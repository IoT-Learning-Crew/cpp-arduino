// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
#ifndef HEADER_H
#define HEADER_H
#include "Arduino.h"

#define LED_PIN 2
#define SERVO_PIN 17
#define SERIAL_NUMBER 115200

#define MS_500  500
#define MS_1000 1000
#define MS_2000 2000

void blinkPin(int pinNumber);
void blinkTime(int ms);

#endif