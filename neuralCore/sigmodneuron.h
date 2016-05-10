#ifndef SIGMODNEURON_H
#define SIGMODNEURON_H

#include <QObject>
#include "neuron.h"

class SigmodNeuron : public Neuron
{
    Q_OBJECT
public:
    static Neuron *createItem(){
        return new SigmodNeuron();
    }

    explicit SigmodNeuron(int dimenCont=0, int *sizes=0,QObject *parent = 0);

signals:

public slots:

    // Neuron interface
protected:
    double activationFunction(double in);
    double *calculateError(double error);

private:
    const double k = 1;
    const double learnSpeed = 0.6;

    static double increaceW(double *in,double *mask,double state){
        (*mask) += (*in)*state;
        return state;
    }

};

#endif // SIGMODNEURON_H
