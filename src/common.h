// common.h
//
// Declaration for functions/variables common for main.cpp and event_init.c
// Added by Kacper (KSCB) 2025-05-14 00:10

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void common_sendMessage(int msgid); // declare as C-compatible if compiled as C++

enum common_emoji{
    THUMB_UP,
    WAVE,
    HEART,
    PARTY,
    ALERT
};

#ifdef __cplusplus
}
#endif