#ifndef LAYER_H
#define LAYER_H

#include <QObject>
#include "neuron.h"

class Layer : public QObject
{
    Q_OBJECT
public:
    explicit Layer(int inW = 0,int inH=0,int outW = 0,int ountH=0,QObject *parent = 0);


signals:

public slots:

private:
    double *in;
    double *out;
};

#endif // LAYER_H
