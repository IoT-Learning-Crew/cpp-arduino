// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
// servoMotor.cpp

// ESP32Servo by Kevin ver 3.0.5
#include "header.h"
/*
setup : servo.attach(SERVO_PIN);
*/

void rotateServo(int maxAngle) {
  int degree = 0;

  for(degree; degree <= maxAngle; degree++) {
    servo1.write(degree);
    delay(MS_20);
  }
  Serial.println(degree);

  for(degree = maxAngle; degree >= 0; degree--) {
    servo1.write(degree);
    delay(MS_20);
  }
  Serial.println(degree);

}