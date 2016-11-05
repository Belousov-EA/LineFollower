#include "ExcFarSensor.h"

ExcFarSensor::ExcFarSensor(int _sensors[], int csPin, int clockPin, int mosiPin, int misoPin)
    :adc(clockPin, mosiPin, misoPin, csPin),
    Sensor<int, 8>(_sensors)
    {
      
    }
