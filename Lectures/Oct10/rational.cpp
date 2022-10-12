#include "rational.h"

Rational::Rational() : numerator_(0), denominator_(1)
{
}

Rational::Rational(int num, int den) : numerator_(num), denominator_(den)
{
    if(den == 0)
    {
        numerator_ = 0;
        denominator_ = 1;
    }
    Reduce();
}

int Rational::numerator() const
{
    return numerator_;
}
int Rational::denominator() const
{
    return denominator_;
}

void Rational::set_value(int num, int den)
{
    if (den == 0)
    {
        numerator_ = 0;
        denominator_ = 1;
    } else 
    {
        numerator_ = num;
        denominator_ = den;
    }
    Reduce();
}

void Rational::Reduce()
{
    int gcf = 1;
    int minimum = min(numerator_, denominator_);
    for (int i=2; i<= minimum; i++)
    {
        if (((numerator_ % i) == 0 && (denominator_ % i) == 0))
        {
            gcf = i;
        }
    }
    numerator_ /= gcf;
    denominator_ /= gcf;
}

void Rational::PrintDetail(ostream& stream) const
{
    stream << numerator_ << " / " << denominator_ << endl;
}

Rational Rational::operator*(const Rational& rhs) const
{
    int numerator = numerator_ * rhs.numerator();
    int denominator = denominator_* rhs.denominator();
    return Rational(numerator, denominator);
}

Rational& Rational::operator*=(const Rational& rhs)
{
    numerator_ *= rhs.numerator();
    denominator_ *= rhs.denominator();
    Reduce();
    return *this;
}