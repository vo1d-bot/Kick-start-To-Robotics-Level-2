#include "wireless.h"
#define BAUD_RATE 9600


void setup() {
  Serial.begin(BAUD_RATE);
  initWiFi();
}

void loop() {
  if(WiFi.status() == WL_CONNECTED) {
    blink(1);
  }
  else if (WiFi.status() != WL_CONNECTED) {
    blink(0);
  }
  delay(5000);
}
