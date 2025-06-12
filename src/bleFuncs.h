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
void bleSendNotificationWithGps(message_type_t type, int senderId, float lat, float lon);

#endif // BLEFUNCS_H