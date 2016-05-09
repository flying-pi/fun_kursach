#include "neuron.h"
#include <math.h>

Neuron::Neuron(int dimenCont, int *sizes, QObject *parent) : QObject(parent)
{
    if(dimenCont!=0 &&  sizes != NULL)
        setSize(new Vector(dimenCont,sizes));
}

double Neuron::calcFiled(Vector *inputSize,double *input,const Vector *offset)
{
    if(myltidimensionOperation == NULL){
        myltidimensionOperation = new MyltidimensionOperation(size,inputSize);
    }
    if(offset!=NULL){
        myltidimensionOperation->setOffsetPoint(offset->getDimenSizes());
    }
    currentSumm = myltidimensionOperation->calc(input,weigth,sumFun);
    currentSignal = 1.0/(1+exp(currentSumm));
    return currentSignal;
}

void Neuron::setSize(Vector *size){
    this->size  = size;
    int weigthLenth = size->getLinerLength();
    weigth = new double[weigthLenth];
    for(int i=0;i<weigthLenth;i++)
        weigth[i] = Util::getInstance().myRand();
}
