
// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
#ifndef OLEDU8G2_H
#define OLEDU8G2_H
#include "Arduino.h"
#include "U8g2lib.h"
// for SPI
#include "SPI.h"
// for img
#include "gotg_glass.h"
#include "gotg_card.h"
// for using Korean NanumGothicCoding font
//#include "u8g2_font_unifont_t_korean_NanumGothicCoding_16.h"
// 참고 블로그 : https://stemwith.github.io/2021/09/26/ESP32-OLED/
// Please UNCOMMENT one of the contructor lines below
// U8g2 Contructor List (Frame Buffer)
// The complete list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
// Please update the pin numbers according to your setup. Use U8X8_PIN_NONE if the reset pin is not connected

// for HW_SPI (VSPI)
// U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 5, /* dc=*/ 14, /* reset=*/ 15);
// for SW_SPI
//U8G2_SH1106_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 26, /* data=*/ 25, /* cs=*/ 5, /* dc=*/ 14, /* reset=*/ 15);
// for SSD1306, I2C, (ESP32: SDA 21, SCL 22) = D21  D22
// U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
// for SH1106,  I2C, (ESP32: SDA 21, SCL 22)
//U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// 폰트 리스트 :https://github.com/olikraus/u8g2/wiki/fntlist16
// 온라인 비트맵 배열 생성기 : https://javl.github.io/image2cpp/
void drawBitmapPage(U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2, const unsigned char*bitmap);
void drawTextPage(U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2, char *text);
#endif