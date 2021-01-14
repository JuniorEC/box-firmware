#include <Arduino.h>
#include <ArduinoJson.h>

#include "universal-mqtt.h"
#include "model/port.h"
#include "model/cabinet.h"

String cabinet_id = String("1b9gB9oSYonzp498qI5G");
Port *port;
Cabinet *cabinet;

void messageReceived(String &topic, String &payload)
{
  Serial.println("incoming: " + topic + " - " + payload);
  StaticJsonDocument<200> doc;
  // Deserialize the JSON document
  DeserializationError error = deserializeJson(doc, payload.c_str());

  // Test if parsing succeeds.
  if (error)
  {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  if (topic.equals("/devices/" + String(device_id) + "/commands"))
  {
    // TODO
    
  }

  if (topic.equals("/devices/" + String(device_id) + "/config"))
  {
    String id = doc["id"];
    String description = doc["description"];
    byte hash = doc["hash"];
    bool active = doc["active"];
    bool available = doc["available"];
    bool isPrivate = doc["private"];

    float latitude = doc["latitude"];
    float longitude = doc["longitude"];

    cabinet = new Cabinet(id, hash, active, available, isPrivate, description, latitude, longitude);

    port = new Port(id, id, 123, 123);
    
    Serial.println(cabinet->toString());
  }
}

void setup()
{
  // put your setup code here, to run once:
  // TODO: Necessary?
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  setupCloudIoT();
}

unsigned long lastTelemetryMillis = 0;
unsigned long lastStateMillis = 0;

void loop()
{
  mqtt->loop();
  delay(10); // <- fixes some issues with WiFi stability
  mqttClient->onMessage(messageReceived);

  if (!mqttClient->connected())
  {
    connect();
  }

  // publish a message roughly every second.
  // Serial.println((millis() - lastMillis));

  // if (millis() - lastMillis > 100000)
  // {
  //   lastMillis = millis();
  //   Serial.println("publicando...");
  //   publishTelemetry(getDefaultSensor());
  // }

  if (millis() - lastTelemetryMillis > 60000)
  {
    lastTelemetryMillis = millis();
    Serial.println("publicando evento de telemetria...");
    // publishCabinetTelemetry(cabinet->getId(), cabinet->toString());
    publishPortTelemetry(port->getCabinetid(), port->getId(), port->toString());
  }

  if (millis() - lastStateMillis > 900000)
  {
    lastStateMillis = millis();
    Serial.println("publicando device state...");
    publishCabinetState(cabinet->toString());
  }
}