#ifndef _STEP_H_
#define _STEP_H_

#define NUM_READINGS 10

#include "Arduino.h"
#include "DistanceGP2Y0A21YK.h"

class Step {
public:
  Step(int pin, int lowerThreshold, int upperThreshold);

  int Distance();
  boolean Presence();
  void Run();

  DistanceGP2Y0A21YK * distance;
private:
  int lowerThreshold;
  int pin;
  long presenceStarted;
  int readings[NUM_READINGS];
  int upperThreshold;
};

#endif
