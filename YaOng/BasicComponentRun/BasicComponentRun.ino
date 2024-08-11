// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
// BasicComponentRun.ino
// #include "header.h"
#include "oledU8g2.h"
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);
// Servo servo1;
void setup() {
  // Serial.begin(SERIAL_NUMBER);
  // pinMode(LED_PIN, OUTPUT);
  // servo1.attach(SERVO_PIN);
  // pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  // pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  // pinMode(ISD_REC_PIN, OUTPUT);
  // pinMode(ISD_PLAY_E_PIN, OUTPUT);
  // printISDGuide();
  u8g2.begin();
  u8g2.enableUTF8Print();
}

void loop() {
  drawTextPage(u8g2, "helllll");
  drawBitmapPage(u8g2, gotg_glass);
  drawBitmapPage(u8g2, gotg_card);
}
