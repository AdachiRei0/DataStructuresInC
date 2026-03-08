#include "Complex.hpp"
#include <time.h>

int main () {
    clock_t start = clock();

    Complex a(1, 2);
    Complex b(3, 4);

    cout << "a = ";
    a.show();
    cout << "b = ";
    b.show();

    Complex c = a + b;
    cout << "a + b = ";
    c.show();

    c = Complex(34, -5); 
    cout << c.get_str() << endl;
    c.show();

    c = a - b;
    cout << "a - b = ";
    c.show();

    cout << "a * b = ";
    c = a * b;
    c.show();

    cout << "a / b = ";
    c = a / b;
    c.show();

    cout << "c.cg() = ";
    c.cg().show();

    cout << "b.get_arg() = ";
    cout << b.get_arg() << endl;

    cout << "b.get_mod() = " ;
    cout << b.get_mod() << endl;

    clock_t end = clock();

    cout << "花费" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

    return 0;
}