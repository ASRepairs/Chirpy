#include <LilyGoLib.h> 
#include <LV_Helper.h>
#include "esp_log.h"
#include "UI/custom/custom.h"
#include "UI/generated/gui_guider.h"
#include "common.h" // Added by Kacper (KSCB)

#define LORA_FREQUENCY        868.0f
#define TASK_STACK_SIZE       4096
#define TX_INTERVAL_MS        3000
#define UI_REFRESH_MS         10
#define RX_CHECK_INTERVAL_MS  50

static const char* TAG = "MAIN";
// global vars
SX1262 radio = newModule();
lv_obj_t* label1 = nullptr;
volatile bool receivedFlag = false;
volatile bool isTransmitting = false;
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
        int index_1_delim = receivedMsg.indexOf(';');
        String group_str = receivedMsg.substring(0, index_1_delim);
        ESP_LOGI(TAG, "[SX1262] Group ID: %s", group_str.c_str());
        int gr_id = atoi(group_str.c_str());
        if((gr_id == common_current_group) || (gr_id == 0) || (common_current_group == 0)) {
            String msg_str = receivedMsg.substring(index_1_delim+1);
            ESP_LOGI(TAG, "[SX1262] Message STR: %s", msg_str.c_str());
            int msg_id = atoi(msg_str.c_str());
            common_displayMessageUI(msg_id);
            watch.setWaveform(0, 15);  // play effect
            watch.setWaveform(1, 0);  // end waveform
            watch.setWaveform(3, 15);  // play effect
            watch.setWaveform(4, 0);  // end waveform
            watch.run();
        }
        //replace with some nice gui to show the message/emoji
        // lv_label_set_text_fmt(label1, "RX Success\nMessage: %s\nRSSI: %d dBm", receivedMsg.c_str(), radio.getRSSI());
        
    } else {
        ESP_LOGE(TAG, "[SX1262] Failed to read message, code: %d", state);
        //lv_label_set_text_fmt(label1, "RX Failed\nError: %d", state);
    }
    vTaskDelay(pdMS_TO_TICKS(1000));
    //after accepting, return to normal gui or something
    //lv_label_set_text(label1, "Waiting for message...");
    //radio.startReceive();  // go back to RX mode after sending so we can receive the next messages
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

int common_sendMessage(int msg_id) {
    String msg_str;
    if(msg_id == 0) {
        msg_str = "0;" + String(msg_id);
    } else {
        msg_str = String(common_current_group) + ";" + String(msg_id);
    }
    ESP_LOGI(TAG, "gr_id: %d msg_id: %d, msg_str: %s", common_current_group, msg_id, msg_str);
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

    //UI stuff replace with actual ui stuff
    setup_ui(&guider_ui); // Initialize the UI
    custom_init(&guider_ui);
    //FreeRTOS tasks
    //xTaskCreatePinnedToCore(TaskLoraSender, "TaskLoraSender", TASK_STACK_SIZE, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(TaskLoraReceiver, "TaskLoraReceiver", TASK_STACK_SIZE, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(TaskLvglUpdate, "TaskLvglUpdate", TASK_STACK_SIZE, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(TaskCheckShortButtonPressed, "TaskCheckShortButtonPressed",TASK_STACK_SIZE, NULL, 1, NULL, 0);
    //xTaskCreatePinnedToCore(TaskShowRecievedFrame, "TaskShowRecievedFrame",TASK_STACK_SIZE, NULL, 1, NULL, 0);
}

void loop() {
    
}
