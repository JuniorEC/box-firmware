#include "port.h"

Port::Port(String id, String cabinetid, int analogpin, int digitalpin)
{

  this->id = id;
  this->cabinetid = cabinetid;
  this->analogpin = analogpin;
  this->digitalpin = digitalpin;

  init();
}
void Port::init()
{
  // Always try to avoid duplicate code.
  // Instead of writing digitalWrite(pin, LOW) here,
  // call the function off() which already does that
}

String Port::getId()
{
  return this->id;
}

void Port::setId(String id)
{
  this->id = id;
}

String Port::getCabinetid()
{
  return this->cabinetid;
}

void Port::setCabinetid(String cabinetid)
{
  this->cabinetid = cabinetid;
}

int Port::getAnalogpin()
{
  return this->analogpin;
}

void Port::setAnalogpin(int analogpin)
{
  this->analogpin = analogpin;
}

int Port::getDigitalpin()
{
  return this->digitalpin;
}

void Port::setDigitalpin(int digitalpin)
{
  this->digitalpin = digitalpin;
}

String Port::toString() {
  return String("{\"id\": \"") + String(this->id) +
         String("\",\"armario\": \"") + String(this->cabinetid) +
         String("\",\"analogpin\": \"") + String(this->analogpin) +
         String("\",\"digitalpin\": \"") + String(this->digitalpin) +
         String("\"}");
}
