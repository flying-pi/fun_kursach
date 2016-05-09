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
    in = data;
    for(int i=0;i<outSize->getLinerLength();i++){
        out[i] = fullConnectedNeurons->at(i)->calcFiled(inSize,in);
    }
    if(child != NULL)
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

void Layer::settError(double *error)
{
    for(int i=0;i<fullConnectedNeurons->size();i++){
        fullConnectedNeurons->at(i)->calculateError(error[i]);
    }
}

void Layer::setInParams(Vector *inSize)
{
    this->inSize = inSize;
    in = new double[inSize->getLinerLength()];
}
