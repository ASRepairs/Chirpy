#include <LilyGoLib.h> 
#include <LV_Helper.h>
#include "esp_log.h"
#include "common.h" // Added by Kacper (KSCB)
#include <time.h>
#include <deque>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "bleFuncs.h"
#include "structs.h"
#include "ChirpyUI/ui.h"

#define LORA_FREQUENCY        868.0f
#define TASK_STACK_SIZE       4096
#define TX_INTERVAL_MS        3000
#define UI_REFRESH_MS         10
#define RX_CHECK_INTERVAL_MS  50
#define MAX_MSG_HISTORY 10

static const char* TAG = "MAIN";
// global vars
BLEServer *pServer = nullptr;

SX1262 radio = newModule();
lv_obj_t* label1 = nullptr;
volatile bool receivedFlag = false;
volatile bool isTransmitting = false;
String node_id;
std::deque<String> recentMessages;

struct userData globalUserData = {0, 0};

GPSData currentGPSData;

bool isPmuIRQ = false;
// ───────────────────────────── ISR ─────────────────────────────

ICACHE_RAM_ATTR void onLoraPacketReceived() {
    if (!isTransmitting) {
        receivedFlag = true;
    }
}

// ──────────────────────── LoRa Transmission ────────────────────────
esp_err_t sendLoraMessage(String& msg) {
    isTransmitting = true; // signal flag that TX is in progress
    radio.standby();

    ESP_LOGI(TAG, "[SX1262] Transmitting: %s", msg.c_str());
    int state = radio.transmit(msg);
    isTransmitting = false;

    if (state == RADIOLIB_ERR_NONE) {
        //replace with some nice gui to show successful send
        //lv_label_set_text_fmt(label1, "TX Success\nDatarate: %.1f bps", radio.getDataRate());
        ESP_LOGI(TAG, "[SX1262] Transmission successful.");
        vTaskDelay(pdMS_TO_TICKS(RX_CHECK_INTERVAL_MS));
        state = radio.startReceive();
        if (state == RADIOLIB_ERR_NONE) {
            ESP_LOGI(TAG, "[SX1262] Listening...");
            vTaskDelay(pdMS_TO_TICKS(1000));
            //lv_label_set_text(label1, "Waiting for message...");
            return ESP_OK;
        }

        ESP_LOGE(TAG, "[SX1262] Failed to enter RX mode, code: %d", state);
    } else {
        //replace with some nice gui to show failed send
        //lv_label_set_text_fmt(label1, "TX Failed\nError: %d", state);
        ESP_LOGE(TAG, "[SX1262] Transmission failed, code: %d", state);
    }

    return ESP_FAIL;
}

// ──────────────────────── LoRa Reception ────────────────────────
void displayReceivedMessage() {
    String receivedMsg;
    int state = radio.readData(receivedMsg);

    if (state == RADIOLIB_ERR_NONE) {
        ESP_LOGI(TAG, "[SX1262] Received message: %s", receivedMsg.c_str());
        int first_colon = receivedMsg.indexOf(':');
        int second_colon = receivedMsg.indexOf(':', first_colon + 1);
        int third_colon = receivedMsg.indexOf(':', second_colon + 1);
        int forth_colon = receivedMsg.indexOf(':', third_colon + 1);

        if (first_colon == -1 || second_colon == -1 || forth_colon == -1 || forth_colon <= second_colon)
        {
            ESP_LOGW(TAG, "[SX1262] Invalid message format");
            return;
        }

        String sender = receivedMsg.substring(0, first_colon);
        String msg_id = receivedMsg.substring(first_colon + 1, second_colon);
        String group_str = receivedMsg.substring(second_colon + 1, third_colon);
        String usr_str = receivedMsg.substring(third_colon + 1, forth_colon);
        String payload_str = receivedMsg.substring(forth_colon + 1);

        // skip if we were the sender
        if (sender == node_id)
        {
            ESP_LOGI(TAG, "[SX1262] Skipping own message ID: %s", msg_id.c_str());
            return;
        }

        // skip if we already processed this message before
        if (std::find(recentMessages.begin(), recentMessages.end(), msg_id) != recentMessages.end())
        {
            ESP_LOGI(TAG, "[SX1262] Already forwarded message ID: %s", msg_id.c_str());
            return;
        }

        // keep track of messages to prevent infinite mesh loop
        recentMessages.push_back(msg_id);
        if (recentMessages.size() > MAX_MSG_HISTORY) recentMessages.pop_front();

        // processing of the message happens here
        int gr_id = atoi(group_str.c_str());
        int usr_id = atoi(usr_str.c_str());
        int msg_payload = atoi(payload_str.c_str());

        if ((gr_id == globalUserData.groupId) || (gr_id == 0) || (globalUserData.groupId == 0)) {
            ESP_LOGI(TAG, "[SX1262] Displaying message for group %d", gr_id);
            watch.setWaveform(0, 15);  // play effect
            watch.setWaveform(1, 0);  // end waveform
            watch.setWaveform(3, 15);  // play effect
            watch.setWaveform(4, 0);  // end waveform
            watch.run();
        }

        // rebroadcast
        ESP_LOGI(TAG, "[SX1262] Rebroadcasting message: %s", receivedMsg.c_str());
        sendLoraMessage(receivedMsg);
    }
    else
    {
        ESP_LOGE(TAG, "[SX1262] Failed to read message, code: %d", state);
    }
    vTaskDelay(pdMS_TO_TICKS(1000));
}

