#include "scan.h"
#define BAUD_RATE 9600

void setup() {
  Serial.begin(BAUD_RATE);
}

void loop() {
  initScan();
}
