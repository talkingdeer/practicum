#include <iostream>
#include "Figure.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square_Circle.h"
#include "Exeption.h"

using namespace std;

int main()
{
    try {
        Circle c(1);
        Square s(0);
        Triangle t(3, 4, 5);
        Square_Circle sc(4, 1);
        Figure* arr[] = { (Figure*)&c, (Figure*)&s, (Figure*)&t, (Figure*)&sc };
        for (int i = 0; i < 4; i++) {
            cout << "Figure №" << i + 1 << ": ";
            cout << arr[i]->sq() << endl;
        }
    }
    catch (const Exeption& exc) {
        cerr << exc.GetName();
    }
    catch (exception &E) {
        cerr << E.what();
    }
    catch (...) {
        cerr << "Error\n";
    }
    return 0;
}
