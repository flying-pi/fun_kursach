#include "sigmodneuron.h"

SigmodNeuron::SigmodNeuron(int dimenCont, int *sizes, QObject *parent) : Neuron(dimenCont,sizes,parent)
{

}

double SigmodNeuron::activationFunction(double in)
{
    return 1.0/(1+exp(k*in));
}

double * SigmodNeuron::calculateError(double error)
{
    double sigma = k*currentSignal*(1-currentSignal)*error;
    double wSum=0;
    for(int i=0;i<=size->getLinerLength();i++) wSum+=weigth[i];
    for(int i=0;i<size->getLinerLength();i++)
        this->errors[i] = weigth[i]*sigma/wSum;
    sigma*=learnSpeed;
    myltidimensionOperation->calc(lastIn,weigth,increaceW,sigma);
    weigth[size->getLinerLength()]+=sigma;
    return this->errors;
}
