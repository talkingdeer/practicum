#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
using namespace std;

class Figure {
public:
    virtual double sq() const = 0;
    virtual ~Figure() {}
};

#endif
