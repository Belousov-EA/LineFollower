#include "AirMotors.h"
#include "Algorithm.h"
#include "ExcFarSensor.h"
#include "Motors.h"
#include "Sensor.h"

const int sensorCount = 8;

int nearSensors[sensorCount] = {0, 1, 2, 3, 4, 5, 6, 7};
int nearWeight[sensorCount] = {1, 1, 1, 1, 1, 1, 1, 1};
int nearWhite[sensorCount] = {1, 1, 1, 1, 1, 1 ,1, 1};
int nearBlack[sensorCount] = {1, 1, 1, 1, 1, 1, 1, 1};

int farSensors[sensorCount] = {0, 1, 2, 3, 4, 5, 6, 7};
int farWeight[sensorCount] = {1, 1, 1, 1, 1, 1, 1, 1};
int farWhite[sensorCount] = {1, 1, 1, 1, 1, 1, 1, 1};
int farBlack[sensorCount] = {1, 1, 1, 1, 1, 1, 1, 1};

float p = 1.00;
float d = 1.00;
float maxSpeed = 0.5;
float ps = 0.1;

float speed;
float reg;

int csPin=0;
int clockPin = 1;
int mosiPin =2;
int misoPin = 3;

AirMotors air;
Algorithm alg;
ExcFarSensor albedoExcFar(farSensors, csPin, clockPin, mosiPin, misoPin);
Motors motors;
Sensor<int, 8> albedoExcNear(nearSensors);

void setup() 
{
  air.init(0, 1);
  motors.init(0, 1, 2, 3);
  alg.nearExc.init(&albedoExcNear, sensorCount, nearWeight, nearWhite, nearBlack);
  alg.farExc.init(&albedoExcFar, sensorCount, farWeight, farWhite, farBlack);
  alg.pd.init(p, d);
  
}

void loop() 
{
  alg.nearExc.compute();
  alg.farExc.compute();
  alg.vozvrat.setValues(alg.nearExc.getValue(), alg.nearExc.getDark());
  if(alg.nearExc.getDark()!= 0)
  {
    if(alg.farExc.getDark()!=0)
    {
      speed = maxSpeed - ps*abs(alg.farExc.getValue());
    }else
    {
      speed = maxSpeed - ps;
    }
    alg.pd.toRegulate(alg.nearExc.getValue());
    reg = alg.pd.getValue();
  }else
  if(alg.farExc.getDark()!=0)
  {
    alg.pd.toRegulate(alg.farExc.getValue());
    reg = alg.pd.getValue();
    speed = maxSpeed - ps;
  }else
  {
    if(alg.vozvrat.lineLosted())
    {
      if(alg.vozvrat.getLastExc()>0.00)
      {
        alg.pd.setPredError(1.00);
        reg = alg.pd.getP();
      }else
      {
        alg.pd.setPredError(-1.00);
        reg = -alg.pd.getP();
      }
    }
  }
  motors.setPower(speed*(1+reg), speed*(1-reg));
  air.setPower(reg);
  motors.call();
  air.call();
}





