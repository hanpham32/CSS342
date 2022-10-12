#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iostream>
using namespace std;

class Rational
{
    public:
        //Constructors
        Rational();
        Rational(int numerator, int denominator);

        //getters-setters
        int numerator() const;
        int denominator() const;
        void set_value(int numerator, int denominator);

        //actions
        Rational& operator*=(const Rational& rhs);
        Rational operator*(const Rational& rhs) const;
        Rational Divide(const Rational& rhs) const;
        Rational Add(const Rational& rhs) const;
        Rational Subtract(const Rational& rhs) const;
        void PrintDetail(ostream& stream) const;

    private:
        int numerator_;
        int denominator_;
        void Reduce();
};
#endif