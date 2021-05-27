#include "Square.h"
#include "Exeption.h"

Square::Square(double a = 1)
{
    if (a <= 0) {
        throw Exeption(1);
    }
    this->a = a;
}
double Square::sq() const
{
    return a * a;
}
