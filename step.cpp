#include "step.h"

Step::Step(int pin, int lowerThreshold, int upperThreshold) {
  this->pin = pin;
  this->lowerThreshold = lowerThreshold;
  this->upperThreshold = upperThreshold;

  this->distance = new DistanceGP2Y0A21YK();
  this->distance->begin(pin);
  this->distance->setARefVoltage(3);
  this->distance->setAveraging(1);
  this->distance->setEnabled(true);

  for (int i = 0; i < NUM_READINGS; i++) {
    this->readings[i] = 255;
  }
}

int Step::Distance() {
  int sum = 0;

  for (int i = 0; i < NUM_READINGS; i++) {
    sum += this->readings[i];
  }

  return sum / NUM_READINGS;
}

boolean Step::Presence() {
  int distance = this->Distance();

  return this->lowerThreshold <= distance && distance <= this->upperThreshold;
}

void Step::Run() {
  for (int i = NUM_READINGS - 1; i > 0; i--) {
    this->readings[i] = this->readings[i - 1];
  }

  this->readings[0] = this->distance->getDistanceCentimeter();

  for (int i = 1; i < NUM_READINGS - 1; i++) {
    if (this->readings[i - 1] == 255 && this->readings[i] != 255 && this->readings[i + 1] == 255) {
      this->readings[i] = 255;
    }
  }
}
