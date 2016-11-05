#ifndef AIR_MOTORS_H
#define AIR_MOTORS_H

#include <Arduino.h>

class AirMotors
{
  public:
    void init(int lPin, int rPin);
    inline void setPower(float power);
    inline void call();
  private:
    int leftPin;
    int rightPin;
    int leftPower;
    int rightPower;  
};

#endif
