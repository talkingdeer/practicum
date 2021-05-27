#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure {
    double a, b, c;

public:
    Triangle(double, double, double);
    double sq() const;
};

#endif
