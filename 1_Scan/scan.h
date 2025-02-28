#pragma once
#include <WiFi.h>

bool flag = true;

void initScan() {
  if(flag) {
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    Serial.println("Setup Completed");
    flag = false;
  }

  Serial.println("Initializing Scan....");
  int totalNetworks = WiFi.scanNetworks();

  if(totalNetworks == 0) {
    Serial.println("no networks found");
  }
  else {
    Serial.print(totalNetworks);
    Serial.println(" networks found");
    for(int i = 0; i < totalNetworks; i++) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
      delay(10);
    }
  }

  Serial.println();

  // Wait a bit before scanning again
  delay(5000);
}