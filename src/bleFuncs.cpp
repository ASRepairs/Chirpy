#include "bleFuncs.h"
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <esp_log.h>
#include <esp_timer.h>

/* ─────────────  UUIDs  ───────────── */
constexpr char SERVICE_UUID[] = "0000abcd-0000-1000-8000-00805f9b34fb";
constexpr char CHAR_RX_UUID[] = "0000dcba-0000-1000-8000-00805f9b34fb"; // Android ➜ ESP
constexpr char CHAR_TX_UUID[] = "0000dcb1-0000-1000-8000-00805f9b34fb"; // ESP ➜ Android

/* ─────────────  Compile–time logging switch  ───────────── */
#define BLELOG
#ifdef BLELOG
static const char *TAG = "BLE";
#endif

/* ─────────────  Globals kept in .bss / .data  ───────────── */
static BLECharacteristic *rxChar = nullptr;
static BLECharacteristic *txChar = nullptr;
static BLEAdvertising *adv = nullptr;
static BLEServer *srv = nullptr;
static GPSData *extGpsData = nullptr;
static esp_timer_handle_t gpsTimer = nullptr;
static volatile bool gConnected = false;

/* ─────────────  Small helpers  ───────────── */
static inline void sendReqTime()
{
    static constexpr char msg[] = "REQ:TIME";
    if (gConnected && txChar)
    {
        txChar->setValue((uint8_t *)msg, sizeof(msg) - 1);
        txChar->notify();
    }
}

static void sendReqGps()
{
    static constexpr char msg[] = "REQ:GPS";
    if (gConnected && txChar)
    {
        txChar->setValue((uint8_t *)msg, sizeof(msg) - 1);
        txChar->notify();
    }
}

static void sendCurrentUser()
{
    if (!gConnected || !txChar)
        return;

    char buf[24];
    snprintf(buf, sizeof(buf), "CURR:%d,%d",
             globalUserData.userId,
             globalUserData.groupId
    );
    txChar->setValue((uint8_t *)buf, strlen(buf));
    txChar->notify();
#ifdef BLELOG
    ESP_LOGI(TAG, "TX → %s", buf);
#endif
}

void bleSendNotification(message_type_t type, int senderId, const char *payload)
{
    if (!gConnected || !txChar)
        return;

    // Estimate required buffer size based on message type
    size_t payload_len = strlen(payload);
    size_t overhead = 20;  // Rough: "NOTIF:%d:%d:" + null terminator
    size_t total_len = overhead + payload_len + 10; // extra padding

    char *buf = (char *)malloc(total_len);
    if (!buf)
    {
        ESP_LOGE(TAG, "Failed to allocate buffer for BLE message");
        return;
    }

    snprintf(buf, total_len, "NOTIF:%d:%d:%s", senderId, type, payload);
    txChar->setValue((uint8_t *)buf, strlen(buf));
    txChar->notify();

#ifdef BLELOG
    ESP_LOGI(TAG, "TX → %s", buf);
#endif
    free(buf);
}

/* ─────────────  ESP-timer callback (runs in its own tiny task)  ───────────── */
static void gpsTimerCb(void *)
{
    sendReqGps();
#ifdef BLELOG
    ESP_LOGI(TAG, "TX → REQ:GPS");
#endif
}

