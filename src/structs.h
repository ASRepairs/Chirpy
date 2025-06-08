#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdint.h>
struct GPSData
{
    float latitude;
    float longitude;
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    bool valid;
};
#endif // STRUCTS_H