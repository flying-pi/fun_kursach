#ifndef SIZE_H
#define SIZE_H


class Vector
{
public:
    Vector(int dimenCount,int *dimens);
    int operator[](int pos);
    /**
     * @brief getLinerLength
     * @return  return lenth of array for saving array with @dimenCount dimension and @dimens lenth of each dimen
     */
    int getLinerLength();
    int const*getDimenSizes() const{
        return dimens;
    }

   const inline int getDimensCount() const {return  dimenCount;}
private:
    int *dimens;
    int dimenCount;
};


#endif // SIZE_H
