#ifndef _GATE_H_
#define _GATE_H_

#include "step.h"

class Gate {
public:
  Gate(Step ** steps, int stepsCount);

  int Count();
  boolean Presence();
  void Run();

private:
  int counter;
  boolean presence;
  Step ** steps;
  int stepsCount;
};

#endif
