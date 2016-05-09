#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <random>
#include <QString>
#include <QDebug>
#include "vector.h"


class Util
{

public:
    static Util& getInstance()
    {
        static Util    instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }

private:
    Util();
    const double downRandom = 0;
    const double upRandom = 10000;


    std::random_device randomDevice;
    std::default_random_engine randomEngine;
    std::uniform_int_distribution<double> uniform_dist;


public:
    Util(Util const&)               = delete;
    void operator=(Util const&)  = delete;

    double myRand();
};

typedef double (*myltidimensionSymmator)(double*, double*, double);

class MyltidimensionOperation{

public:
    MyltidimensionOperation(Vector *summatorSize,Vector *inputSize);

    inline double calc(double *_input,double *_summator,myltidimensionSymmator summatorFun,double state=0){
        double *input = _input;
        double *summator = _summator;
        int start = 0;
        int currentDimenStart = 1;
        int summatorSize = 1;
        for(int i=0;i<dimenCount;i++)
        {
            start+=offsetPoint[i]*currentDimenStart;
            currentDimenStart =(i == 0)?(*inputSize)[0]:currentDimenStart*(*inputSize)[i-1];
            summatorSize*=(*this->summatorSize)[i];
        }
        input+=start;
        for(int i=0;i<summatorSize;i++){
            if(i%axisOffset[0] == 0 && i>0){
                for(int d=0;d<dimenCount;d++){
                    if(i%axisOffset[d] == 0){
                        input-=(((*this->summatorSize)[d])-(d==0?0:1))*(d==0?1:inputAxisOffset[d-1]);
                        if(i%axisOffset[d+1] != 0){
                            input += inputAxisOffset[d];
                            break;
                        }
                    }
                }
            }
            state = summatorFun(input,summator,state);
            input++;
            summator++;
        }

        return state;
    }

    void setOffsetPoint(int const*offset){
        if(offset != NULL && offset != 0){
            offsetPoint = offset;
        }
    }

private:
    Vector *inputSize;
    Vector *summatorSize;
    int dimenCount;
    int *axisOffset;
    int *inputAxisOffset;
    int const*offsetPoint;


};


#endif // UTIL_H
