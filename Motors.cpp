#include "Motors.h"

void Motors::init(int lPower, int lDirection, int rPower, int rDirection)
{
  leftPowerPin = lPower;
  leftDirectionPin = lDirection;
  rightPowerPin = rPower;
  rightDirectionPin = rDirection;
}


void Motors::setPower(float leftP, float rightP)
{
  leftDirection =  leftP>0?0:1;
  leftPower =  constrain(abs(leftP*255), 0, 255);
  rightDirection = rightP>0?0:1;
  rightPower =  constrain(abs(rightP*255), 0, 255);
}

void Motors::call()
{
  digitalWrite(leftDirectionPin, leftDirection);
  analogWrite(leftPowerPin, leftPower);
  digitalWrite(rightDirectionPin, rightDirection);
  analogWrite(rightPowerPin, rightPower);
}



