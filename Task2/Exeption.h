#ifndef EXEPTION_H
#define EXEPTION_H

class Exeption {
private:
    char* str;

public:
    Exeption(const char*);
    const char* GetName() const;
    ~Exeption();
};

#endif
