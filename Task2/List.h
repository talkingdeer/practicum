#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "Exeption.h"

class List {
    struct Node {
        char* elem;
        Node* next;
        Node(const char* elem = "\0", Node* next = NULL);
        ~Node();
    };
    Node* lst;

public:
    List()
        : lst(NULL)
    {
    }
    List(const char*);
    List(const List&);
    List& operator=(const List&);
    List& operator+=(const List&);
    int length() const;
    friend List operator+(const List&, const List&);
    friend List operator-(const List&, const char*);
    char* operator[](int);
    explicit operator char*() const;
    friend std::ostream& operator<<(std::ostream&, const List&);
    bool empty() const;
    void clear();
    ~List();
};

#endif