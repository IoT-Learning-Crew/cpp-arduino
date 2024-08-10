// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
// ledBlink.cpp
#include "header.h"
/*
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
*/
int distanceUseUltrasonic() {
  long duration, distance;
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delay(MS_10);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);  // 반사되어 돌아온 초음파 시간(us)
  // puseIn : echo pin의 high 유지시간.
  distance = ((34000*duration)/1000000)/2;  // 편도 (cm)
  // 초음파(소리)의 속도 - 340m/s.
  // 1us당 cm단위로 변환한하다.
  delay(MS_20);
  return distance;
}

void printDistance(){
  long distance = distanceUseUltrasonic();
  Serial.print("DIstance : ");
  Serial.print(distance);
  Serial.println(" Cm");
}

void lightLEDIfCloseDistance(){
  long distance = distanceUseUltrasonic();
  if(distance < 6){
      digitalWrite(LED_PIN, HIGH);
  }
  else{
    digitalWrite(LED_PIN, LOW);
  }
}