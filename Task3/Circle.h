#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"

class Circle : virtual public Figure {
    double r;

public:
    Circle(double);
    double sq() const;
};

#endif
