#ifndef SQUARE_CIRCLE_H
#define SQUARE_CIRCLE_H

#include "Circle.h"
#include "Square.h"

class Square_Circle : public Square, public Circle {
    double a, r;

public:
    Square_Circle(double, double);
    double sq() const;
};

#endif
