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

esp_err_t common_sendLoraMessage(const char *msg);
esp_err_t common_sendLoraEmoji(int msg);
esp_err_t common_sendLoraAlert(void);
esp_err_t common_sendLoraGPS(void);
void common_displayMessageUI(int msg_id, int usr_id);
void common_setBrightness(uint8_t level);
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
    PANDY = 3
} user_emoji;

typedef enum
{
    MSG_TYPE_TEXT = 1,
    MSG_TYPE_EMOJI = 2,
    MSG_TYPE_GPS = 3,
    MSG_TYPE_ALERT = 4
} message_type_t;
