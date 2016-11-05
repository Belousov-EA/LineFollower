#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

class Motors
{
  public:
    void init(int lPower, int lDirection, int rPower, int rDirection);
    inline void setPower(float leftP, float rightP);
    inline void call();
  private:
    int leftPowerPin;
    int leftDirectionPin;
    int rightPowerPin;
    int rightDirectionPin;
    int leftPower;
    int rightPower;
    bool leftDirection;
    bool rightDirection;
};

#endif
