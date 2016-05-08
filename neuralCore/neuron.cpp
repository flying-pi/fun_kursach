#include "neuron.h"

Neuron::Neuron( int w, int h,QObject *parent) : QObject(parent)
{
this->size = new QSize(w,h);
}
