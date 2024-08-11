// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
// OLEDSsd1306.cpp
#include "oledU8g2.h"

/*
  global : 
    U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

  setup :
  u8g2.begin();
  u8g2.enableUTF8Print();  // enable UTF8 support for the Arduino print() function
*/


void drawTextPage(U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2, char *text){
    u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0, 15, text);
    u8g2.setFont(u8g2_font_unifont_t_korean2);
    u8g2.setCursor(0, 50);
    u8g2.print("안녕하세요");
    u8g2.setFont(u8g2_font_unifont_t_symbols);
    u8g2.drawUTF8(80, 50, ">v< ☃");
  } while (u8g2.nextPage());
  delay(1000);
}
void drawBitmapPage(U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2, const unsigned char*bitmap){
  u8g2.firstPage();
  do {
    u8g2.drawBitmap(0, 0, 16, 64, bitmap);
  } while (u8g2.nextPage());
  delay(1000);
}