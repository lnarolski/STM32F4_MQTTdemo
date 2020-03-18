// TESTED ON ESP32 Dev Module

#define RXD2 16
#define TXD2 17

#include <WiFi.h>
#include "MQTToverSerial.h"

const char* ssid     = "SSID";
const char* password = "PASSWORD";

WiFiClient wifiClient;

MQTToverSerial* mqttClient;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("INFO$Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
  }

  Serial.println("INFO$WiFi connected");
  Serial.print("INFO$IP address: ");
  Serial.println(WiFi.localIP());

  mqttClient = new MQTToverSerial(wifiClient, Serial2, "192.168.2.1", 1883, "", "", "ESP32-MQTToverSerial", &Serial);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial2.available())
    mqttClient->ReadSerial();
  mqttClient->Loop();
}
