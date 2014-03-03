#ifndef _BOOT_CYCLE_H_
#define _BOOT_CYCLE_H_

#include "Arduino.h"
#include "light.h"

class BootCycle {
public:
  Light * BottomLight;
  long Duration;
  long LEDInterval;
  int LEDPin;
  long LightsInterval;
  Light * TopLight;

  BootCycle(int ledPin, Light * topLight, Light * bottomLight);

  boolean Run();
  void Setup();

private:
  unsigned long ledCycledAt = 0;
  int ledState = LOW;
  unsigned long lightsCycledAt = 0;
  unsigned long startedAt = 0;
};

#endif
