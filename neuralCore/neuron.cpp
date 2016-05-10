#include "neuron.h"
#include <math.h>

Neuron::Neuron(int dimenCont, int *sizes, QObject *parent) : QObject(parent)
{
    if(dimenCont!=0 &&  sizes != NULL)
        setSize(new Vector(dimenCont,sizes));
}

Neuron::~Neuron()
{
    delete myltidimensionOperation;
    delete weigth;
    delete errors ;
    delete lastIn;
    delete lastInOffset;
}

double Neuron::calcFiled(Vector *inputSize,double *input,const Vector *offset)
{
    lastIn = input;
    lastInOffset = offset;
    if(myltidimensionOperation == NULL){
        myltidimensionOperation = new MyltidimensionOperation(size,inputSize);
    }
    if(offset!=NULL){
        myltidimensionOperation->setOffsetPoint(offset->getDimenSizes());
    }
    currentSumm = myltidimensionOperation->calc(input,weigth,sumFun)+weigth[size->getLinerLength()]*1;
    currentSignal =activationFunction(currentSumm);
    return currentSignal;
}

void Neuron::setSize(Vector *size){
    this->size  = size;
    int weigthLenth = size->getLinerLength();
    weigth = new double[weigthLenth+1];
    errors = new double[weigthLenth];
    for(int i=0;i<weigthLenth+1;i++){
        weigth[i] = Util::getInstance().myRand();
        qDebug()<<weigth[i];
    }
}

double *Neuron::calculateError(double error)
{
    return NULL;
}
