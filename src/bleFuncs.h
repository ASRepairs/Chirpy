#ifndef BLEFUNCS_H
#define BLEFUNCS_H

#pragma once

#include <BLEServer.h>
#include <LilyGoLib.h>
#include "structs.h"

void startBLETask(const String &node_id, GPSData *gpsData);

#endif // BLEFUNCS_H