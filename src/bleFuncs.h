#ifndef BLEFUNCS_H
#define BLEFUNCS_H

#pragma once

#include <BLEServer.h>
#include <LilyGoLib.h>
#include "structs.h"
#include "common.h"
bool bleClientConnected();
void bleSendReqGpsNow();
void startBLETask(const char *bleName, GPSData *gpsData);
void bleSendNotification(message_type_t type, int senderId, const char *payload);

#endif // BLEFUNCS_H