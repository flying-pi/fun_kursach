#ifndef SIGMODNEURON_H
#define SIGMODNEURON_H

#include <QObject>
#include "neuron.h"

class SigmodNeuron : public Neuron
{
    Q_OBJECT
public:
    explicit SigmodNeuron(int w = 0,int h= 0,QObject *parent = 0);

signals:

public slots:
};

#endif // SIGMODNEURON_H
