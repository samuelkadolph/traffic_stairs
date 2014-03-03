#include "stairs.h"

boolean Stairs::Run() {
  delay(20);

  unsigned long now = millis();

  this->TopGate->Run();
  this->BottomGate->Run();

  // draft logic
  // if (this->TopGate->Presence() && this->BottomGate->Presence()) {
  //   // top and bottom gates detected someone
  //   this->TopLight->Stop();
  //   this->BottomLight->Stop();
  // } else if (this->BottomGate->Count() == 0 && this->TopGate->Presence()) {
  //   // no one entered bottom gate and top gate detected someone
  //   this->TopLight->Walk();
  //   this->BottomLight->Stop();
  // } else if (this->TopGate->Count() == 0 && this->BottomGate->Presence()) {
  //   // no one entered top gate and bottom gate detected someone
  //   this->TopLight->Stop();
  //   this->BottomLight->Walk();
  // } else {
  //   // no one in the stairs
  //   this->TopLight->Walk();
  //   this->BottomLight->Walk();
  // }

  if ((now - this->topTrippedAt) < LIGHT_TRIPPED_DURATION) {
    this->BottomLight->Stop();
  } else {
    this->BottomLight->Walk();

    if (this->BottomGate->Presence()) {
      this->bottomTrippedAt = now;
    }
  }

  if ((now - this->bottomTrippedAt) < LIGHT_TRIPPED_DURATION) {
    this->TopLight->Stop();
  } else {
    this->TopLight->Walk();

    if (this->TopGate->Presence()) {
      this->topTrippedAt = now;
    }
  }

  return false;
}

void Stairs::Setup() {
  this->TopLight->Setup();
  this->BottomLight->Setup();
}
