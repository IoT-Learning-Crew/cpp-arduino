// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
#include <ESP32Servo.h>

// #define SERVO_PIN 25

static const int servoPin = 25;

Servo servo1;

void setup() {
  Serial.begin(115200);
  servo1.attach(servoPin);
}

void loop() {
  int posDegrees = 0;

  for(posDegrees; posDegrees <= 180; posDegrees++) {
    servo1.write(posDegrees);
    delay(20);
  }
  Serial.println(posDegrees);

  for(posDegrees = 180; posDegrees >= 0; posDegrees--) {
    servo1.write(posDegrees);
    delay(20);
  }
  Serial.println(posDegrees);

}