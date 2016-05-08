#ifndef NEURON_H
#define NEURON_H

#include <QObject>
#include <QSize>
#include <QPoint>

class Neuron : public QObject
{
    Q_OBJECT
public:
    explicit Neuron(int w = 0,int h= 0,QObject *parent = 0);
    QSize const* getSize(){
        return size;
    }
    virtual double calcFiled(QPoint const* offset,double const *input) = 0;

signals:

public slots:

protected:
    QSize *size;
};

#endif // NEURON_H
