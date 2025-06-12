#ifndef BLEFUNCS_H
#define BLEFUNCS_H

#pragma once

#include <BLEServer.h>
#include <LilyGoLib.h>
#include "structs.h"

bool bleClientConnected();
void bleSendReqGpsNow();
void startBLETask(const char *bleName, GPSData *gpsData);

#endif // BLEFUNCS_H