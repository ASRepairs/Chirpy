#include <cstdio>
#include <cstring>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include <RadioLib.h>
extern "C"{
#include "../components/st7789/st7789.h"
#include "../components/st7789/fontx.h"
}

#include "esp_spiffs.h"
#include "EspHal.h"

static const char *TAG = "ChirpyMain";

// Radio module configuration
#define LORA_FREQUENCY     868000000  // 868 MHz EU
#define LORA_TX_POWER      14         // +14 dBm
#define TCXO_VOLTAGE       1.8f       // Typical for SX126x
#define USE_LDO            true

// Display configuration
#define COLOR_BLACK 0x0000
#define COLOR_WHITE 0xFFFF

// Hardware configuration
#define BUTTON_GPIO        GPIO_NUM_0
#define DEBOUNCE_DELAY_MS  50

TFT_t tft;
FontxFile fx16G[2];
SX1262 radio(nullptr);  // Use proper RadioLib initialization

extern "C" esp_err_t mountSPIFFS(const char* base_path, const char* partition_label, int files) {
    esp_vfs_spiffs_conf_t conf = {
        .base_path = base_path,
        .partition_label = partition_label,
        .max_files = static_cast<size_t>(files),
        .format_if_mount_failed = true
    };
    esp_err_t ret = esp_vfs_spiffs_register(&conf);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to mount SPIFFS (%s)", esp_err_to_name(ret));
    } else {
        size_t total = 0, used = 0;
        ret = esp_spiffs_info(partition_label, &total, &used);
        if (ret == ESP_OK) {
            ESP_LOGI(TAG, "SPIFFS Partition [%s] mounted: total %u, used %u",
                     partition_label, (unsigned)total, (unsigned)used);
        }
    }
    return ret;
}

void display_init(void) {
    spi_master_init(&tft, CONFIG_ST7789_MOSI_GPIO, CONFIG_ST7789_SCLK_GPIO,
                   CONFIG_ST7789_CS_GPIO, CONFIG_ST7789_DC_GPIO,
                   CONFIG_ST7789_RESET_GPIO, CONFIG_BL_GPIO);
    lcdInit(&tft, CONFIG_WIDTH, CONFIG_HEIGHT, CONFIG_OFFSETX, CONFIG_OFFSETY);
    lcdFillScreen(&tft, COLOR_BLACK);
}

void display_clear(void) {
    lcdFillScreen(&tft, COLOR_BLACK);
}

void display_print(const char *msg) {
    lcdFillScreen(&tft, COLOR_BLACK);
    lcdDrawString(&tft, fx16G, 10, 100, (uint8_t *)msg, COLOR_WHITE);
}

void lora_receive_task(void *arg) {
    while (1) {
        // Check if packet received
        if (radio.available()) {
            uint8_t rxBuffer[256];
            int state = radio.readData(rxBuffer, sizeof(rxBuffer));

            if (state == RADIOLIB_ERR_NONE) {
                size_t rxLen = radio.getPacketLength();
                rxBuffer[rxLen < sizeof(rxBuffer) ? rxLen : sizeof(rxBuffer)-1] = '\0';
                ESP_LOGI(TAG, "Received: %s", rxBuffer);
                display_print("Message Received");
            }
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void send_lora_message(void) {
    const char *msg = "x";
    ESP_LOGI(TAG, "Sending message: %s", msg);

    int state = radio.transmit((uint8_t*)msg, strlen(msg));
    if (state == RADIOLIB_ERR_NONE) {
        display_print("Message Sent");
        vTaskDelay(pdMS_TO_TICKS(1000));
    } else {
        ESP_LOGE(TAG, "Send failed: %d", state);
        display_print("Send Failed");
    }
}

extern "C" void app_main(void) {
    ESP_LOGW(TAG, "Application start");

    // Initialize SPIFFS
    ESP_ERROR_CHECK(mountSPIFFS("/fonts", "storage", 7));
    InitFontx(fx16G, "/fonts/ILGH16XB.FNT", "");

    // Button initialization - fix missing initializers
    gpio_config_t btn_conf = {
        .pin_bit_mask = (1ULL << BUTTON_GPIO),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&btn_conf);

    // Display initialization
    display_init();
    display_print("Initializing...");

    // RadioLib HAL
    EspHal* hal = new EspHal(
        CONFIG_SX126X_SCLK_GPIO,  // SCK
        CONFIG_SX126X_MISO_GPIO,  // MISO
        CONFIG_SX126X_MOSI_GPIO   // MOSI
    );

    // RadioLib module with  pin mapping
    Module* lora_module = new Module(
        hal,
        CONFIG_SX126X_NSS_GPIO,   // NSS
        9,                        // DIO1 (IO9)
        CONFIG_SX126X_RST_GPIO,   // RST
        CONFIG_SX126X_BUSY_GPIO   // BUSY
    );
    radio = SX1262(lora_module);

    // Radio initialization with parameters
    ESP_LOGI(TAG, "Initializing SX1262...");
    int state = radio.begin(
        LORA_FREQUENCY/1e6,   // Frequency in MHz
        125.0,                // Bandwidth
        9,                    // Spreading factor
        7,                    // Coding rate
        RADIOLIB_SX126X_SYNC_WORD_PRIVATE, // Sync word
        LORA_TX_POWER,        // TX power
        8,                    // Preamble length
        TCXO_VOLTAGE,         // TCXO voltage
        USE_LDO               // Use LDO regulator
    );

    if (state != RADIOLIB_ERR_NONE) {
        ESP_LOGE(TAG, "Radio init failed: %d", state);
        display_print("Radio Error");
        while(1) vTaskDelay(1000);
    }

    radio.setTCXO(TCXO_VOLTAGE);

    radio.startReceive();

    // receive task
    xTaskCreate(lora_receive_task, "lora_rx", 4096, NULL, 5, NULL);
    display_print("Ready");

    // Main loop
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
        send_lora_message();
        vTaskDelay(pdMS_TO_TICKS(1000));
        if (gpio_get_level(BUTTON_GPIO) == 0) {
            vTaskDelay(pdMS_TO_TICKS(DEBOUNCE_DELAY_MS));
            if (gpio_get_level(BUTTON_GPIO) == 0) {
                send_lora_message();
                while (gpio_get_level(BUTTON_GPIO) == 0) {
                    vTaskDelay(pdMS_TO_TICKS(10));
                }
            }
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}