// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
// recordPlayISD1820.cpp
#include "header.h"

void printISDGuide(){
  Serial.println("*****guide*****");
  Serial.println("1. record 5 second");
  Serial.println("2. play all");

}

void listenSerialISDCommend(){
  int command;
  while(Serial.available()){
    command = (int)Serial.read();
    switch(command){
      case '1':
        Serial.println("Recording 5s...");
        recordISD();
        Serial.println("Recording finished");
        break;
      case '2':
        Serial.println("Play~~~");
        playISD();
        Serial.println("Play finished");
        break;
    }
  }
}
void recordISD(){
  digitalWrite(ISD_REC_PIN, HIGH);
  delay(S_5);
  digitalWrite(ISD_REC_PIN, LOW);
}
void playISD(){
  digitalWrite(ISD_PLAY_E_PIN, HIGH);
  delay(MS_500);
  digitalWrite(ISD_PLAY_E_PIN, LOW);
}