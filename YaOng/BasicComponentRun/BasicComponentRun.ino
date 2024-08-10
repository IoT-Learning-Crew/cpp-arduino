// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
// BasicComponentRun.ino
#include "header.h"

Servo servo1;

void setup() {
  Serial.begin(SERIAL_NUMBER);
  pinMode(LED_PIN, OUTPUT);
  pinMode(14, OUTPUT);
  servo1.attach(SERVO_PIN);

}

void loop() {
  blinkTime(MS_1000);
  blinkPin(14);
  rotateServo(90);
}
