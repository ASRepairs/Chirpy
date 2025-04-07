#ifndef ESP_HAL_H
#define ESP_HAL_H

#include <RadioLib.h>

// Also ensure your sdkconfig has either CONFIG_IDF_TARGET_ESP32 or CONFIG_IDF_TARGET_ESP32S3 set.
#if !defined(CONFIG_IDF_TARGET_ESP32) && !defined(CONFIG_IDF_TARGET_ESP32S3)
  #error This HAL supports ESP32 and ESP32-S3 targets.
#endif

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_timer.h"
#include "esp_log.h"
#include "driver/spi_master.h"

#ifdef CONFIG_IDF_TARGET_ESP32
  #include "esp32/rom/gpio.h"
#elif defined(CONFIG_IDF_TARGET_ESP32S3)
  #include "esp32s3/rom/gpio.h"
#endif

// Arduino-like macros
#define LOW     (0x0)
#define HIGH    (0x1)
#define INPUT   (0x01)
#define OUTPUT  (0x03)
#define RISING  (0x01)
#define FALLING (0x02)
#define NOP()   asm volatile("nop")

class EspHal : public RadioLibHal {
  public:
    EspHal(int8_t sck, int8_t miso, int8_t mosi)
      : RadioLibHal(INPUT, OUTPUT, LOW, HIGH, RISING, FALLING),
        spiSCK(sck), spiMISO(miso), spiMOSI(mosi), spi_device(nullptr) {}

    // Called by RadioLib once at startup
    void init() override {
      spiBegin();
    }

    void term() override {
      spiEnd();
    }

    // Basic GPIO
    void pinMode(uint32_t pin, uint32_t mode) override {
      if(pin == RADIOLIB_NC) return;
      gpio_config_t conf = {};
      conf.pin_bit_mask = (1ULL << pin);
      conf.mode = static_cast<gpio_mode_t>(mode);
      conf.pull_up_en = GPIO_PULLUP_DISABLE;
      conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
      conf.intr_type = GPIO_INTR_DISABLE;
      gpio_config(&conf);
    }

    void digitalWrite(uint32_t pin, uint32_t val) override {
      if(pin == RADIOLIB_NC) return;
      gpio_set_level(static_cast<gpio_num_t>(pin), val);
    }

    uint32_t digitalRead(uint32_t pin) override {
      if(pin == RADIOLIB_NC) return 0;
      return gpio_get_level(static_cast<gpio_num_t>(pin));
    }

    // Interrupts
    void attachInterrupt(uint32_t intNum, void (*isr)(void), uint32_t mode) override {
      if(intNum == RADIOLIB_NC) return;
      gpio_set_intr_type((gpio_num_t)intNum, (gpio_int_type_t)(mode & 0x7));
      gpio_install_isr_service(ESP_INTR_FLAG_IRAM);
      gpio_isr_handler_add((gpio_num_t)intNum, reinterpret_cast<gpio_isr_t>(isr), nullptr);
    }

    void detachInterrupt(uint32_t intNum) override {
      if(intNum == RADIOLIB_NC) return;
      gpio_isr_handler_remove((gpio_num_t)intNum);
      gpio_set_intr_type((gpio_num_t)intNum, GPIO_INTR_DISABLE);
    }

    // Timing
    void delay(unsigned long ms) override {
      vTaskDelay(pdMS_TO_TICKS(ms));
    }

    void delayMicroseconds(unsigned long us) override {
      uint64_t start = esp_timer_get_time();
      while((esp_timer_get_time() - start) < us) {
        // spin
      }
    }

    unsigned long millis() override {
      return (unsigned long)(esp_timer_get_time() / 1000ULL);
    }

    unsigned long micros() override {
      return (unsigned long)esp_timer_get_time();
    }

    // Basic pulse measurement (blocking)
    long pulseIn(uint32_t pin, uint32_t state, unsigned long timeout) override {
      if(pin == RADIOLIB_NC) return 0;
      uint64_t start = micros();
      while(digitalRead(pin) == state) {
        if((micros() - start) > timeout) {
          return 0;
        }
      }
      return (long)(micros() - start);
    }

    // SPI
    void spiBegin() {
      // Zero-init the bus config, then assign fields
      spi_bus_config_t bus_cfg = {};
      bus_cfg.mosi_io_num = spiMOSI;
      bus_cfg.miso_io_num = spiMISO;
      bus_cfg.sclk_io_num = spiSCK;
      bus_cfg.quadwp_io_num = -1;
      bus_cfg.quadhd_io_num = -1;
      bus_cfg.max_transfer_sz = 4094;

      // Zero-init the device config, then assign fields
      spi_device_interface_config_t dev_cfg = {};
      dev_cfg.mode = 0;                  // SPI mode 0
      dev_cfg.clock_speed_hz = 2000000;  // 2 MHz
      dev_cfg.spics_io_num = -1;         // no dedicated CS
      dev_cfg.queue_size = 1;
      dev_cfg.flags = SPI_DEVICE_NO_DUMMY;

      // Initialize bus and add device
      ESP_ERROR_CHECK(spi_bus_initialize(SPI2_HOST, &bus_cfg, SPI_DMA_CH_AUTO));
      ESP_ERROR_CHECK(spi_bus_add_device(SPI2_HOST, &dev_cfg, &spi_device));
    }

    void spiBeginTransaction() override {
      // no-op for ESP-IDF
    }

    // If your parent class has spiTransfer(uint8_t), rename this to match exactly
    uint8_t spiTransferByte(uint8_t b) {
      // Zero-init transaction, then assign
      spi_transaction_t t = {};
      t.flags = (SPI_TRANS_USE_TXDATA | SPI_TRANS_USE_RXDATA);
      t.length = 8;    // bits to transmit
      t.rxlength = 0;  // we'll rely on length for full-duplex
      t.tx_data[0] = b;

      ESP_ERROR_CHECK(spi_device_transmit(spi_device, &t));
      return t.rx_data[0];
    }

    void spiTransfer(uint8_t* out, size_t len, uint8_t* in) override {
      spi_transaction_t t = {};
      t.length = static_cast<uint32_t>(len * 8); // bits
      t.tx_buffer = out;
      t.rx_buffer = in;

      ESP_ERROR_CHECK(spi_device_transmit(spi_device, &t));
    }

    void spiEndTransaction() override {
      // no-op for ESP-IDF
    }

    void spiEnd() {
      if(spi_device) {
        spi_bus_remove_device(spi_device);
        spi_bus_free(SPI2_HOST);
        spi_device = nullptr;
      }
    }

  private:
    int8_t spiSCK;
    int8_t spiMISO;
    int8_t spiMOSI;
    spi_device_handle_t spi_device;
};

#endif
