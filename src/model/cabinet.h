#ifndef CABINET_H
#define CABINET_H
#include <Arduino.h>

// #include "port.h"

class Cabinet
{

private:
    String id;

private:
    byte hash;

private:
    bool active;

private:
    bool available;

private:
    bool isPrivate;

private:
    String description;

private:
    float latitude;

private:
    float longitude;

// private:
//     Port ports;

public:
    Cabinet(String id, byte hash, bool active, bool available, bool isPrivate, String description, float latitude, float longitude/*, Port ports*/);
    void init();

    String getId();
    void setId(String id);

    byte getHash();
    void setHash(byte hash);

    bool getActive();
    void setActive(bool active);

    bool getAvailable();
    void setAvailable(bool available);

    bool getIsPrivate();
    void setIsPrivate(bool isPrivate);

    String getDescription();
    void setDescription(String description);

    float getLatitude();
    void setLatitude(float latitude);

    float getLongitude();
    void setLongitude(float longitude);

    String toString();
    // Port getPorts();
    // void setPorts(Port ports[]);
};
#endif