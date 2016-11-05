#include "AirMotors.h"

void AirMotors::init(int lPin, int rPin)
{
  leftPin = lPin;
  rightPin = rPin;
}

void AirMotors::setPower(float power)
{
  if(power>0)
  {
    leftPower = constrain(abs(power*255),0,255);
    rightPower = 0;
  }else
    {
      leftPower = 0;
      rightPower = constrain(abs(power*255),0,255);
    }
}


void AirMotors::call()
{
  analogWrite(leftPin, leftPower);
  analogWrite(rightPin, rightPower);
}


