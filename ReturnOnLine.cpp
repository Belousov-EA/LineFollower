#include "ReturnOnLine.h"

void ReturnOnLine::setValues(float exc, float dark)
{
  if(dark>0)
  {
    darkCount = 0;
    lastExc = exc;
  } else
    {
      darkCount++;
    }
}


bool ReturnOnLine::lineLosted()
{
  if(darkCount>3)
  {
    return true;
  }
    else
    {
      return false;
    }
}

float ReturnOnLine::getLastExc()
{
  return lastExc;
}

