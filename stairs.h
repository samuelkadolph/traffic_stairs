#ifndef _STAIRS_H_
#define _STAIRS_H_

#include "gate.h"
#include "light.h"

#define LIGHT_TRIPPED_DURATION 6000

class Stairs {
public:
  Gate * BottomGate;
  Light * BottomLight;
  Gate * TopGate;
  Light * TopLight;

  boolean Run();
  void Setup();

private:
  unsigned long bottomTrippedAt;
  unsigned long topTrippedAt;
};

#endif
