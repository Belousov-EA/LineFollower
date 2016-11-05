#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

//#define SENSOR_DEBUG


template <typename T, const int sensorCount>
class Sensor 
{
      protected:
        T values [sensorCount];
        int sensors[sensorCount];
      public:
        Sensor(int _sensors[]);
        virtual void init();
        int valueCount()
        {
          return sensorCount;
        }
        T getValue(int num) 
        {
          return values[num];
        }
        T getValue()
        {
          return values[0];
        }
        virtual void read();
        void sensorDebud()
        {
          #ifdef SENSOR_DEBUG
            for (int i = 0; i<sensorCount; i++)
            {
              Serial.print(values[i]);
              Serial.print ('\t');
            }
          #endif
        }
};

#endif
