#ifndef NEURON_H
#define NEURON_H

#include <QObject>
#include "../util/vector.h"
#include <QPoint>
#include "../util/util.h"


class Neuron : public QObject
{
    Q_OBJECT
public:
    explicit Neuron(int dimenCont=0, int *sizes=NULL,QObject *parent = 0);
    Vector const* getSize(){
        return size;
    }
    virtual double calcFiled(Vector *inputSize, double *input, Vector const* offset = NULL);

    void setSize(Vector *size);
    virtual void calculateError(double error) ;


signals:

public slots:

protected:
    Vector *size;
    MyltidimensionOperation *myltidimensionOperation = NULL;
    double currentSumm;
    double currentSignal;
    double *weigth = NULL;
    double *lastIn;
    Vector const *lastInOffset;

    static double sumFun(double *in,double *mask,double state){
        state += (*in)*(*mask);
        return state;
    }

    virtual double activationFunction(double in) = 0;

};

#endif // NEURON_H
