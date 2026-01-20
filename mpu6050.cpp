#include <Arduino.h>
#include "mpu6050.h"

long steps = 0;

void initMPU() {}

long getStepCount() {
  steps++;  // dummy increment
  return steps;
}

void resetStepCount() {
  steps = 0;
}
