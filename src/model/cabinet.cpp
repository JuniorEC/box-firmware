#include "cabinet.h"
// #include "port.h"

Cabinet::Cabinet(String id, byte hash, bool active, bool available, bool isPrivate, String description, float latitude, float longitude/*, Port ports*/) {
  this->id = id;
  this->hash = hash;
  this->active = active;
  this->available = available;
  this->isPrivate = isPrivate;
  this->description = description;
  this->latitude = latitude;
  this->longitude = longitude;
//   this->ports = ports;
  init();
}
void Cabinet::init() {
  // Always try to avoid duplicate code.
  // Instead of writing digitalWrite(pin, LOW) here,
  // call the function off() which already does that
}

String Cabinet::getId() {
  return this->id;
}

void Cabinet::setId(String id) {
  this->id = id;
}

byte Cabinet::getHash() {
  return this->hash;
}

void Cabinet::setHash(byte hash) {
  this->hash = hash;
}

bool Cabinet::getActive() {
  return this->active;
}

void Cabinet::setActive(bool active) {
  this->active = active;
}

bool Cabinet::getAvailable() {
  return this->available;
}

void Cabinet::setAvailable(bool available) {
  this->available = available;
}

bool Cabinet::getIsPrivate() {
  return this->isPrivate;
}

void Cabinet::setIsPrivate(bool isPrivate) {
  this->isPrivate = isPrivate;
}

String Cabinet::getDescription() {
  return this->description;
}

void Cabinet::setDescription(String description) {
  this->description = description;
}

float Cabinet::getLatitude() {
  return this->latitude;
}

void Cabinet::setLatitude(float latitude) {
  this->latitude = latitude;
}

float Cabinet::getLongitude() {
  return this->longitude;
}

void Cabinet::setLongitude(float longitude) {
  this->longitude = longitude;
}

String Cabinet::toString() {
  return String("{\"id\":") + String(this->id) +
         String("\",\"hash\":\"") + String(this->hash) +
         String("\",\"active\":\"") + String(this->active) +
         String("\",\"available\":\"") + String(this->available) +
        //  String(",\"isPrivate\":") + String(this->isPrivate) +
        //  String(",\"description\":") + String(this->description) +
        //  String(",\"latitude\":") + String(this->latitude) +
        //  String(",\"longitude\":") + String(this->longitude) +
         String("\"}");
}
// Port Cabinet::getPorts() {
//   return this->ports[];
// }

// void Cabinet::setPorts(Port ports[]) {
// //   this->ports = ports;
// }
