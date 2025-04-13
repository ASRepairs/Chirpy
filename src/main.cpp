#include <LilyGoLib.h>
#include <LV_Helper.h>
#include "esp_log.h"
#include "encryption.h"

#define LORA_FREQUENCY        868.0f
#define TASK_STACK_SIZE       4096
#define TX_INTERVAL_MS        3000
#define UI_REFRESH_MS         10
#define RX_CHECK_INTERVAL_MS  50

static const char* TAG = "ChirpyMain";

// global vars
SX1262 radio = newModule();
lv_obj_t* label1 = nullptr;
volatile bool receivedFlag = false;
volatile bool isTransmitting = false;
bool isPmuIRQ = false;
static String currentGroup = "gr1";

// ───────────────────────────── ISR ─────────────────────────────

ICACHE_RAM_ATTR void onLoraPacketReceived() {
    if (!isTransmitting) {
        receivedFlag = true;
    }
}

// ──────────────────────── LoRa Transmission ────────────────────────
esp_err_t sendLoraMessage(String& msg) {
    const uint8_t* plaintext = reinterpret_cast<const uint8_t*>(msg.c_str());
    size_t plainLen = msg.length();
    const unsigned char* chosenKey = getKeyForGroup(currentGroup);
    static uint8_t cipherBuf[1024];  // adjustable maximum
    size_t cipherLen = sizeof(cipherBuf);

    //Encrypt
    if (!encryptAES256(plaintext, plainLen,
                               chosenKey, 32,
                               cipherBuf, cipherLen)) {
        ESP_LOGE(TAG, "[SX1262] Encryption failed. Not sending.");
        return ESP_FAIL;
    }

    //Convert raw cipher to a String TODO: deal with null
    String encrypted;
    encrypted.reserve(cipherLen);
    for (size_t i = 0; i < cipherLen; i++) {
        encrypted += (char)cipherBuf[i];
    }
    isTransmitting = true; // signal that TX is in progress
    radio.standby();

    ESP_LOGI(TAG, "[SX1262] Transmitting encrypted text: %s", encrypted.c_str());
    int state = radio.transmit(encrypted); // Send encrypted text
    isTransmitting = false;

    if (state == RADIOLIB_ERR_NONE) {
        lv_label_set_text_fmt(label1, "TX Success\nDatarate: %.1f bps", radio.getDataRate());
        ESP_LOGI(TAG, "[SX1262] Transmission successful.");
        vTaskDelay(pdMS_TO_TICKS(RX_CHECK_INTERVAL_MS));
        state = radio.startReceive();
        if (state == RADIOLIB_ERR_NONE) {
            ESP_LOGI(TAG, "[SX1262] Listening...");
            vTaskDelay(pdMS_TO_TICKS(1000));
            lv_label_set_text(label1, "Waiting for message...");
            return ESP_OK;
        }

        ESP_LOGE(TAG, "[SX1262] Failed to enter RX mode, code: %d", state);
    } else {
        lv_label_set_text_fmt(label1, "TX Failed\nError: %d", state);
        ESP_LOGE(TAG, "[SX1262] Transmission failed, code: %d", state);
    }

    return ESP_FAIL;
}

// ──────────────────────── LoRa Reception ────────────────────────
void displayReceivedMessage() {
    String receivedMsg;
    int state = radio.readData(receivedMsg);

    if (state == RADIOLIB_ERR_NONE) {
        const uint8_t* cipherData = reinterpret_cast<const uint8_t*>(receivedMsg.c_str());
        size_t cipherLen = receivedMsg.length();
        //decrypt
        const unsigned char* chosenKey = getKeyForGroup(currentGroup);
        static uint8_t plainBuf[1024];
        size_t plainLen = sizeof(plainBuf);
        if (!decryptAES256(cipherData, cipherLen,
                                   chosenKey, 32,
                                   plainBuf, plainLen)) {
            ESP_LOGW(TAG, "[SX1262] Decryption failed - discarding message (possibly wrong group)");
            lv_label_set_text_fmt(label1, "Discarding message\n(decryption failed)");
            return;  // we discard if it fails
        }

        //Convert plaintext to a String (assuming it's ASCII)
        String decrypted;
        decrypted.reserve(plainLen);
        for (size_t i=0; i<plainLen; i++) {
            decrypted += (char)plainBuf[i];
        }

        ESP_LOGI(TAG, "[SX1262] Received raw cipher, len=%d", (int)cipherLen);
        ESP_LOGI(TAG, "[SX1262] Decrypted message (group=%s): %s", currentGroup.c_str(), decrypted.c_str());

        lv_label_set_text_fmt(label1,
            "RX Success\nMessage: %s\nRSSI: %d dBm",
            decrypted.c_str(), radio.getRSSI());
    } else {
        ESP_LOGE(TAG, "[SX1262] Failed to read message, code: %d", state);
        lv_label_set_text_fmt(label1,
            "RX Failed\nError: %d", state);
    }
    vTaskDelay(pdMS_TO_TICKS(5000));
    lv_label_set_text(label1, "Waiting for message...");
    //radio.startReceive();  // go back to RX mode after sending so we can receive the next messages
}

