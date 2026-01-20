#include <Arduino.h>
#include "faces.h"

#define LONG_PRESS_TIME 800
#define DOUBLE_PRESS_TIME 350

struct Button {
  uint8_t pin;
  bool lastState;
  unsigned long pressTime;
  unsigned long lastRelease;
  bool waitingDouble;
};

Button btnNext = {BTN_NEXT, HIGH, 0, 0, false};

bool nextShort = false;
bool nextLong = false;
bool nextDouble = false;

void setupButtons() {
  pinMode(BTN_NEXT, INPUT_PULLUP);
}

void updateButtons() {
  nextShort = nextLong = nextDouble = false;

  bool state = digitalRead(btnNext.pin);

  // Pressed
  if (btnNext.lastState == HIGH && state == LOW) {
    btnNext.pressTime = millis();
  }

  // Released
  if (btnNext.lastState == LOW && state == HIGH) {
    unsigned long duration = millis() - btnNext.pressTime;

    if (duration >= LONG_PRESS_TIME) {
      nextLong = true;
      btnNext.waitingDouble = false;
    } else {
      if (btnNext.waitingDouble &&
          millis() - btnNext.lastRelease <= DOUBLE_PRESS_TIME) {
        nextDouble = true;
        btnNext.waitingDouble = false;
      } else {
        btnNext.waitingDouble = true;
        btnNext.lastRelease = millis();
      }
    }
  }

  // Single press timeout
  if (btnNext.waitingDouble &&
      millis() - btnNext.lastRelease > DOUBLE_PRESS_TIME) {
    nextShort = true;
    btnNext.waitingDouble = false;
  }

  btnNext.lastState = state;
}


