#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_spiffs.h"


//  Uncomment the one you want to use.
// #define ST7789
#define SSD1306

#ifdef ST7789
#include "../components/st7789/st7789.h"
#include "../components/st7789/fontx.h"
#endif

#ifdef SSD1306
#include "../components/ssd1306/ssd1306.h"
#include "../components/ssd1306/font8x8_basic.h"
#endif


#include "../components/ra01s/ra01s.h"


static const char *TAG = "ChirpyMain";

esp_err_t mountSPIFFS(const char *base_path, const char *partition_label, int max_files)
{
    esp_vfs_spiffs_conf_t conf = {
        .base_path = base_path,
        .partition_label = partition_label,
        .max_files = max_files,
        .format_if_mount_failed = true
    };
    esp_err_t ret = esp_vfs_spiffs_register(&conf);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to mount SPIFFS (%s)", esp_err_to_name(ret));
    } else {
        size_t total = 0, used = 0;
        ret = esp_spiffs_info(partition_label, &total, &used);
        if (ret == ESP_OK) {
            ESP_LOGI(TAG, "SPIFFS Partition [%s] mounted: total %d, used %d", partition_label, total, used);
        }
    }
    return ret;
}

#ifdef ST7789

// ST7789 display configuration and global variables
#define PIN_MOSI    23
#define PIN_SCLK    18
#define PIN_CS      5
#define PIN_DC      16
#define PIN_RESET   17
#define PIN_BL      4
#define DISP_WIDTH  240
#define DISP_HEIGHT 240
#define COLOR_BLACK 0x0000
#define COLOR_WHITE 0xFFFF

TFT_t tft;
FontxFile fx16G[2];

void display_init(void)
{
    spi_master_init(&tft, PIN_MOSI, PIN_SCLK, PIN_CS, PIN_DC, PIN_RESET, PIN_BL);
    // Initialize display with width, height, and offsets (here offsets are 0)
    lcdInit(&tft, DISP_WIDTH, DISP_HEIGHT, 0, 0);
    // clear display with a black screen
    lcdFillScreen(&tft, COLOR_BLACK);
}

void display_clear(void)
{
    //just fill the screen with black color
    lcdFillScreen(&tft, COLOR_BLACK);
}

void display_print(const char *msg)
{
    // clear the screen and print the message.
    lcdFillScreen(&tft, COLOR_BLACK);
    lcdDrawString(&tft, fx16G, 10, 100, (uint8_t *)msg, COLOR_WHITE);
}

#endif // ST7789

#ifdef SSD1306

SSD1306_t oled;

void display_init(void)
{

    i2c_master_init(&oled, CONFIG_SDA_GPIO, CONFIG_SCL_GPIO, CONFIG_RESET_GPIO);
#ifdef CONFIG_SSD1306_128x64
    ssd1306_init(&oled, 128, 64);
#else
    ssd1306_init(&oled, 128, 32);
#endif
    ssd1306_clear_screen(&oled, false);
    ssd1306_contrast(&oled, 0xff);
}

void display_clear(void)
{
    ssd1306_clear_screen(&oled, false);
}

void display_print(const char *msg)
{
    // Clear the screen and display the text on the first row.
    ssd1306_clear_screen(&oled, false);
    ssd1306_display_text(&oled, 0, msg, strlen(msg), false);
}

#endif // SSD1306



// LoRa configuration parameters.
#define LORA_FREQUENCY 868000000  // 868 MHz for EU
#define LORA_TX_POWER  14         // (range -3 to +22 dBm)
#define LORA_SPREADING_FACTOR 7
#define LORA_BANDWIDTH        0x08
#define LORA_CODING_RATE      1
#define LORA_PREAMBLE_LENGTH  8
#define LORA_PAYLOAD_LENGTH   0      // 0 = variable length packet
#define LORA_CRC_ON           true
#define LORA_INVERT_IQ        false

// GPIO configuration for the user button.
#define BUTTON_GPIO         GPIO_NUM_0  // the EN button
#define DEBOUNCE_DELAY_MS   50

//-------------------------------------------------------------------
// Task to poll for LoRa messages (polling version as in your code)
//-------------------------------------------------------------------
void lora_receive_task(void *arg)
{
    uint8_t rxBuffer[256];
    while (1) {
        // poll for a received packet.
        uint8_t rxLen = LoRaReceive(rxBuffer, sizeof(rxBuffer));
        if (rxLen > 0) {
            // Null-terminate
            if (rxLen < sizeof(rxBuffer)) {
                rxBuffer[rxLen] = '\0';
            } else {
                rxBuffer[sizeof(rxBuffer)-1] = '\0';
            }
            ESP_LOGI(TAG, "Received: %s", rxBuffer);
            display_clear();
            display_print("Message Received");
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

// Function to send a LoRa message and update the display.
void send_lora_message(void)
{
    const char *msg = "Hello from board";
    ESP_LOGI(TAG, "Sending message: %s", msg);

    // Send the message in synchronous mode.
    bool success = LoRaSend((uint8_t *)msg, strlen(msg), SX126x_TXMODE_SYNC);
    if (success) {
        display_clear();
        display_print("Message Sent");
    } else {
        display_clear();
        display_print("Send Failed");
    }
}

void app_main(void)
{
    ESP_LOGW(TAG, "main start");
    ESP_LOGI(TAG, "Mounting SPIFFS for fonts");
    ESP_ERROR_CHECK(mountSPIFFS("/fonts", "storage", 7));

#ifdef ST7789
    // Initialize font for ST7789 display.
    InitFontx(fx16G, "/fonts/ILGH16XB.FNT", "");
#endif

    // Button GPIO initialization.
    gpio_config_t btn_conf = {
        .pin_bit_mask = (1ULL << BUTTON_GPIO),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE, //TODO: check on hardware if needed
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&btn_conf);

    // init the display.
    display_init();
    display_clear();
    display_print("Welcome!!!!!");

    // init the LORA driver.
    LoRaInit();
    if (LoRaBegin(LORA_FREQUENCY, LORA_TX_POWER, 0.0, true) != ERR_NONE) {
        ESP_LOGE(TAG, "LoRaBegin failed");
        display_clear();
        display_print("LoRa Init Failed");
        return;
    }
    ESP_LOGE(TAG, "LoRaBegin success");
    display_clear();
    display_print("LoRa Init success");
    // modulation parameters config
    LoRaConfig(LORA_SPREADING_FACTOR, LORA_BANDWIDTH, LORA_CODING_RATE,
               LORA_PREAMBLE_LENGTH, LORA_PAYLOAD_LENGTH, LORA_CRC_ON, LORA_INVERT_IQ);

    // making LoRa to receive continuously.
    SetRx(0xFFFFFF);

    // task to poll for incoming LoRa messages.
    xTaskCreate(lora_receive_task, "lora_receive_task", 4096, NULL, 5, NULL);

    // Main loop poll for the button press to trigger a message send.
    while (1) {

        if (gpio_get_level(BUTTON_GPIO) == 0) {
            vTaskDelay(pdMS_TO_TICKS(DEBOUNCE_DELAY_MS));
            if (gpio_get_level(BUTTON_GPIO) == 0) {
                send_lora_message();
                display_print("message sent");
                ESP_LOGI(TAG, "lora message sent!");
                while (gpio_get_level(BUTTON_GPIO) == 0) {
                    vTaskDelay(pdMS_TO_TICKS(10));
                }
            }
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
