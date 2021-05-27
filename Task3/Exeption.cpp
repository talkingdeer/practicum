#include "Exeption.h"
#include <iostream>
#include <cstring>

using namespace std;

Exeption::Exeption(int ERR_CODE)
{
    if (ERR_CODE == 1) {
        this->str = new char[strlen("Circle error\n") + 1];
        strcpy(str, "Circle error\n");
        return;
    }
    if (ERR_CODE == 2) {
        this->str = new char[strlen("Square error\n") + 1];
        strcpy(str, "Square error\n");
        return;
    }
    if (ERR_CODE == 3) {
        this->str = new char[strlen("Triangle error\n") + 1];
        strcpy(str, "Triangle error\n");
        return;
    }
    if (ERR_CODE == 4) {
        this->str = new char[strlen("Square_circle error\n") + 1];
        strcpy(str, "Square_circle error\n");
        return;
    }
    else {
        this->str = new char[strlen("Error\n") + 1];
        strcpy(str, "Error\n");
        return;
    }
}

Exeption::~Exeption()
{
    delete[] str;
}

const char* Exeption::GetName() const
{
    return str;
}
