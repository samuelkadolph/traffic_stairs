#ifndef _LIGHT_H_
#define _LIGHT_H_

class Light {
public:
  enum StateEnum {
    OFF,
    WALK,
    STOP
  };

  StateEnum State;

  Light(int walkPin, int stopPin);

  void Off();
  void SetState(Light::StateEnum state);
  void Setup();
  void Stop();
  void Walk();

private:
  int stopPin;
  int walkPin;
};

#endif
