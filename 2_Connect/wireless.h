#pragma once
#include <WiFi.h>

const char* ssid = "SSID";
const char* password = "PASSWORD";

void initWiFi();
void blink(int sig);

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println();
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
}

void blink(int sig) {
  switch(sig) {
    case 1 :
      Serial.print("Connected to ");
      Serial.println(ssid);
      break;
    case 0 :
      Serial.println("Disconnected");
      WiFi.reconnect();
      delay(100);
      break;
  }
}
