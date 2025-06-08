#include "bleFuncs.h"
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <LilyGoLib.h>
#include <esp_log.h>

#define SERVICE_UUID "0000abcd-0000-1000-8000-00805f9b34fb"
#define CHAR_UUID "0000dcba-0000-1000-8000-00805f9b34fb"


#define BLELOG // Uncomment to enable BLE logging
#ifdef BLELOG
static const char *TAG = "BLE_TASK";
#endif

// BLE state
static BLEServer *pServer = nullptr;
static BLECharacteristic *pCharacteristic = nullptr;
static BLEAdvertising *pAdvertising = nullptr;
static volatile bool isConnected = false;
static volatile bool wasConnected = false;
static GPSData *gpsDataPtr = nullptr;

// ───────────────────────────── CALLBACKS ─────────────────────────────
class MyServerCallbacks : public BLEServerCallbacks
{
    void onConnect(BLEServer *) override
    {
        isConnected = true;
#ifdef BLELOG
        ESP_LOGI(TAG, "Device connected");
#endif
    }

    void onDisconnect(BLEServer *) override
    {
        isConnected = false;
#ifdef BLELOG
        ESP_LOGW(TAG, "Device disconnected");
#endif
        vTaskDelay(pdMS_TO_TICKS(200)); // allow stack to clear
        pAdvertising->start();
#ifdef BLELOG
        ESP_LOGI(TAG, "Advertising restarted");
#endif
    }
};

class GPSWriteCallback : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pChar) override
    {
        const std::string &value = pChar->getValue();

        float lat, lon;
        int yr, mon, d, h, m, s;

        if (sscanf(value.c_str(), "%f,%f,%d,%d,%d,%d,%d,%d",
                   &lat, &lon, &yr, &mon, &d, &h, &m, &s) == 8 &&
            gpsDataPtr)
        {

            gpsDataPtr->latitude = lat;
            gpsDataPtr->longitude = lon;
            gpsDataPtr->year = yr;
            gpsDataPtr->month = mon;
            gpsDataPtr->day = d;
            gpsDataPtr->hour = h;
            gpsDataPtr->minute = m;
            gpsDataPtr->second = s;
            gpsDataPtr->valid = true;

#ifdef BLELOG
            ESP_LOGI(TAG, "Parsed: %.6f, %.6f @ %04d-%02d-%02d %02d:%02d:%02d",
                     lat, lon, yr, mon, d, h, m, s);
#endif
        }
        else
        {
#ifdef BLELOG
            ESP_LOGW(TAG, "Invalid GPS+time string or null pointer");
#endif
        }
    }
};

// ───────────────────────────── TASK ─────────────────────────────
void bleTask(void *param)
{
    std::string *nodeId = static_cast<std::string *>(param);
    std::string deviceName = "Chirpy_" + *nodeId;
    delete nodeId;

    BLEDevice::init(deviceName.c_str());
    BLEDevice::setMTU(23); // prevent long writes

    pServer = BLEDevice::createServer();
    static MyServerCallbacks serverCallbacks;
    pServer->setCallbacks(&serverCallbacks);

    BLEService *service = pServer->createService(SERVICE_UUID);
    pCharacteristic = service->createCharacteristic(
        CHAR_UUID, BLECharacteristic::PROPERTY_WRITE);

    pCharacteristic->addDescriptor(new BLE2902()); // safe to heap alloc
    static GPSWriteCallback writeCb;
    pCharacteristic->setCallbacks(&writeCb);

    service->start();

    pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->start();

#ifdef BLELOG
    ESP_LOGI(TAG, "Advertising as %s", deviceName.c_str());
#endif

    while (true)
    {
        if (isConnected && !wasConnected)
        {
            wasConnected = true;
#ifdef BLELOG
            ESP_LOGI(TAG, "Client connected");
#endif
        }

        if (!isConnected && wasConnected)
        {
            wasConnected = false;
#ifdef BLELOG
            ESP_LOGI(TAG, "Client disconnected");
#endif
        }

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

// ───────────────────────────── PUBLIC ─────────────────────────────
void startBLETask(const String &node_id, GPSData *gpsData)
{
    gpsDataPtr = gpsData;
    auto *idCopy = new std::string(node_id.c_str());
    xTaskCreatePinnedToCore(bleTask, "BLETask", 6144, idCopy, 1, NULL, 0);
}
