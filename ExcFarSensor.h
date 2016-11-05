#ifndef EXC_FAR_SENSOR_H
#define EXC_FAR_SENSOR_H

#include "Sensor.h"
#include "MCP3008.h"

class ExcFarSensor : public Sensor<int, 8>
{
  public:
    ExcFarSensor(int _sensors[], int csPin, int clockPin, int mosiPin, int misoPin);
    void virtual read()
    {
      for(int i = 0; i<8; i++)
      {
        values[i] = adc.readADC(sensors[i]);
      }
    }
  private:
    MCP3008 adc;
    
    
};
#endif
