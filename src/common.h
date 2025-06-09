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
void common_displayMessageUI(int msg_id, int usr_id);

#ifdef __cplusplus
} // extern "C"
#endif


typedef enum
{
    ALERT = 0,
    THUMB_UP = 1,
    WAVE = 2,
    HEART = 3,
    PARTY = 4
} common_emoji;