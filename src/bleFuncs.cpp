#include "bleFuncs.h"
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <LilyGoLib.h>
#include <esp_log.h>

static const char *TAG = "BLE_TASK";

// BLE state variables
static BLEServer *pServer = nullptr;
static BLECharacteristic *pCharacteristic = nullptr;
static BLEAdvertising *pAdvertising = nullptr;
static bool isConnected = false;
static bool wasConnected = false;
static GPSData *gpsDataPtr = nullptr;

#define SERVICE_UUID "0000abcd-0000-1000-8000-00805f9b34fb"
#define CHAR_UUID "0000dcba-0000-1000-8000-00805f9b34fb"

// ───────────────────────────── CALLBACKS ─────────────────────────────
class MyServerCallbacks : public BLEServerCallbacks
{
    void onConnect(BLEServer *server) override
    {
        ESP_LOGI(TAG, "Device connected");
        isConnected = true;
    }

    void onDisconnect(BLEServer *server) override
    {
        ESP_LOGW(TAG, "Device disconnected");
        isConnected = false;
        vTaskDelay(pdMS_TO_TICKS(200));
        pAdvertising->start();
        ESP_LOGI(TAG, "Advertising restarted");
    }
};

class GPSWriteCallback : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pChar) override
    {
        std::string gpsRaw = pChar->getValue();
        ESP_LOGI(TAG, "Received: %s", gpsRaw.c_str());

        float lat, lon;
        if (sscanf(gpsRaw.c_str(), "%f,%f", &lat, &lon) == 2 && gpsDataPtr != nullptr)
        {
            gpsDataPtr->latitude = lat;
            gpsDataPtr->longitude = lon;
            gpsDataPtr->valid = true;
            ESP_LOGI(TAG, "Parsed: %.6f, %.6f", lat, lon);
        }
        else
        {
            ESP_LOGW(TAG, "Invalid GPS string or null pointer");
        }
    }
};

// ───────────────────────────── TASK ─────────────────────────────
void bleTask(void *param)
{
    String *nodeIdPtr = static_cast<String *>(param);
    String deviceName = "Chirpy_" + *nodeIdPtr;
    delete nodeIdPtr; // Free after use

    BLEDevice::init(deviceName.c_str());
    BLEDevice::setMTU(23); // Prevent long writes

    pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks());

    BLEService *service = pServer->createService(SERVICE_UUID);

    pCharacteristic = service->createCharacteristic(
        CHAR_UUID,
        BLECharacteristic::PROPERTY_WRITE // normal write only
    );

    pCharacteristic->addDescriptor(new BLE2902());
    pCharacteristic->setCallbacks(new GPSWriteCallback());

    service->start();

    pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->start();

    ESP_LOGI(TAG, "Started advertising as %s", deviceName.c_str());

    while (true)
    {
        if (isConnected && !wasConnected)
        {
            ESP_LOGI(TAG, "Client connected");
            wasConnected = true;
        }
        else if (!isConnected && wasConnected)
        {
            ESP_LOGI(TAG, "Client disconnected");
            wasConnected = false;
        }

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

// ───────────────────────────── PUBLIC ─────────────────────────────
void startBLETask(const String &node_id, GPSData *gpsData)
{
    gpsDataPtr = gpsData;
    String *idCopy = new String(node_id);
    xTaskCreatePinnedToCore(bleTask, "BLETask", 4096, idCopy, 1, nullptr, 0);
}
