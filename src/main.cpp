#include <LilyGoLib.h> 
#include <LV_Helper.h>
#include "esp_log.h"
#include "UI/custom/custom.h"
#include "UI/generated/gui_guider.h"
#include "common.h" // Added by Kacper (KSCB)
#include <time.h>
#include <TinyGPSPlus.h>
#include <deque>

#define LORA_FREQUENCY        868.0f
#define TASK_STACK_SIZE       4096
#define TX_INTERVAL_MS        3000
#define UI_REFRESH_MS         10
#define RX_CHECK_INTERVAL_MS  50
#define MAX_MSG_HISTORY 10

static const char* TAG = "MAIN";
// global vars
SX1262 radio = newModule();
lv_obj_t* label1 = nullptr;
TinyGPSPlus gps;
const char *TIMEZONE = "CET-1CEST,M3.5.0/02:00:00,M10.5.0/03:00:00"; // central Europe with daylight saving time
volatile bool timeSynced = false;
volatile bool receivedFlag = false;
volatile bool isTransmitting = false;
String node_id;
std::deque<String> recentMessages;
struct GPSData
{
    float latitude;
    float longitude;
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    bool valid;
};

volatile GPSData currentGPSData;

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
        int semicolon = receivedMsg.indexOf(';');

        if (first_colon == -1 || second_colon == -1 || semicolon == -1 || semicolon <= second_colon)
        {
            ESP_LOGW(TAG, "[SX1262] Invalid message format");
            return;
        }

        String sender = receivedMsg.substring(0, first_colon);
        String msg_id = receivedMsg.substring(first_colon + 1, second_colon);
        String group_str = receivedMsg.substring(second_colon + 1, semicolon);
        String payload_str = receivedMsg.substring(semicolon + 1);

        // skip if we were the sender
        if (sender == node_id)
        {
            ESP_LOGI(TAG, "[SX1262] Skipping own message: %s", msg_id.c_str());
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
        int msg_payload = atoi(payload_str.c_str());

        if ((gr_id == common_current_group) || (gr_id == 0) || (common_current_group == 0)) {
            ESP_LOGI(TAG, "[SX1262] Displaying message for group %d", gr_id);
            common_displayMessageUI(msg_payload);
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
                
                ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.message_received_heart_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
                //ui_load_scr_animation(&guider_ui, &guider_ui.message_received_heart, guider_ui.message_received_heart_del, &guider_ui.message_received_heart_del, setup_scr_message_received_heart, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
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

void TaskUpdateGPSLocationAndTime(void *pvParameters) //TODO: might wanna separate this into two tasks, one for location and one for time so it saves battery..
{
    ESP_LOGI(TAG, "[GPS] Waiting for a valid GPS signal...");

    while (true)
    {
        // read everything from GPS UART
        while (GPSSerial.available())
        {
            char c = GPSSerial.read();
            gps.encode(c);
        }

        time_t current_time;
        struct tm tm_utc;

        // Get existing system time to preserve unmodified parts
        gettimeofday((struct timeval *)&current_time, NULL);
        localtime_r(&current_time, &tm_utc);

        bool timeUpdated = false;

        // Location
        if (gps.location.isValid())
        {
            currentGPSData.latitude = gps.location.lat();
            currentGPSData.longitude = gps.location.lng();
            currentGPSData.valid = true;

            ESP_LOGI(TAG, "[GPS] Location updated: Lat=%.6f, Lon=%.6f",
                     currentGPSData.latitude, currentGPSData.longitude);
        }

        // Update date if available
        if (gps.date.isValid())
        {
            currentGPSData.year = gps.date.year();
            currentGPSData.month = gps.date.month();
            currentGPSData.day = gps.date.day();

            tm_utc.tm_year = currentGPSData.year - 1900;
            tm_utc.tm_mon = currentGPSData.month - 1;
            tm_utc.tm_mday = currentGPSData.day;

            timeUpdated = true;

            ESP_LOGI(TAG, "[GPS] Date updated: %04d-%02d-%02d",
                     currentGPSData.year, currentGPSData.month, currentGPSData.day);
        }

        // Update time if available
        if (gps.time.isValid())
        {
            currentGPSData.hour = gps.time.hour();
            currentGPSData.minute = gps.time.minute();
            currentGPSData.second = gps.time.second();

            tm_utc.tm_hour = currentGPSData.hour;
            tm_utc.tm_min = currentGPSData.minute;
            tm_utc.tm_sec = currentGPSData.second;

            timeUpdated = true;

            ESP_LOGI(TAG, "[GPS] Time updated: %02d:%02d:%02d",
                     currentGPSData.hour, currentGPSData.minute, currentGPSData.second);
        }

        // Set RTC if either date or time was updated
        if (timeUpdated)
        {
            time_t updated_time = mktime(&tm_utc);
            if (updated_time != (time_t)-1)
            {
                struct timeval now = {.tv_sec = updated_time, .tv_usec = 0};
                settimeofday(&now, nullptr);
                watch.hwClockWrite();

                ESP_LOGI(TAG, "[GPS] System and RTC updated to: %04d-%02d-%02d %02d:%02d:%02d",
                         tm_utc.tm_year + 1900,
                         tm_utc.tm_mon + 1,
                         tm_utc.tm_mday,
                         tm_utc.tm_hour,
                         tm_utc.tm_min,
                         tm_utc.tm_sec);
            }
            else
            {
                ESP_LOGW(TAG, "[GPS] mktime() failed; RTC not updated.");
            }
        }

        vTaskDelay(pdMS_TO_TICKS(1000)); // Run every second
    }
}

// ─────────── Common functions definition (common.h) ──────────────

// TODO: Make it nicer
void common_change_group(int gr_id){
    ESP_LOGI(TAG, "Group id changed from %d to %d", common_current_group, gr_id);
    if(common_current_group != 0){
        switch (common_current_group)
        {
        case 1:
            lv_obj_set_style_text_color(guider_ui.groups_list_label_group_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
            break;
        case 2:
            lv_obj_set_style_text_color(guider_ui.groups_list_label_group_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
            break;
        case 3:
            lv_obj_set_style_text_color(guider_ui.groups_list_label_group_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
            break;
        case 4:
            lv_obj_set_style_text_color(guider_ui.groups_list_label_group_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
            break;
        case 5:
            lv_obj_set_style_text_color(guider_ui.groups_list_label_group_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
            break;
        case 6:
            lv_obj_set_style_text_color(guider_ui.groups_list_label_group_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
            break;
        case 7:
            lv_obj_set_style_text_color(guider_ui.groups_list_label_group_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
            break;
        case 8:
            lv_obj_set_style_text_color(guider_ui.groups_list_label_group_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
            break;
        case 9:
            lv_obj_set_style_text_color(guider_ui.groups_list_label_group_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
            break;
        case 10:
            lv_obj_set_style_text_color(guider_ui.groups_list_label_group_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
            break;
        default:
            break;
        }
    }
    switch (gr_id)
    {
    case 1:
        lv_obj_set_style_text_color(guider_ui.groups_list_label_group_1, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
        break;
    case 2:
        lv_obj_set_style_text_color(guider_ui.groups_list_label_group_2, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
        break;
    case 3:
        lv_obj_set_style_text_color(guider_ui.groups_list_label_group_3, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
        break;
    case 4:
        lv_obj_set_style_text_color(guider_ui.groups_list_label_group_4, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
        break;
    case 5:
        lv_obj_set_style_text_color(guider_ui.groups_list_label_group_5, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
        break;
    case 6:
        lv_obj_set_style_text_color(guider_ui.groups_list_label_group_6, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
        break;
    case 7:
        lv_obj_set_style_text_color(guider_ui.groups_list_label_group_7, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
        break;
    case 8:
        lv_obj_set_style_text_color(guider_ui.groups_list_label_group_8, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
        break;
    case 9:
        lv_obj_set_style_text_color(guider_ui.groups_list_label_group_9, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
        break;
    case 10:
        lv_obj_set_style_text_color(guider_ui.groups_list_label_group_10, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
        break;
    default:
        break;
    }
    
    common_current_group = gr_id;
}

int common_sendMessage(int msg_id) { // message structure is: "<node_id>:<msg_uid>:<group_id>;<payload "msg_id">"
    String msg_str;
    String msg_uid = String(millis()); // could also use timestamp
    if(msg_id == 0) {
        msg_str = node_id + ":" + msg_uid + ":0;" + String(msg_id);
    }
    else
    {
        msg_str = node_id + ":" + msg_uid + ":" + String(common_current_group) + ";" + String(msg_id);
    }
    ESP_LOGI(TAG, "Sending msg: %s", msg_str.c_str());
    int status = sendLoraMessage(msg_str);
    return status;
}

// TODO: Make it nicer
void common_displayMessageUI(int msg_id) {
    switch (msg_id)
    {
    case ALERT:
        ui_load_scr_animation(&guider_ui, &guider_ui.alert_received, guider_ui.alert_received_del, &guider_ui.alert_received_del, setup_scr_alert_received, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
        break;
    case THUMB_UP:
        ui_load_scr_animation(&guider_ui, &guider_ui.message_received_like, guider_ui.message_received_like_del, &guider_ui.message_received_like_del, setup_scr_message_received_like, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
        break;
    case WAVE:
        ui_load_scr_animation(&guider_ui, &guider_ui.message_received_wave, guider_ui.message_received_wave_del, &guider_ui.message_received_wave_del, setup_scr_message_received_wave, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
        break;
    case HEART:
        ui_load_scr_animation(&guider_ui, &guider_ui.message_received_heart, guider_ui.message_received_heart_del, &guider_ui.message_received_heart_del, setup_scr_message_received_heart, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
        break;
    case PARTY:
        ui_load_scr_animation(&guider_ui, &guider_ui.message_received_party, guider_ui.message_received_party_del, &guider_ui.message_received_party_del, setup_scr_message_received_party, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
        break;
    default:
        ESP_LOGI(TAG, "msg_id: %d", msg_id);
        break;
    }
    return;
}


// ───────────────────────────── Setup ─────────────────────────────
void setup() {
    common_current_group = 0; // todo: move that variable to flash memory
    Serial.begin(115200);
    esp_log_level_set("*", ESP_LOG_VERBOSE);
    setenv("TZ", TIMEZONE, 1);
    tzset();
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

    //UI stuff replace with actual ui stuff
    setup_ui(&guider_ui); // Initialize the UI
    custom_init(&guider_ui);
    //FreeRTOS tasks
    //xTaskCreatePinnedToCore(TaskLoraSender, "TaskLoraSender", TASK_STACK_SIZE, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(TaskLoraReceiver, "TaskLoraReceiver", TASK_STACK_SIZE, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(TaskLvglUpdate, "TaskLvglUpdate", TASK_STACK_SIZE, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(TaskCheckShortButtonPressed, "TaskCheckShortButtonPressed",TASK_STACK_SIZE, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(TaskUpdateGPSLocationAndTime, "TaskUpdateGPSLocationAndTime", TASK_STACK_SIZE / 2, NULL, 3, NULL, 1);
    //xTaskCreatePinnedToCore(TaskShowRecievedFrame, "TaskShowRecievedFrame",TASK_STACK_SIZE, NULL, 1, NULL, 0);
}

void loop() {
    
}
