#include "Circle.h"
#include "Exeption.h"

Circle::Circle(double r = 1)
{
    if (r <= 0) {
        throw Exeption(1);
    }
    this->r = r;
}

double Circle::sq() const
{
    return 3.14 * r * r;
}
