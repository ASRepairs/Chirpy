// common.h
//
// Declaration for functions/variables common for main.cpp and event_init.c
// Added by Kacper (KSCB) 2025-05-14 00:10

#pragma once

#ifdef __cplusplus
extern "C" {
#endif
// declare as C-compatible if compiled as C++

int common_sendMessage(int msg_id);
void common_displayMessageUI(int msg_id, int usr_id);

enum common_emoji{
    ALERT = 0,
    THUMB_UP = 1,
    WAVE = 2,
    HEART = 3,
    PARTY = 4
} common_emoji;

int common_current_group;  // TODO: move that variable to flash memory
int common_current_user;  // TODO: move that variable to flash memory

void common_change_group(int gr_id);

#ifdef __cplusplus
}
#endif