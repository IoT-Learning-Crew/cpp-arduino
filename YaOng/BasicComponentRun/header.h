// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
#ifndef HEADER_H
#define HEADER_H
#include "Arduino.h"
#include <ESP32Servo.h>

#define SERIAL_NUMBER 115200
#define LED_PIN 14
#define SERVO_PIN 17
#define ULTRASONIC_TRIG_PIN 25  // 초음파를 보내는 핀
#define ULTRASONIC_ECHO_PIN 26  // 초음파를 받는 핀
#define CDS_ANALOG_PIN A6 //D34
#define ISD_REC_PIN 2
#define ISD_PLAY_E_PIN 4

#define MS_10  10
#define MS_20  20
#define MS_500  500
#define MS_1000 1000
#define MS_2000 2000
#define S_5 5000
#define S_10 10000

extern Servo servo1;

// LED
void blinkPin(int pinNumber);
void blinkTime(int ms);
// 서보모터
void rotateServo(int maxAngle);
// Ultrasonic 초음파센서
void printDistance();
void lightLEDIfCloseDistance();
int distanceUseUltrasonic();
// CDS 조도센서
float quantityOfLightCDS();
void printLight();
void lightLEDIfLightCDS();
// ISD1820 사운드 녹음 모듈
void listenSerialISDCommend();
void printISDGuide();
void recordISD();
void playISD();
#endif