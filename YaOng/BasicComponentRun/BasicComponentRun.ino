// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
// BasicComponentRun.ino
#include "header.h"

// Servo servo1;
WiFiServer server(80);

void setup() {
  Serial.begin(SERIAL_NUMBER);
  
  pinMode(LED_PIN, OUTPUT);
  // servo1.attach(SERVO_PIN);
  // pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  // pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  // pinMode(ISD_REC_PIN, OUTPUT);
  // pinMode(ISD_PLAY_E_PIN, OUTPUT);
  // printISDGuide();


  // connectWifiSTA();
  setWifiAp();
  server.begin();

}

void loop() {
  WiFiClient client = server.available();  // listen for incoming clients
  listenClient(client);
}
