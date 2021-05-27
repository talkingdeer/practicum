#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"

class Square : virtual public Figure{
    double a;
public:
    Square(double);
    double sq() const;
};

#endif
