#include <Wire.h>
#include <U8g2lib.h>
#include "faces.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);

int currentFace = 0;
const int totalFaces = 3;

void setup() {
  Wire.begin();
  u8g2.begin();
  setupButtons();
}

void loop() {
  updateButtons();

  if (nextShort) {
    currentFace = (currentFace + 1) % totalFaces;
  }

  if (nextLong) {
    // Open settings later
  }

  if (nextDouble) {
    // Shortcut (health / GPS)
  }

  u8g2.clearBuffer();
  drawDigitalFace();
  u8g2.sendBuffer();
}


