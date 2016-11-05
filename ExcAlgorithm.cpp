#include "ExcAlgorithm.h"

void ExcAlgorithm::init(Sensor<int, 8>*_excSensor, int _sensorCount, int _weight[], int _white[], int _black[])
{
  this -> excSensor = _excSensor;
  sensorCount = _sensorCount;
  weight = new int [sensorCount];
  white = new int [sensorCount];
  black = new int [sensorCount];
  linePro = new float [sensorCount];
  
  for (int i=0; i<sensorCount; i++)  
  {
    weight[i] = _weight[i];
    white[i]=_white[i];
    black[i]=_black[i];
  }
}

void ExcAlgorithm::compute()
{
  dark = 0;
  value = 0;
  excSensor -> read();
  int perehod = 0;
  for(int i = 0; i<excSensor -> valueCount(); i++)
  {
    if (excSensor -> getValue(i)>black[i])
    {
      linePro[i] = 1;
    }else if(excSensor -> getValue(i)<white[i])
    {
      linePro[i] = 0;
    }else
    {
      linePro[i]=float(excSensor -> getValue(i)-white[i])/float(black[i]-white[i]);
      linePro[i]=constrain(linePro[i],0,1);
    }
  }

   for (int i = 0; i<sensorCount; i++)
  {
    value+=weight[i]*linePro[i];
    dark+=linePro[i];
    if(i>0)
    {
      if(abs(linePro[i]-linePro[i-1])>0.7)
      {
        perehod++;
      }
    }
  }


  if ((dark>0)&&(perehod<3))
  {
    value/=(dark*sensorCount/2);
  }else
  {
    value=0;
  }
}

float ExcAlgorithm::getDark()
{
  return dark;
}

float ExcAlgorithm::getValue()
{
  return value;
}

