#include "PDAlgorithm.h"

void PDAlgorithm::toRegulate(float error)
{
  nowTime = millis();
  float reg = error*p+(error - predError)*d/(nowTime-oldTime);
  predError = error;
  oldTime = nowTime;
  force = reg;
}

void PDAlgorithm::init(float P, float D)
{
  p = P;
  d = D;
  predError = 0.00;
}

void PDAlgorithm::setPD(float P, float D)
{
  p = P;
  d = D;
}

