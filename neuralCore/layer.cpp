#include "layer.h"
#include "sigmodneuron.h"




Layer::Layer(int inputDimenCount, int *inputDimen,
             int outDimenCount, int *outDimen, QObject *parent):QObject(parent)
{
    setInParams(new Vector(inputDimenCount,inputDimen));
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

Layer::~Layer()
{
    delete outSize;
    delete []in;
    delete []out;
    delete []errors;
    delete []bufErrors;
    delete child;
    for(int i=0;i<fullConnectedNeurons->size();i++)delete fullConnectedNeurons->at(i);
    delete fullConnectedNeurons;
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
        newItem->setAdditionalActiavation(parent == NULL);
        fullConnectedNeurons->append(newItem);
    }
}


void Layer::settError(double *error)
{
    for(int i=0;i<fullConnectedNeurons->size();i++){
        bufErrors =  fullConnectedNeurons->at(i)->calculateError(error[i]);
        for(int j=0;j<inSize->getLinerLength();  j++)
        {
            if(i==0){
                this->errors[j] = bufErrors[j];
            }else{
                this->errors[j] +=bufErrors[j];
            }
        }
    }
    if(parent !=NULL)
        parent->settError(errors);
}

void Layer::setInParams(Vector *inSize)
{
    this->inSize = inSize;
    in = new double[inSize->getLinerLength()];
    errors = new double[inSize->getLinerLength()];
    bufErrors = new double[inSize->getLinerLength()];
}