/* ─────────────  BLE Callbacks  ───────────── */
class RxCallback : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *c) override
    {
        const std::string &v = c->getValue();
        if (!extGpsData)
            return; // safety

        /* ────────── plain chat text (TXT:…) ────────── */
        if (v.rfind("TXT:", 0) == 0) // payload starts with "TXT:"
        {
            std::string msg = v.substr(4); // strip the prefix
            if (!msg.empty())
            {
#ifdef BLELOG
                ESP_LOGI(TAG, "RX ← TXT \"%s\"", msg.c_str());
#endif
                /* broadcast via LoRa */
                common_sendLoraMessage(msg.c_str(), true); // from BLE
            }
            return; // nothing more to do
        }

        else if (v.rfind("LOC:", 0) == 0)
        {
            float lat, lon;
            if (sscanf(v.c_str() + 4, "%f,%f", &lat, &lon) == 2)
            {
                extGpsData->latitude = lat;
                extGpsData->longitude = lon;
#ifdef BLELOG
                ESP_LOGI(TAG, "RX ← LOC %.5f,%.5f", lat, lon);
#endif
                common_sendLoraGPS(true); // broadcast as MSG_TYPE_GPS
            }
            else
            {
#ifdef BLELOG
                ESP_LOGW(TAG, "Bad LOC payload: %s", v.c_str());
#endif
            }
            return;
        }
        else if (v.rfind("SET_AVA:", 0) == 0)
        {
            int uid = atoi(v.c_str() + 8);
            if (uid >= 0 && uid <= 7)
            {
                globalUserData.userId = uid;
                sendCurrentUser(); // confirm back
                ui_request_sync(globalUserData.userId, globalUserData.groupId);
            }
            return;
        }
        else if (v.rfind("SET_GRP:", 0) == 0)
        {
            int gid = atoi(v.c_str() + 8);
            if (gid >= 1 && gid <= 10)
            {
                globalUserData.groupId = gid;
                sendCurrentUser(); // confirm back
                ui_request_sync(globalUserData.userId, globalUserData.groupId);
            }
            return;
        }
        else if (v == "REQ:USER")
        { // ask explicitly
            sendCurrentUser();
            return;
        }
        /* Fast comma count to decide what we received */
        uint8_t comma = 0;
        for (char ch : v)
            if (ch == ',')
                ++comma;

        /* ─────  CASE 1: GPS only  (lat,lon)  ───── */
        if (comma == 1)
        {
            float lat, lon;
            if (sscanf(v.c_str(), "%f,%f", &lat, &lon) == 2)
            {
                extGpsData->latitude = lat;
                extGpsData->longitude = lon;
#ifdef BLELOG
                ESP_LOGI(TAG, "RX ← GPS  %.5f,%.5f", lat, lon);
#endif
            }
            else
#ifdef BLELOG
                ESP_LOGW(TAG, "Bad GPS string: %s", v.c_str());
#endif
        }

        /* ─────  CASE 2: Time only (Y,M,D,h,m,s) ───── */
        else if (comma == 5)
        {
            int Y, M, D, h, m, s;
            if (sscanf(v.c_str(), "%d,%d,%d,%d,%d,%d",
                       &Y, &M, &D, &h, &m, &s) == 6)
            {
#ifdef BLELOG
                ESP_LOGI(TAG, "RX ← TIME %04d-%02d-%02d %02d:%02d:%02d",
                         Y, M, D, h, m, s);
#endif
                struct tm t{};
                t.tm_year = Y - 1900;
                t.tm_mon = M - 1;
                t.tm_mday = D;
                t.tm_hour = h;
                t.tm_min = m;
                t.tm_sec = s;

                time_t tt = mktime(&t);
                struct timeval now = {.tv_sec = tt, .tv_usec = 0};
                settimeofday(&now, nullptr);
                watch.hwClockWrite();
            }
            else
#ifdef BLELOG
                ESP_LOGW(TAG, "Bad TIME string: %s", v.c_str());
#endif
        }

        /* ─────  Anything else: ignore  ───── */
#ifdef BLELOG
        else
            ESP_LOGW(TAG, "Unexpected payload (commas=%u): %s",
                     comma, v.c_str());
#endif
    }
};

class SrvCb : public BLEServerCallbacks
{
    void onConnect(BLEServer *) override
    {
        gConnected = true;
        adv->stop(); // stop adverts while connected
        // start the timer to send GPS data every 5 minutes
        esp_timer_start_periodic(gpsTimer, 5ULL * 60 * 1000000); // five min
#ifdef BLELOG
        ESP_LOGI(TAG, "Client connected");
#endif
        ui_request_sync(globalUserData.userId, globalUserData.groupId);
        //sendCurrentUser();
    }
    void onDisconnect(BLEServer *) override
    {
        gConnected = false;
        esp_timer_stop(gpsTimer);
        adv->start(); // resume adverts
#ifdef BLELOG
        ESP_LOGI(TAG, "Client disconnected");
#endif
    }
};

/* ─────────────  The FreeRTOS task  ───────────── */
static void bleTask(void *arg)
{
    char *devName = static_cast<char *>(arg);
    BLEDevice::init(devName);
    BLEDevice::setMTU(32); // keep ATT payload short

    srv = BLEDevice::createServer();
    static SrvCb srvCb;
    srv->setCallbacks(&srvCb);

    auto *svc = srv->createService(SERVICE_UUID);

    rxChar = svc->createCharacteristic(CHAR_RX_UUID, BLECharacteristic::PROPERTY_WRITE);
    static RxCallback rxCb;
    rxChar->setCallbacks(&rxCb);
    rxChar->addDescriptor(new BLE2902());

    txChar = svc->createCharacteristic(CHAR_TX_UUID, BLECharacteristic::PROPERTY_NOTIFY);
    txChar->addDescriptor(new BLE2902());

    svc->start();

    adv = BLEDevice::getAdvertising();
    adv->addServiceUUID(SERVICE_UUID);
    adv->setScanResponse(false);
    adv->start();

#ifdef BLELOG
    ESP_LOGI(TAG, "Advertising as %s", devName);
#endif

    /* create 1× esp-timer once – reusable */
    esp_timer_create_args_t ta{.callback = gpsTimerCb, .name = "gpsT"};
    esp_timer_create(&ta, &gpsTimer);

    while (true)
        vTaskDelay(pdMS_TO_TICKS(1000));
}

/* ─────────────  API ───────────── */
void startBLETask(const char *bleName, GPSData *gpsData)
{
    extGpsData = gpsData;
    xTaskCreatePinnedToCore(bleTask, "ble", 8192 * 4, (void *)bleName, 1, NULL, 1);
}

/* optional helpers --------------------------------------------------*/
bool bleClientConnected() { return gConnected; }
void bleSendReqGpsNow() { sendReqGps(); }
