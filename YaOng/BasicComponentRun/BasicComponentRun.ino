// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
// BasicComponentRun.ino
#include "header.h"

Servo servo1;

void setup() {
  Serial.begin(SERIAL_NUMBER);
  pinMode(LED_PIN, OUTPUT);
  servo1.attach(SERVO_PIN);
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);

}

void loop() {
  lightLEDIfLightCDS();
}
