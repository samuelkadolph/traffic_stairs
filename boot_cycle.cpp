#include "boot_cycle.h"

BootCycle::BootCycle(int ledPin, Light * topLight, Light * bottomLight) {
  this->BottomLight = bottomLight;
  this->Duration = 3000;
  this->LEDInterval = 250;
  this->LEDPin = ledPin;
  this->LightsInterval = 500;
  this->TopLight = topLight;
}


boolean BootCycle::Run() {
  unsigned long now = millis();

  if (this->startedAt == 0) {
    this->startedAt = now;
  }

  if ((now - this->startedAt) > this->Duration) {
    digitalWrite(this->LEDPin, HIGH);

    this->TopLight->Off();
    this->BottomLight->Off();

    return true;
  }

  if ((now - this->ledCycledAt) > this->LEDInterval) {
    this->ledCycledAt = now;

    digitalWrite(this->LEDPin, this->ledState = ledState == LOW ? HIGH : LOW);
  }

  if ((now - this->lightsCycledAt) > this->LightsInterval) {
    this->lightsCycledAt = now;

    this->TopLight->SetState(this->TopLight->State == Light::WALK ? Light::STOP : Light::WALK);
    this->BottomLight->SetState(this->BottomLight->State == Light::WALK ? Light::STOP : Light::WALK);
  }

  return false;
}

void BootCycle::Setup() {
}
