#include <cstdio>
#include <iostream>
#include "List.h"
#include "Exeption.h"
#include <stdexcept>
#include <cstring>
#include <stdio.h>

using namespace std;

char* get(char* str, size_t num)
{
    str = NULL;
    num = 0;
    getline(&str, &num, stdin);
    int len = strlen(str);
    if (!strcmp(str, "\n\0")) {
        str[0] = '\0';
        return str;
    }
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    return str;
}

int main()
{
    try {
        char* s = NULL;
        size_t n = 0;
        cerr << "\n   The tests are running..." << endl;
        cerr << "\n   Enter the string: ";
        s = get(s, n);
        List l1(s);
        cerr << "\n   Creating the list... \n   " << l1 << endl;
        cerr << "\n   Creating the 2nd list...\n";
        cerr << "\n   Enter the string: ";
        free(s);
        s = get(s, n);
        List l2(s);
        cerr << "\n   Creating the second list...\n   " << l2 << endl;
        l1 = l1 + l2;
        cerr << "\n   List 1 = List 1 + list 2 \n   " << l1 << endl;
        l1 += l2;
        cerr << "\n   List 1 += List 2 \n   " << l1 << endl;
        free(s);
        cerr << "\n   Enter the string you want to add to the beginning of the line: ";
        s = get(s, n);
        cerr << "\n   List 1 = " << s << " + List 1 \n   " << (l1 = s + l1) << endl;
        free(s);
        cerr << "\n   Enter the string you want to add to the ending of the line: ";
        s = get(s, n);
        cerr << "\n   List 1 = List 1 + " << s << "\n   " << (l1 = l1 + s) << endl;
        free(s);
        cerr << "\n   Choose the srtring you want to remove: ";
        s = get(s, n);
        cerr << "\n   List 1 = List 1 - " << s << " \n   " << (l1 = l1 - s) << endl;
        free(s);
        cerr << "\n   Enter the number of the element you want to display: ";
        int i;
        cin >> i;
        char* el;
        el = l1[i];
        cerr << "\n   " << el << endl;
        delete[] el;
        cerr << "\n   Transforming the list into the string... " << endl;
        char* str = (char*)l1;
        cerr << "   " << str << endl;
		delete[] str;
        cerr << "\n   The lenght of the list:" << endl;
        cerr << "\n   " << l1.length() << endl;
        cerr << endl;
    }
    catch (exception& e) {
        cerr << "Standart exception error " << e.what() << endl;
    }
    catch (Exeption& E) {
        cerr << E.GetName();
    }
    catch (...) {
        cerr << "Error\n";
    }
    return 0;
}
