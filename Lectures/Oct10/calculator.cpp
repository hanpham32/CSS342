#include <iostream>
#include "rational.h"
using namespace std;

int main()
{
    Rational r1;
    Rational r2(1,2);
    Rational r3(10, 100);
    Rational r4(3, 9);

    r1.PrintDetail(cout);
    r2.PrintDetail(cout);
    r3.PrintDetail(cout);
    r4.PrintDetail(cout);

    // Rational r5 = r3.Multiply(r2);
    Rational r5 = r3 * r2;
    r5.PrintDetail(cout);
}