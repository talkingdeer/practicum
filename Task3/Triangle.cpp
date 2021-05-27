#include "Triangle.h"
#include "Exeption.h"
#include <math.h>

Triangle::Triangle(double a = 1, double b = 1, double c = 1)
{
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        throw Exeption(3);
    }
    this->a = a;
    this->b = b;
    this->c = c;
}
double Triangle::sq() const
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
