// common.h
//
// Declaration for functions/variables common for main.cpp and event_init.c
// Added by Kacper (KSCB) 2025-05-14 00:10

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void common_sendMessage(int msg_id); // declare as C-compatible if compiled as C++

enum common_emoji{
    ALERT = 0,
    THUMB_UP = 1,
    WAVE = 2,
    HEART = 3,
    PARTY = 4
} common_emoji;

#ifdef __cplusplus
}
#endif