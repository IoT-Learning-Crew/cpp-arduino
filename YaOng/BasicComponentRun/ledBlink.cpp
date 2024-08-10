// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
// ledBlink.cpp
#include "header.h"
/*
setup : pinMode(LED_PIN, OUTPUT);
*/
void blinkPin(int pinNumber) {
  digitalWrite(pinNumber, HIGH);
  delay(500);
  digitalWrite(pinNumber, LOW);
  delay(500);
}

void blinkTime(int ms) {
  digitalWrite(LED_PIN, HIGH);
  delay(ms);
  digitalWrite(LED_PIN, LOW);
  delay(ms);
}