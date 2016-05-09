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
};

#endif // SIGMODNEURON_H
