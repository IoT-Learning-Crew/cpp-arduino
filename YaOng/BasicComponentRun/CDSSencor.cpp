// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
// CDSSencor.cpp
#include "header.h"

float quantityOfLightCDS() {
  delay(MS_20);
  float light = 0;
  light = analogRead(CDS_ANALOG_PIN);
  return light;
}

void printLight(){
  Serial.print("Quantity of Light : ");
  Serial.println(quantityOfLightCDS());
  return;
}

void lightLEDIfLightCDS(){
  long distance = quantityOfLightCDS();
  if(distance > 3000){
      digitalWrite(LED_PIN, HIGH);
  }
  else{
    digitalWrite(LED_PIN, LOW);
  }
} 
