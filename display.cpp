#include "display.h"

U8G2_SH1106_128X64_NONAME_F_HW_I2C display(U8G2_R0, U8X8_PIN_NONE);

void initDisplay() {
  display.begin();
  display.setFont(u8g2_font_6x12_tr);
}

void clearDisplay() {
  display.clearBuffer();
}

void displayUpdate() {
  display.sendBuffer();
}

void drawText(int x, int y, String text, uint8_t size) {
  if (size == 1) display.setFont(u8g2_font_6x12_tr);
  else if (size == 2) display.setFont(u8g2_font_10x20_tr);
  else if (size == 3) display.setFont(u8g2_font_logisoso32_tf);

  display.setCursor(x, y + 12);
  display.print(text);
}

void drawTextCentered(String text, int y, uint8_t size) {
  if (size == 1) display.setFont(u8g2_font_6x12_tr);
  else if (size == 2) display.setFont(u8g2_font_10x20_tr);
  else if (size == 3) display.setFont(u8g2_font_logisoso32_tf);

  int16_t x = (128 - display.getStrWidth(text.c_str())) / 2;
  display.setCursor(x, y + 12);
  display.print(text);
}
