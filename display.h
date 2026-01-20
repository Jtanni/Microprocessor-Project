#ifndef DISPLAY_H
#define DISPLAY_H

#include <U8g2lib.h>

extern U8G2_SH1106_128X64_NONAME_F_HW_I2C display;

void initDisplay();
void clearDisplay();
void displayUpdate();
void drawText(int x, int y, String text, uint8_t size);
void drawTextCentered(String text, int y, uint8_t size);

#endif

