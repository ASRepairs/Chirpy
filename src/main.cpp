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
static char chirpyName[32];
std::deque<String> recentMessages;

struct userData globalUserData = {1, 0}; //start with first group and froggy

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

// ─────────────────────── Time/Date ────────────────────────
static void _ui_set_time_label(void *p)
{
    /* p points to a NUL-terminated "HH:MM" string that lives in task scope */
    lv_label_set_text(ui_Time, (const char *)p);
}


void TaskTimeUpdater(void *pvParameters)
{
    static char buf[6]; /* “HH:MM” — must persist between calls     */
    struct tm tm_now;   /* POSIX time structure                      */

    for (;;)
    {
        /* 1. read Unix time from the hardware RTC */
        time_t t = watch.hwClockRead(); /* LilyGO helper updates ‘time’ */
        localtime_r(&t, &tm_now); /* convert to broken-down time  */

        /* 2. format hour and minute */
        snprintf(buf, sizeof(buf), "%02d:%02d", tm_now.tm_hour, tm_now.tm_min);

        /* 3. queue the label update in LVGL’s own context (thread-safe) */
        lv_async_call(_ui_set_time_label, buf);

        /* 4. repeat every second (change to 60000 ms if only minute precision wanted) */
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

static void _ui_set_date_label(void *p)
{
    lv_label_set_text(ui_Date, (const char *)p);
}

void TaskDateUpdater(void *pvParameters)
{
    static char date_buf[16]; // "Wed, 21/01" + null terminator
    struct tm tm_now;

    for (;;)
    {
        time_t t = watch.hwClockRead();
        localtime_r(&t, &tm_now);

        // Format: "Wed, 21/01"
        strftime(date_buf, sizeof(date_buf), "%a, %d/%m", &tm_now);

        lv_async_call(_ui_set_date_label, date_buf);

        vTaskDelay(pdMS_TO_TICKS(60000)); // update every 60 seconds
    }
}

// ──────────────────────── Notification Handling ────────────────────────
void handleReceivedNotification(int user_id, int msg_type, const char *payload_str)
{
    ESP_LOGI(TAG, "UI Received notification from user %d: %s", user_id, payload_str);
    lv_obj_set_y(ui_NotificationContainer, 0); // Force Y to top

    // Set sender image
    switch (user_id)
    {
    case FROGGY:
        lv_img_set_src(ui_SenderAvatarInNotificationImage, &ui_img_froggy_png);
        break;
    case PIGGY:
        lv_img_set_src(ui_SenderAvatarInNotificationImage, &ui_img_piggy_png);
        break;
    case HORSY:
        lv_img_set_src(ui_SenderAvatarInNotificationImage, &ui_img_horsy_png);
        break;
    case PANDY:
        lv_img_set_src(ui_SenderAvatarInNotificationImage, &ui_img_pandy_png);
        break;
    default:
        lv_img_set_src(ui_SenderAvatarInNotificationImage, &ui_img_froggy_png); // default to Froggy
        break;
    }
    bool auto_dismiss = true;
    // Interpret the payload
    if (msg_type == MSG_TYPE_EMOJI)
    {
        int emoji_code = atoi(payload_str);
        ESP_LOGI(TAG, "Parsed emoji code: %d", emoji_code);
        lv_obj_add_flag(ui_ReceivedMessageLabel, LV_OBJ_FLAG_HIDDEN); // hide text label
        lv_obj_clear_flag(ui_ReceivedEmojiImage, LV_OBJ_FLAG_HIDDEN); // show emoji image

        switch (emoji_code)
        {
        case THUMB_UP:
            lv_img_set_src(ui_ReceivedEmojiImage, &ui_img_likeemoji_png);
            break;
        case WAVE:
            lv_img_set_src(ui_ReceivedEmojiImage, &ui_img_waveemoji_png);
            break;
        case HEART:
            lv_img_set_src(ui_ReceivedEmojiImage, &ui_img_heartemoji_png);
            break;
        case PARTY:
            lv_img_set_src(ui_ReceivedEmojiImage, &ui_img_celebrationemoji_png);
            break;
        default:
            lv_img_set_src(ui_ReceivedEmojiImage, &ui_img_likeemoji_png);
            ESP_LOGW(TAG, "Unknown emoji code: %d", emoji_code);
            break;
        }
    }
    else if (msg_type == MSG_TYPE_ALERT)
    {
        float lat = 0, lon = 0;
        if (sscanf(payload_str, "%f,%f", &lat, &lon) == 2 && lat != 0 && lon != 0)
        {
            bleSendNotificationWithGps(MSG_TYPE_ALERT, user_id, lat, lon); // Send alert to phone
            lv_obj_add_flag(ui_ReceivedMessageLabel, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_ReceivedEmojiImage, LV_OBJ_FLAG_HIDDEN);
            lv_img_set_src(ui_ReceivedEmojiImage, &ui_img_emergencyemoji_png);
            auto_dismiss = false;
        }
        else if (lat == 0 || lon == 0)
        {
            // If lat/lon are zero, treat as a generic alert without GPS
            lv_obj_add_flag(ui_ReceivedMessageLabel, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_ReceivedEmojiImage, LV_OBJ_FLAG_HIDDEN);
            lv_img_set_src(ui_ReceivedEmojiImage, &ui_img_emergencyemoji_png);
            auto_dismiss = false;
        }
        else
        {
            ESP_LOGW(TAG, "Bad ALERT payload: %s", payload_str);
        }
    }

    else if (msg_type == MSG_TYPE_TEXT)
    {
        lv_obj_add_flag(ui_ReceivedEmojiImage, LV_OBJ_FLAG_HIDDEN);     // hide emoji image
        lv_obj_clear_flag(ui_ReceivedMessageLabel, LV_OBJ_FLAG_HIDDEN); // show text label
        // Treat as plain text message
        lv_label_set_text(ui_ReceivedMessageLabel, payload_str);
    }
    else if (msg_type == MSG_TYPE_GPS)
    {
        float lat = 0, lon = 0;
        if (sscanf(payload_str, "%f,%f", &lat, &lon) == 2) {
            bleSendNotificationWithGps(MSG_TYPE_GPS, user_id, lat, lon);
            lv_obj_add_flag(ui_ReceivedEmojiImage, LV_OBJ_FLAG_HIDDEN);     // hide emoji image
            lv_obj_clear_flag(ui_ReceivedMessageLabel, LV_OBJ_FLAG_HIDDEN); // show text label
            // GPS as a message
            char buf[64];
            snprintf(buf, sizeof(buf), "Received GPS: (%.6f, %.6f)", lat, lon);
            lv_label_set_text(ui_ReceivedMessageLabel, buf);
        } else ESP_LOGW(TAG, "Bad GPS payload: %s", payload_str);
    }

    // show the notification overlay
    lv_obj_clear_flag(ui_NotificationContainer, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_parent(ui_NotificationContainer, lv_layer_top());

    // Auto-hide after 5 seconds
    static lv_timer_t *hide_timer = nullptr;
    if (hide_timer)
        lv_timer_del(hide_timer);

    if (auto_dismiss)
    {
        hide_timer = lv_timer_create([](lv_timer_t *t)
                                     {
                DismissNotificationAnimation_Animation(ui_NotificationContainer, 0);
                lv_timer_create([](lv_timer_t *t)
                                {
                    lv_obj_add_flag(ui_NotificationContainer, LV_OBJ_FLAG_HIDDEN);
                    lv_timer_del(t);
                }, 500, NULL);
            }, 5000, nullptr);
    }
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
        int fourth_colon = receivedMsg.indexOf(':', third_colon + 1);
        int fifth_colon = receivedMsg.indexOf(':', fourth_colon + 1);

        if (fifth_colon == -1)
        {
            ESP_LOGW(TAG, "Invalid message format – type missing");
            return;
        }

        String sender = receivedMsg.substring(0, first_colon);
        String msg_id = receivedMsg.substring(first_colon + 1, second_colon);
        String group_str = receivedMsg.substring(second_colon + 1, third_colon);
        String usr_str = receivedMsg.substring(third_colon + 1, fourth_colon);
        String type_str = receivedMsg.substring(fourth_colon + 1, fifth_colon);
        String payload_str = receivedMsg.substring(fifth_colon + 1);
        int msg_type = atoi(type_str.c_str());

        // skip if we were the sender
        if (sender == String(chirpyName))
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

        if ((gr_id == globalUserData.groupId) || (gr_id == 0) || (globalUserData.groupId == 0)) {
            ESP_LOGI(TAG, "[SX1262] Displaying message for group %d", gr_id);
            handleReceivedNotification(usr_id, msg_type, payload_str.c_str());
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

void TaskCheckShortButtonPressed(void *pvParameters)
{
    while (true)
    {
        if (isPmuIRQ)
        {
            isPmuIRQ = false;
            watch.readPMU();

            // Long press = turn off display
            if (watch.isPekeyLongPressIrq())
            {
                if (watch.getBrightness() > 0)
                {
                    watch.setBrightness(0); // this will also sleep the lcd
                    watch.powerIoctl(WATCH_POWER_TOUCH_DISP, false);
                    ESP_LOGI(TAG, "[watch] Display turned OFF (long press)");
                }
            }

            // Short press = wake screen or go to home
            else if (watch.isPekeyShortPressIrq())
            {
                ESP_LOGI(TAG, "[watch] Pekey short-press");

                if (watch.getBrightness() == 0)
                {
                    // lcd is off, turn it on
                    watch.powerIoctl(WATCH_POWER_TOUCH_DISP, true);
                    vTaskDelay(pdMS_TO_TICKS(50)); // wait for power to stabilize
                    watch.setBrightness(50); // or restore previous brightness
                    ESP_LOGI(TAG, "[watch] Display turned ON");
                }
                else
                {
                    // Display is on, switch to home screen if not already there
                    if (lv_scr_act() != ui_MainScreen)
                    {
                        lv_scr_load_anim(ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_IN, 300, 0, false);
                        ESP_LOGI(TAG, "[watch] Switched to Home Screen");
                    }
                }

                //vibrator feedback
                watch.setWaveform(0, 1);
                watch.setWaveform(1, 0);
                watch.run();
            }
            watch.clearPMU();
        }
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}

// ─────────── Common functions definition (common.h) ──────────────

esp_err_t common_sendLoraMessage(const char *msg) // message structure is: "<node_id>:<msg_uid>:<group_id>:<user_id>:<type>:<payload>"
{ 
        String msg_str;
    String msg_uid = String(millis()); // could also use timestamp

    msg_str = String(chirpyName) + ":" + msg_uid + ":" + String(globalUserData.groupId) +
              ":" + String(globalUserData.userId) + ":" + String(MSG_TYPE_TEXT) + ":" + String(msg);

    ESP_LOGI(TAG, "Sending msg: %s", msg_str.c_str());
    return sendLoraMessage(msg_str);
}

esp_err_t common_sendLoraEmoji(int emoji_code)
{ // message structure is: "<node_id>:<msg_uid>:<group_id>:<user_id>:<type>:<payload>"
    String msg_str;
    String msg_uid = String(millis());
    int type = MSG_TYPE_EMOJI;

    msg_str = String(chirpyName) + ":" + msg_uid + ":" +
              String(globalUserData.groupId) + ":" +
              String(globalUserData.userId) + ":" + String(type) + ":" + String(emoji_code);

    ESP_LOGI(TAG, "Sending emoji msg: %s", msg_str.c_str());
    return sendLoraMessage(msg_str);
}

esp_err_t common_sendLoraAlert(void)
{
    // ALERT is always broadcast to all groups (groupId = 0)
    String msg_str;
    String msg_uid = String(millis());
    int type = MSG_TYPE_ALERT;
    String payload = String(currentGPSData.latitude, 6) + "," + String(currentGPSData.longitude, 6);

    msg_str = String(chirpyName) + ":" + msg_uid + ":" +
              "0:" + // broadcast to all groups
              String(globalUserData.userId) + ":" + String(type) + ":" + payload;

    ESP_LOGI(TAG, "Sending alert msg: %s", msg_str.c_str());
    return sendLoraMessage(msg_str);
}

esp_err_t common_sendLoraGPS(void)
{
    // Check if GPS data is valid (not 0,0)
    if (currentGPSData.latitude == 0.0f && currentGPSData.longitude == 0.0f) {
        ESP_LOGW(TAG, "GPS data is unavailable or invalid (0,0). Not sending.");
        return ESP_FAIL;
    }

    String msg_str;
    String msg_uid = String(millis());
    int type = MSG_TYPE_GPS;

    // gps payload should be "lat,lon"
    String payload = String(currentGPSData.latitude, 6) + "," + String(currentGPSData.longitude, 6);

    msg_str = String(chirpyName) + ":" + msg_uid + ":" +
              String(globalUserData.groupId) + ":" +
              String(globalUserData.userId) + ":" +
              String(type) + ":" + payload;

    ESP_LOGI(TAG, "Sending GPS msg: %s", msg_str.c_str());
    return sendLoraMessage(msg_str);
}

void common_setBrightness(uint8_t level)
{
    if (level > 0 && level <= 255) {
        watch.setBrightness(level);
    } else {
        ESP_LOGE(TAG, "[watch] Invalid brightness level: %d. Must be between 1 and 255.", level);
    }
}


// ───────────────────────────── Setup ─────────────────────────────
void setup() {

    Serial.begin(115200);
    //Serial.setDebugOutput(true); 
    //esp_log_level_set("*", ESP_LOG_INFO);

    watch.begin();
    beginLvglHelper();
    watch.attachPMU([]() {
        isPmuIRQ = true;
    });
    uint64_t chip_id = ESP.getEfuseMac();
    char chip_id_str[13];

    sprintf(chip_id_str, "%012llX", chip_id); // or "%012llx" for lowercase
    snprintf(chirpyName, sizeof(chirpyName), "Chirpy_%s", chip_id_str);
    ESP_LOGI(TAG, "[Node ID] %s", chirpyName); // 80E58A63B0E4


    // Initialize LoRa radio
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

    // Initialize BLE
    startBLETask(chirpyName, &currentGPSData);

    ui_init(); //LVGL UI

    // QR Code generation
    // Create QR Code object and attach to QR container
    lv_obj_t *qr = lv_qrcode_create(ui_QRContainer, 150, lv_color_black(), lv_color_hex(0xffa300)); // that color ;)
    lv_obj_center(qr); // center inside parent
    lv_obj_set_style_border_width(qr, 2, 0);
    lv_obj_set_style_border_color(qr, lv_color_hex(0xffa300), 0);
    lv_obj_set_style_border_opa(qr, LV_OPA_COVER, 0);
    lv_obj_set_style_radius(qr, 0, 0);

    // Set QR code data (Chirpy_<MAC>)
    lv_qrcode_update(qr, chirpyName, strlen(chirpyName));


    //FreeRTOS tasks
    //xTaskCreatePinnedToCore(TaskLoraSender, "TaskLoraSender", TASK_STACK_SIZE, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(TaskLoraReceiver, "TaskLoraReceiver", TASK_STACK_SIZE, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(TaskLvglUpdate, "TaskLvglUpdate", TASK_STACK_SIZE, NULL, 100, NULL, 0);
    xTaskCreatePinnedToCore(TaskCheckShortButtonPressed, "TaskCheckShortButtonPressed",TASK_STACK_SIZE, NULL, 1, NULL, 1);
    //xTaskCreatePinnedToCore(TaskShowRecievedFrame, "TaskShowRecievedFrame",TASK_STACK_SIZE, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(TaskTimeUpdater,"TaskTimeUpdater", TASK_STACK_SIZE, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(TaskDateUpdater, "TaskDateUpdater", TASK_STACK_SIZE, NULL, 1, NULL, 1);
}

void loop() {
    
}
