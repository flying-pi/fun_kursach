#include "util.h"


Util::Util()
{
    //init random
    //    std::mt19937 rand_engine(rand_dev());
    randomEngine =  std::default_random_engine(randomDevice());;
    uniform_dist = std::uniform_int_distribution<double>(downRandom, upRandom);
}

double Util::myRand()
{
    return uniform_dist(randomEngine)/upRandom;
}



MyltidimensionOperation::MyltidimensionOperation(Vector *summatorSize, Vector *inputSize)
{
    Q_ASSERT(summatorSize->getDimensCount()==inputSize->getDimensCount());
    this->inputSize = inputSize;
    this->summatorSize = summatorSize;
    this->dimenCount = summatorSize->getDimensCount();
    axisOffset = new int[dimenCount];
    inputAxisOffset = new int[dimenCount];
    axisOffset[0] = (*summatorSize)[0];
    inputAxisOffset[0] = (*inputSize)[0];
    for(int i=1;i<dimenCount;i++){
        axisOffset[i] = axisOffset[i-1]*(*summatorSize)[i];
        inputAxisOffset[i] = inputAxisOffset[i-1]*(*inputSize)[i];
    }
    int *tempOffsetPoint = new int[dimenCount];
    for(int i=0;i<dimenCount;i++)
        tempOffsetPoint[i] = 0;
    offsetPoint = tempOffsetPoint;
}