// ───────────────────────────── Tasks ─────────────────────────────
void TaskLoraSender(void* pvParameters) {
    while (true) {
        String msg = "Task: periodic send";
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
        vTaskDelay(pdMS_TO_TICKS(RX_CHECK_INTERVAL_MS));
    }
}

void TaskLvglUpdate(void* pvParameters) {
    while (true) {
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(UI_REFRESH_MS));
    }
}

void TaskCheckShortButtonPressed(void* pvParameters){
    while (true)
    {
        if (isPmuIRQ) {
            isPmuIRQ = false;
            watch.readPMU();
            if (watch.isPekeyShortPressIrq()) {
                ESP_LOGI(TAG, "[watch] Pekey short-press");
                //String msg = "button pressed";
                //sendLoraMessage(msg);
                // Pekey button as "lock screen"
                
                watch.setWaveform(0, 1);  // play effect
                watch.setWaveform(1, 0);  // end waveform
                watch.run();
                ESP_LOGI(TAG, "[FFat] freeBytes: %d", FFat.freeBytes());

            }
            watch.clearPMU();
        }
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}


// ─────────── Common functions definition (common.h) ──────────────

esp_err_t common_sendLoraMessage(const char *msg){ // message structure is: "<node_id>:<msg_uid>:<group_id>:<user_id (emoji)>:<payload "msg_id">"
    String msg_str;
    String msg_uid = String(millis()); // could also use timestamp

    msg_str = node_id + ":" + msg_uid + ":" + String(globalUserData.groupId) + ":" + String(globalUserData.userId) + ":" + String(msg);

    ESP_LOGI(TAG, "Sending msg: %s", msg_str.c_str());
    return sendLoraMessage(msg_str);
}

esp_err_t common_sendLoraEmoji(int msg)
{ // message structure is: "<node_id>:<msg_uid>:<group_id>:<user_id (emoji)>:<payload "msg_id">"
    String msg_str;
    String msg_uid = String(millis()); // could also use timestamp
    if (msg == ALERT)
    {
        msg_str = node_id + ":" + msg_uid + ":0:" + String(globalUserData.userId) + ":" + String(msg);
    }
    else
    {
        msg_str = node_id + ":" + msg_uid + ":" + String(globalUserData.groupId) + ":" + String(globalUserData.userId) + ":" + String(msg);
    }
    ESP_LOGI(TAG, "Sending msg: %s", msg_str.c_str());
    return sendLoraMessage(msg_str);
}




// ───────────────────────────── Setup ─────────────────────────────
void setup() {
    Serial.begin(115200);
    Serial.setDebugOutput(true); 
    esp_log_level_set("*", ESP_LOG_VERBOSE);
    watch.begin();
    beginLvglHelper();
    watch.attachPMU([]() {
        isPmuIRQ = true;
    });
    uint64_t chip_id = ESP.getEfuseMac();
    char chip_id_str[13];
    sprintf(chip_id_str, "%012llX", chip_id); // or "%012llx" for lowercase
    node_id = String(chip_id_str);
    ESP_LOGI(TAG, "[Node ID] %s", node_id.c_str()); // 80E58A63B0E4
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

    startBLETask(node_id, &currentGPSData);    // Initialize BLE

    ui_init(); //LVGL UI

    //FreeRTOS tasks
    //xTaskCreatePinnedToCore(TaskLoraSender, "TaskLoraSender", TASK_STACK_SIZE, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(TaskLoraReceiver, "TaskLoraReceiver", TASK_STACK_SIZE, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(TaskLvglUpdate, "TaskLvglUpdate", TASK_STACK_SIZE, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(TaskCheckShortButtonPressed, "TaskCheckShortButtonPressed",TASK_STACK_SIZE, NULL, 1, NULL, 0);
    //xTaskCreatePinnedToCore(TaskShowRecievedFrame, "TaskShowRecievedFrame",TASK_STACK_SIZE, NULL, 1, NULL, 0);
}

void loop() {
    
}