// ───────────────────────────── Tasks ─────────────────────────────
void TaskLoraSender(void* pvParameters) {
    while (true) {
        String msg = "hello xd";
        sendLoraMessage(msg);
        vTaskDelay(pdMS_TO_TICKS(TX_INTERVAL_MS));
    }
}

void TaskLoraReceiver(void* pvParameters) {
    while (true) {
        if (receivedFlag) {
            receivedFlag = false;
            displayReceivedMessage();
        }
        //vTaskDelay(pdMS_TO_TICKS(RX_CHECK_INTERVAL_MS));
    }
}

void TaskLvglUpdate(void* pvParameters) {
    while (true) {
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(UI_REFRESH_MS));
    }
}
void TaskCheckShortButtonPressed(void* pvParameters)
{
    while (true)
    {
        if (isPmuIRQ) {
            isPmuIRQ = false;
            watch.readPMU();
            if (watch.isPekeyShortPressIrq()) {
                ESP_LOGI(TAG, "[SX1262] Pekey short-press");
                String msg = "button pressed";
                sendLoraMessage(msg);
            }
            watch.clearPMU();
        }
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}

// ───────────────────────────── Setup ─────────────────────────────
void setup() {
    Serial.begin(115200);
    esp_log_level_set("*", ESP_LOG_VERBOSE);
    watch.begin();
    beginLvglHelper();
    watch.attachPMU([]() {
    isPmuIRQ = true;
    });
    ESP_LOGI(TAG, "[SX1262] Initializing...");
    int state = radio.begin();
    if (state != RADIOLIB_ERR_NONE) {
        ESP_LOGE(TAG, "Initialization failed, code: %d", state);
        while (true);
    }
    ESP_LOGI(TAG, "[SX1262] Initialization successful");

    if (radio.setFrequency(LORA_FREQUENCY) == RADIOLIB_ERR_INVALID_FREQUENCY) {
        ESP_LOGE(TAG, "[SX1262] Invalid frequency: %.1f MHz", LORA_FREQUENCY);
        while (true);
    }

    radio.setDio1Action(onLoraPacketReceived);

    ESP_LOGI(TAG, "[SX1262] Starting RX mode...");
    state = radio.startReceive(); //default we start receiving
    if (state != RADIOLIB_ERR_NONE) {
        ESP_LOGE(TAG, "Failed to start receive mode, code: %d", state);
        while (true);
    }

    //UI stuff
    label1 = lv_label_create(lv_scr_act());
    lv_label_set_recolor(label1, true);
    lv_label_set_text(label1, "Waiting for message...");
    lv_obj_center(label1);

    //FreeRTOS tasks
    //xTaskCreatePinnedToCore(TaskLoraSender, "TaskLoraSender", TASK_STACK_SIZE, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(TaskLoraReceiver, "TaskLoraReceiver", TASK_STACK_SIZE, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(TaskLvglUpdate, "TaskLvglUpdate", TASK_STACK_SIZE, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(TaskCheckShortButtonPressed, "TaskCheckShortButtonPressed",TASK_STACK_SIZE, NULL, 1, NULL, 0);
}

void loop() {
    lv_point_t point;
    lv_indev_t *indev = lv_indev_get_next(NULL);
    if (indev) {
#if LV_VERSION_CHECK(9,0,0)
        if (lv_indev_get_state(indev) == LV_INDEV_STATE_PRESSED) {
#else
        if (indev->proc.state == LV_INDEV_STATE_PRESSED) {
#endif
            String msg = "screen touched";
            sendLoraMessage(msg);
        }
        }
}
