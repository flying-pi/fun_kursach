#include "util.h"


Util::Util()
{
    //init random
    //    std::mt19937 rand_engine(rand_dev());
    randomEngine =  std::default_random_engine(randomDevice());;
    uniform_dist = std::uniform_int_distribution<double>(downRandom, upRandom);
}

double Util::myRand()
{
    return uniform_dist(randomEngine)/upRandom;
}


