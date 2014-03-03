#include "gate.h"

Gate::Gate(Step ** steps, int stepsCount) {
  this->steps = steps;
  this->stepsCount = stepsCount;
}

boolean Gate::Presence() {
  return this->presence;
}

int Gate::Count() {
  return this->counter;
}

void Gate::Run() {
  for (int n = 0; n < this->stepsCount; n++) {
    this->steps[n]->Run();
  }

  this->presence = false;
  for (int n = 0; n < this->stepsCount; n++) {
    if (this->steps[n]->Presence()) {
      this->presence = true;
    }
  }
}
