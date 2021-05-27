#include "List.h"
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <cstring>

using namespace std;

List::Node::Node(const char* elem, Node* next)
{
    this->elem = new char[strlen(elem) + 1];
    strcpy(this->elem, elem);
    this->next = next;
}

List::Node::~Node()
{
    if (elem != NULL)
        delete[] elem;
    elem = NULL;
}

bool List::empty() const
{
    return lst == NULL;
}

void List::clear()
{
    Node* pl;
    while (lst != NULL) {
        pl = lst;
        lst = lst->next;
        pl->Node::~Node();
        if (pl != NULL)
            delete pl;
    }
}

List::~List()
{
    this->clear();
}

List::List(const char* s)
{
    if (s == NULL) {
        throw Exeption("The string is empty");
    }
    Node* temp = new Node(s);
    lst = temp;
}

List::List(const List& l)
{
    if (l.empty()) {
        throw Exeption("The list is empty");
    }
    Node *p, *pl = l.lst;
    Node* temp = new Node(pl->elem);
    lst = p = temp;
    pl = pl->next;
    while (pl != NULL) {
        temp = new Node(pl->elem);
        p = p->next = temp;
        pl = pl->next;
    }
}

List& List::operator=(const List& l)
{
    if (&l == this) {
        return *this;
    }
    this->clear();
    if (l.lst == NULL) {
        return *this;
    }
    Node *p, *pl = l.lst;
    Node* temp = new Node(pl->elem);
    lst = p = temp;
    pl = pl->next;
    while (pl != NULL) {
        temp = new Node(pl->elem);
        p = p->next = temp;
        pl = pl->next;
    }
    return *this;
}

List& List::operator+=(const List& l)
{
    *this = *this + l;
    return *this;
}

List operator+(const List& l1, const List& l2)
{
    List::Node *p, *pl;

    if (l1.empty()) {
        cerr << "     List 1 is empty" << endl;
        return l2;
    }
    if (l2.empty()) {
        cerr << "     List 2 is empty" << endl;
        return l1;
    }
    List res(l1);

    p = res.lst;
    while (p->next != NULL) {
        p = p->next;
    }

    pl = l2.lst;

    while (pl != NULL) {
        List::Node* temp = new List::Node(pl->elem);
        p = p->next = temp;
        pl = pl->next;
    }
    return res;
}
List operator-(const List& l, const char* s)
{
    List::Node *p, *pre;

    if (l.empty()) {
        return l;
    }
    if (s == NULL) {
        return l;
    }
    List res(l);

    p = res.lst;
    if (!strcmp(p->elem, s)) {
        res.lst = p->next;
        delete p;
        return res;
    }
    if (p->next == NULL) {
        return res;
    }
    pre = p;
    p = p->next;
    while (p->next != NULL) {
        if (!strcmp(p->elem, s)) {
            pre->next = p->next;
            delete p;
            return res;
        }
        else {
            pre = p;
            p = p->next;
        }
    }
    if (p->next == NULL && !strcmp(p->elem, s)) {
        pre->next = NULL;
        delete p;
    }
    return res;
}

int List::length(void) const
{
    Node* p = this->lst;
    int res = 0;
    while (p) {
        res++;
        p = p->next;
    }
    return res;
}
char* List::operator[](int i)
{
    if (i >= (this->length())) {
        throw Exeption("\nLenght error\n");
    }
    Node* p = this->lst;
    int j = 0;
    while (j < i) {
        p = p->next;
        j++;
    }
    char* res = new char[strlen(p->elem) + 1];
    strcpy(res, p->elem);
    return res;
}

List::operator char*() const
{
    if (empty()) {
        return NULL;
    }
    Node* p = this->lst;
    int length = 0;
    while (p != NULL) {
        length += strlen(p->elem) + 1;
        p = p->next;
    }
    p = this->lst;
    char* res = new char[length];
    res[0] = '\0';
    int k = 0;
    while (p->next != NULL) {
        res = strcat(res, p->elem);
        res = strcat(res, "_\0");
        p = p->next;
    }
    res = strcat(res, p->elem);
    return res;
}

ostream& operator<<(ostream& s, const List& l)
{
    if (l.lst == NULL) {
        s << "";
        return s;
    }
    List::Node* pl = l.lst;
    while (pl != NULL) {
        s << pl->elem << "  ";
        pl = pl->next;
    }
    return s;
}