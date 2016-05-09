#ifndef LAYER_H
#define LAYER_H

#include <QObject>
#include "neuron.h"
#include "../util/vector.h"
#include <QList>


typedef Neuron* (*neuronFactoryMethod)();

class Layer : public QObject
{
    Q_OBJECT
public:


     Layer(int inputDimenCount,int *inputDimen,int outDimenCount
            ,int *outDimen,QObject *parent = 0);

     Layer(int outDimenCount
            ,int *outDimen,QObject *parent = 0);

    inline Vector const* getInSize(){
        return inSize;
    }
    inline Vector const*getOutSize(){
        return outSize;
    }

    inline double* getIn(){
        return in;
    }

    inline double* getOut(){
        return out;
    }

    virtual void nextStep(double *data);
    virtual  void setParentLayer(Layer *parent);
    virtual void setChild(Layer *child);
    virtual void addFullConnectedNeuron(neuronFactoryMethod neuronFactory);



signals:

public slots:

protected:

    void setInParams(Vector *inSize);

    Vector *inSize;
    Vector *outSize;
    double *in;
    double *out;
    Layer *parent = NULL;
    Layer *child = NULL;
    QList<Neuron *> *fullConnectedNeurons;

};

#endif // LAYER_H
