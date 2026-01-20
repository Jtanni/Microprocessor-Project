#include <Arduino.h>
#include "face_health.h"
#include "display.h"
#include "max30102.h"
#include "mpu6050.h"

void drawFaceHealth() {
  clearDisplay();

  int hr = getHeartRate();
  int spo2 = getSpO2();
  long steps = getStepCount();

  drawText(0, 0, "HR: " + String(hr) + " bpm", 1);
  drawText(0, 16, "SpO2: " + String(spo2) + "%", 1);
  drawText(0, 32, "Steps: " + String(steps), 1);
  drawTextCentered("Hold SELECT to reset", 54, 1);

  displayUpdate();
}
