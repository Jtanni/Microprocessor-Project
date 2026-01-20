#include <Arduino.h>
#include "power.h"
#include "config.h"

void initPower() {
  pinMode(BATTERY_PIN, INPUT);
}

int getBatteryPercent() {
  int raw = analogRead(BATTERY_PIN);
  float voltage = (raw / 4095.0) * 3.3 * 2;  // Voltage divider
  int percent = map(voltage * 100, 330, 420, 0, 100);
  percent = constrain(percent, 0, 100);
  return percent;
}

