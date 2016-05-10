#include "vector.h"


Vector::Vector(int dimenCount, int *dimens){
    if(dimens == nullptr){
        dimens = new int[dimenCount];
        for(int i=0;i<dimenCount;i++)
            dimens[i]=0;
    }
    this->dimens = dimens;
    this->dimenCount = dimenCount;
}

Vector::~Vector()
{
    delete []dimens;
}


int Vector::operator[](int pos){
    return dimens[pos];
}

int Vector::getLinerLength()
{
    if(dimenCount == 0) return 0;
    int result = dimens[0];
    for(int i=1;i<dimenCount;i++){
        result*=dimens[i];
    }
    return result;
}
