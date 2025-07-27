
# Chirpy – Instant Commmunicator Watch For Everyone.
### LoRa messaging for LilyGo T‑Watch‑S3

> **KPZ 2025 — Wrocław** • Built for **Politechnika Wrocławska (PWR)** in collaboration with **Estigiti**.
> Chirpy is a simple, resilient, group‑chat‑style messenger that runs on the **LilyGo T‑Watch‑S3** and uses **LoRa** for long‑range communication. An Android companion app provides typing, GPS and settings via **BLE**; the watch rebroadcasts packets to form a lightweight mesh. The UI is designed in **SquareLine Studio** and rendered with **LVGL**.

---

## Features

* **Long‑range messaging over LoRa.** Default carrier frequency is **868.0 MHz** (EU ISM band). You can change this in code if required by your region (hardware must also support it).
* **BLE companion link** to Android for sending text, GPS/location, avatar and group settings, with a small custom protocol.
* **Mesh‑style rebroadcast with de‑duplication** — watches forward new messages and ignore already‑seen ones.
* **Groups & avatars.** Users pick a **group (1–10)** and an avatar; group **0** is reserved for broadcast (e.g., alerts).
* **Alerts & GPS.** Send an alert to all groups, optionally with GPS coordinates; GPS messages can also be shared to your current group. Phone Link with the app is required to send GPS location.
* **Nice watch UX.** SquareLine/LVGL UI, notification overlay, vibration patterns per message type, auto screen‑off and quick wake.
* **Battery + time/date** shown and kept fresh using the AXP2101 PMU and the watch RTC.
* **On‑device QR code** showing your watch ID for easy and seamless phone pairing.

---

## Hardware

* **Watch**: LilyGo **T‑Watch‑S3** (ESP32‑S3 + SX1262 LoRa + AXP2101 PMU). The firmware uses `LilyGoLib`, LVGL helpers and RadioLib.
* **Phone**: Android device with Bluetooth LE.
* **LoRa**: SX1262 configured at **868.0 MHz** by default for EU.

> **Regulatory note:** Always operate within your local spectrum rules. The default 868 MHz is intended for EU/ETSI regions — change it if your deployment differs.

---

## System overview

* The phone connects over **BLE** to send **text**, **GPS** and **settings** and to receive **notifications** from the watch.
* The watch transmits and **re-broadcasts** LoRa packets; already‑seen IDs are cached to avoid loops.

---

## Message & data model

### LoRa frame (watch ↔ watch)

All payloads on the air use a single, human‑readable frame:

```
<node_id>:<msg_uid>:<group_id>:<user_id>:<type>:<payload>
```

* `node_id`: The sender’s node name, e.g. `Chirpy_<ESP_MAC>` (shown as a QR at boot).
* `msg_uid`: A message ID (millis‑based) to de‑duplicate rebroadcasts.
* `group_id`: Active group (1–10), or **0** for broadcast.
* `user_id`: Selected avatar index (see below).
* `type`: One of `TEXT=1, EMOJI=2, GPS=3, ALERT=4`.
* `payload`: Type‑specific body (text, emoji code, `lat,lon`, or empty for alert without GPS).


**User & battery structs**

```c
struct userData { uint8_t groupId; uint8_t userId; };       // persisted runtime state
typedef struct { uint8_t pct; bool charging; } batt_info_t; // UI battery label
```


**Avatars / user IDs**
Eight built‑in avatars are mapped to `0..7` (Froggy, Piggy, Horsy, Pandy, Lizzy, Phoeny, Puppy, Kitty). UI is synced whenever the user or group changes.

**Emoji payloads**
Predefined emoji codes: `THUMB_UP=1`, `WAVE=2`, `HEART=3`, `PARTY=4`.

---

## BLE protocol (Android ↔ watch)

**GATT layout**

```text
Service UUID:        0000abcd-0000-1000-8000-00805f9b34fb
Characteristic (RX): 0000dcba-0000-1000-8000-00805f9b34fb  // Android → Watch (WRITE)
Characteristic (TX): 0000dcb1-0000-1000-8000-00805f9b34fb  // Watch   → Android (NOTIFY)
```

MTU is set to 128 by default.

**Android → Watch (write to RX)**

* `TXT:<message>` — send chat text; watch rebroadcasts on LoRa.
* `LOC:<lat>,<lon>` — update GPS and (optionally) broadcast as a GPS message.
* `SET_AVA:<0..7>` — choose avatar (user ID).
* `SET_GRP:<1..10>` — set active group. (Group **0** is reserved for broadcast by the firmware).
* `REQ:USER` — ask the watch to report current user + group.
* `Y,M,D,h,m,s` — set time on the watch (comma‑separated).

**Watch → Android (notifications on TX)**

* `NOTIF:<senderId>:<type>:<payload>` — mirrored for anything received/created on the watch. Types match the LoRa `type` field.
* `CURR:<userId>,<groupId>` — state sync when changed or on request.
* `REQ:TIME` — prompts the phone to send current time.
* `REQ:GPS` — sent every **5 minutes** while connected; phone should reply with `LOC:…`.

**Connection lifecycle**
On connect: advertising stops and the periodic **REQ\:GPS** timer starts; UI sync is triggered. On disconnect: timer stops and advertising resumes.

---

## Watch UX details

* **Notifications:** Overlay pops in for messages (text, emoji, GPS, alerts). Alerts show a special icon and typically don’t auto‑dismiss.
* **Haptics:** Different vibration pattern for alerts vs other messages; vibration can be globally enabled/disabled.
* **Buttons & power:**
  * **Short press:** wake screen (and jump to Home).
  * **Long press:** turn display off.
  * **Very long press:** power off the watch.
  * **Auto sleep:** screen turns off after \~30 s of inactivity; wakes on interaction.
* **QR Code for pairing:** A QR code with `Chirpy_<MAC>` is rendered for easy pairing in the connect section.

---

## Build & run

### Firmware (PlatformIO)

1. Install **VS Code** and **PlatformIO**.
2. Open the project folder that contains `platformio.ini` for the **ESP32‑S3** T‑Watch‑S3.
3. Build & upload.

**Changing LoRa frequency:** edit `LORA_FREQUENCY` (e.g., 915.0 for US).

### Android app (Android Studio)

* The app:
  * Scans and connects to `Chirpy_<MAC>` using the QR code.
  * Subscribes to TX (`notify`) and writes to RX using the commands above.
  * Replies to `REQ:TIME` and periodic `REQ:GPS`.
  * Shows incoming messages and notifications.

### UI (SquareLine Studio)

* The LVGL project and exported assets live under `ChirpyUI/…` and are included via `ChirpyUI/ui.h`. Update assets in SquareLine and re‑export to that folder.

---

## Project layout

* SquareLine Studio Project files are in ChirpyUI folder in /src
* Android Studio Project files are in AndroidBLE folder in root (The built APK is also in root folder)
  

---

## Roadmap / TODO

* [ ] PlatformIO envs for multiple regions (EU 868 / US 915).
* [ ] Optional acknowledgements & RSSI/SNR display.
* [ ] Persist user/group across reboots.
* [ ] Code refactor (Main is too big).

---

## Credits

**Authors:** 
Ahmed Al-Tameemi, Project, UI, Lora Comms, Android App.

W12N dept at **PWR (Politechnika Wrocławska)** supervised by Mical Rudowicz from **Estigiti**.

---

## License

GPL-3.0

