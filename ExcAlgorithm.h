#ifndef EXC_ALGORITHM_H
#define EXC_ALGORITHM_H

#include "Sensor.h"

class ExcAlgorithm
{
  public:
    void init(Sensor<int, 8>*_excSensor, int _sensorCount, int _weight[], int _white[], int _black[]);
    void compute();
    float getDark();
    float getValue();
  private:
    Sensor<int, 8> *excSensor;
    int sensorCount;
    float dark;
    int *weight;
    int *white;
    int *black;
    float *linePro;
    float value;
};

#endif
