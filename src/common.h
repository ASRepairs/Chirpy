// common.h
//
// Declaration for functions/variables common for main.cpp and event_init.c
// Added by Kacper (KSCB) 2025-05-14 00:10

#pragma once
#include <esp_err.h>
#ifdef __cplusplus
#include <Arduino.h>
extern "C" {
#endif
// declare as C-compatible if compiled as C++

esp_err_t common_sendLoraMessage(const char *msg, bool from_ble); // message structure is: "<node_id>:<msg_uid>:<group_id>:<user_id>:<type>:<payload>"
esp_err_t common_sendLoraEmoji(int msg, bool from_ble);
esp_err_t common_sendLoraAlert(bool from_ble);
esp_err_t common_sendLoraGPS(bool from_ble);
void common_displayMessageUI(int msg_id, int usr_id);
void common_setBrightness(uint8_t level);
void common_setVibration(bool enable);
#ifdef __cplusplus
} // extern "C"
#endif


typedef enum
{
    THUMB_UP = 1,
    WAVE = 2,
    HEART = 3,
    PARTY = 4
} common_emoji;

typedef enum
{
    FROGGY = 0,
    PIGGY = 1,
    HORSY = 2,
    PANDY = 3,
    LIZZY = 4,
    PHOENY = 5,
    PUPPY = 6,
    KITTY = 7
} user_emoji;

typedef enum
{
    MSG_TYPE_TEXT = 1,
    MSG_TYPE_EMOJI = 2,
    MSG_TYPE_GPS = 3,
    MSG_TYPE_ALERT = 4
} message_type_t;
