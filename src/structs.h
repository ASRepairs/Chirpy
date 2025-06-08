#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdint.h>
struct GPSData
{
    float latitude;
    float longitude;
    bool valid;
};
#endif // STRUCTS_H