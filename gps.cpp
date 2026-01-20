#include "gps.h"
#include <TinyGPSPlus.h>
#include <HardwareSerial.h>

TinyGPSPlus gps;
HardwareSerial gpsSerial(1);

void initGPS() {
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);  // RX, TX
}

String getLocationString() {
  if (gps.location.isValid()) {
    return "Lat:" + String(gps.location.lat(), 2) + " Lon:" + String(gps.location.lng(), 2);
  }
  return "Loc: --";
}
