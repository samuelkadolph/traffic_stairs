#include "boot_cycle.h"
#include "DistanceGP2Y0A21YK.h"
#include "gate.h"
#include "light.h"
#include "stairs.h"
#include "step.h"

enum State {
  BOOTING,
  RUNNING
};

BootCycle * boot;
Light * bottomLight = NULL;
Step * bottomSteps[5] = {};
Stairs * stairs;
State state = BOOTING;
Light * topLight = NULL;
Step * topSteps[5] = {};

void setup() {
  topLight = new Light(0, 1);
  topSteps[0] = new Step(A0, 0, 80);
  topSteps[1] = new Step(A1, 0, 80);
  topSteps[2] = new Step(A2, 0, 80);
  topSteps[3] = new Step(A3, 0, 80);
  topSteps[4] = new Step(A4, 0, 40);

  bottomLight = new Light(2, 3);
  bottomSteps[0] = new Step(A9, 0, 80);
  bottomSteps[1] = new Step(A8, 0, 80);
  bottomSteps[2] = new Step(A7, 0, 80);
  bottomSteps[3] = new Step(A6, 0, 80);
//  bottomSteps[4] = new Step(A5, 0, 80);

  boot = new BootCycle(13, topLight, bottomLight);

  stairs = new Stairs();
  stairs->TopGate = new Gate(topSteps, 5);
  stairs->TopLight = topLight;
  stairs->BottomGate = new Gate(bottomSteps, 4);
  stairs->BottomLight = bottomLight;

  boot->Setup();
  stairs->Setup();

  state = BOOTING;
}

void loop() {
  switch (state) {
    case BOOTING:
      if(boot->Run()) state = RUNNING;
      break;
    case RUNNING:
      stairs->Run();
      Serial.println(String(millis()) + "\t" +
                     String(topSteps[0]->Distance()) + "\t" +
                     String(topSteps[1]->Distance()) + "\t" +
                     String(topSteps[2]->Distance()) + "\t" +
                     String(topSteps[3]->Distance()) + "\t" +
                     String(topSteps[4]->Distance()) + "\t" +
                     String(bottomSteps[3]->Distance()) + "\t" +
                     String(bottomSteps[2]->Distance()) + "\t" +
                     String(bottomSteps[1]->Distance()) + "\t" +
                     String(bottomSteps[0]->Distance()));
      break;
  }
}
