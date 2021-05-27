#include "Exeption.h"
#include <iostream>
#include <cstring>

using namespace std;

Exeption::Exeption(const char* str)
{
    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str);
}

Exeption::~Exeption()
{
    if (str != NULL)
        delete[] str;
    str = NULL;
}

const char* Exeption::GetName() const
{
    return str;
}
