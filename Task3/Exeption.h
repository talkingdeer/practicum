#ifndef EXEPTION_H
#define EXEPTION_H

class Exeption {
private:
    char* str;

public:
    Exeption(int ERR_CODE);
    const char* GetName() const;
    ~Exeption();
};

#endif
