#ifndef PD_ALGORITHM_H
#define PD_ALGORITHM_H

#include <Arduino.h>

class PDAlgorithm
{
  public:
    void init(float P, float D);
    inline void toRegulate(float error);
    void setPredError(float pError) {predError = pError;}
    float getP() {return p;}
    float getValue() {return force;}
    void setPD(float P, float D);
  protected:
    float p;
    float d;
  private:
    float force;
    float predError;
    unsigned long oldTime;
    unsigned long nowTime;
};

#endif
