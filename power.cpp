#include<Arduino.h>
#include "power.h"
#include "config.h"

void initPower() {
  analogReadResolution(12);  // ESP32 ADC
}

int getBatteryPercent() {
  int raw = analogRead(BATTERY_PIN);
  float voltage = raw * (3.3 / 4095.0) * 2;  // adjust if voltage divider
  int percent = map(voltage * 100, 330, 420, 0, 100);
  percent = constrain(percent, 0, 100);
  return percent;
}
