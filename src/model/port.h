#ifndef PORT_H
#define PORT_H
#include <Arduino.h>

class Port
{

private:
    String id;

private:
    String cabinetid;

private:
    int analogpin;

private:
    int digitalpin;

public:
    Port(String id, String cabinetid, int analogpin, int digitalpin);
    void init();
    String getId();
    void setId(String id);
    String getCabinetid();
    void setCabinetid(String cabinetid);
    int getAnalogpin();
    void setAnalogpin(int analogpin);
    int getDigitalpin();
    void setDigitalpin(int digitalpin);
    String toString();
};
#endif