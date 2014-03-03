#include "Arduino.h"
#include "light.h"

Light::Light(int walkPin, int stopPin) {
  this->walkPin = walkPin;
  this->stopPin = stopPin;

  this->State = Light::OFF;
}

void Light::Off() {
  this->SetState(OFF);
}

void Light::SetState(Light::StateEnum state) {
  this->State = state;

  digitalWrite(this->stopPin, this->State == STOP ? HIGH : LOW);
  digitalWrite(this->walkPin, this->State == WALK ? HIGH : LOW);
}

void Light::Setup() {
 pinMode(this->stopPin, OUTPUT);
 pinMode(this->walkPin, OUTPUT);

 digitalWrite(this->stopPin, LOW);
 digitalWrite(this->walkPin, LOW);
}

void Light::Stop() {
  this->SetState(STOP);
}

void Light::Walk() {
  this->SetState(WALK);
}
