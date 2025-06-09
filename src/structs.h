#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdint.h>
struct GPSData
{
    float latitude;
    float longitude;
    bool valid;
};

struct userData
{
    uint8_t groupId; // 0-9, 0 = no group
    uint8_t userId;  // 0-9, 0 = no user
};

extern struct userData globalUserData;

#endif // STRUCTS_H