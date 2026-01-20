#include <Arduino.h>
#include "face_time.h"
#include "display.h"
#include "rtc.h"
#include "power.h"
#include "gps.h"

void drawFaceTime() {
  clearDisplay();

  // Fetch data
  String dateStr = getDateString();       // e.g. 20-01-2026
  String timeStr = getTimeString();       // e.g. 14:35:09
  int battery = getBatteryPercent();      // e.g. 87%
  String location = getLocationString();  // e.g. "Chittagong"

  // -----------------------
  // DATE - small, top, centered
  // -----------------------
  drawTextCentered(dateStr, 0, 1);

  // -----------------------
  // TIME - big, bold, one line, centered
  // -----------------------
  drawTextCentered(timeStr, 20, 3);   // y = 20 to leave space for date

  // -----------------------
  // BATTERY - top-right corner
  // -----------------------
  drawText(96, 0, String(battery) + "%", 1);

  // -----------------------
  // LOCATION - below time, centered
  // -----------------------
  drawTextCentered(location, 50, 1);   // y = 50 for bottom spacing

  displayUpdate();
}
