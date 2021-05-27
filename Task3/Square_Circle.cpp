#include "Square_Circle.h"
#include "Exeption.h"

double Square_Circle::sq() const
{
    return Square::sq() - Circle::sq();
}

Square_Circle::Square_Circle(double a, double r)
    : Square(a)
    , Circle(r)
{
    if (a <= 0 || r <= 0 || a < 2 * r)
        throw Exeption(4);
}
