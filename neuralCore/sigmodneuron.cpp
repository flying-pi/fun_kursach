#include "sigmodneuron.h"

SigmodNeuron::SigmodNeuron(int dimenCont, int *sizes, QObject *parent) : Neuron(dimenCont,sizes,parent)
{

}

double SigmodNeuron::activationFunction(double in)
{
    return 1.0/(1+exp(k*in));
}

void SigmodNeuron::calculateError(double error)
{
    double sigma = -k*currentSignal*(1-currentSignal)*error * learnSpeed;
    myltidimensionOperation->calc(lastIn,weigth,increaceW,sigma);
    weigth[size->getLinerLength()]+=sigma;
    sigma;
}
