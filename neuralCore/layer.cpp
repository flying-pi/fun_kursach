#include "layer.h"




Layer::Layer(int inputDimenCount, int *inputDimen,
             int outDimenCount, int *outDimen, QObject *parent):QObject(parent)
{
    inSize = new Vector(inputDimenCount,inputDimen);
    outSize = new Vector(outDimenCount,outDimen);
    in = new double[inSize->getLinerLength()];
    out = new double[outSize->getLinerLength()];
    fullConnectedNeurons = new QList<Neuron *>();
}

Layer::Layer(int outDimenCount, int *outDimen, QObject *parent)
{
    outSize = new Vector(outDimenCount,outDimen);
    out = new double[outSize->getLinerLength()];
    fullConnectedNeurons = new QList<Neuron *>();
}

void Layer::nextStep(double *data) {
    if(child == NULL) return;
    for(int i=0;i<outSize->getDimensCount();i++){

    }
    child->nextStep(out);
}

void Layer::setParentLayer(Layer *parent){
    this->parent = parent;
}

void Layer::setChild(Layer *child){
    child->setInParams(outSize);
    this->child = child;
    child->setParentLayer(this);
}

void Layer::addFullConnectedNeuron(neuronFactoryMethod neuronFactory)
{
    for(int i=0;i<outSize->getLinerLength();i++){
        Neuron *newItem =neuronFactory();
        newItem->setSize(inSize);
        fullConnectedNeurons->append(newItem);
    }
}

void Layer::setInParams(Vector *inSize)
{
    this->inSize = inSize;
    in = new double[inSize->getLinerLength()];
}
