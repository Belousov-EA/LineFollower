#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "ExcAlgorithm.h"
#include "PDAlgorithm.h"
#include "ReturnOnLine.h"

class Algorithm
{
  public:
    void compute();
    ExcAlgorithm nearExc;
    ExcAlgorithm farExc;
    PDAlgorithm pd;
    ReturnOnLine vozvrat;
};

#endif
