#ifndef RATIONALFRACTION_H
#define RATIONALFRACTION_H

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>

class RationalFraction {
private:
    int numerator;
    int denominator;
    int gcd(int a, int b);
    void reduce();

public:
    RationalFraction(int num, int denom);
    RationalFraction(const RationalFraction& other);
    int getNumerator() const;
    int getDenominator() const;
    RationalFraction add(const RationalFraction& other) const;
    RationalFraction multiply(const RationalFraction& other) const;
    RationalFraction divide(const RationalFraction& other) const;
    void print() const;
};
#endif
