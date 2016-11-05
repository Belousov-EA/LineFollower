#include "Sensor.h"

template <typename T, int sensorCount>
Sensor<T, sensorCount>::Sensor(int _sensors[])
{
  for (int i = 0; i<sensorCount; i++)
  {
    sensors[i] = _sensors[i];
  }
}

template <typename T, int sensorCount>
void Sensor<T, sensorCount>::read()
{
  for(int i = 0; i<sensorCount; i++)
  {
    values[i] = analogRead(sensors[i]);
  }
}
 

template<typename T, int sensorCount>
void Sensor<T, sensorCount>::init()
{
  
}

