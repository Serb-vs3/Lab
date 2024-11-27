#include "RationalFraction.h"
#include <iomanip>

int RationalFraction::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a > 0 ? a : -a;
}

void RationalFraction::reduce() {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

RationalFraction::RationalFraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denom == 0) {
        throw std::invalid_argument("Zero.");
    }
    reduce();
}

RationalFraction::RationalFraction(const RationalFraction& other)
    : numerator(other.numerator), denominator(other.denominator) {}

int RationalFraction::getNumerator() const {
    return numerator;
}

int RationalFraction::getDenominator() const {
    return denominator;
}

RationalFraction RationalFraction::add(const RationalFraction& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int denom = denominator * other.denominator;
    return RationalFraction(num, denom);
}

RationalFraction RationalFraction::multiply(const RationalFraction& other) const {
    return RationalFraction(numerator * other.numerator, denominator * other.denominator);
}

RationalFraction RationalFraction::divide(const RationalFraction& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Zero.");
    }
    return RationalFraction(numerator * other.denominator, denominator * other.numerator);
}

void RationalFraction::print() const {
    int num_width = std::to_string(std::abs(numerator)).length();
    int denom_width = std::to_string(std::abs(denominator)).length();
    int max_width = std::max(num_width, denom_width);
    bool is_negative = (numerator < 0);
    int padding = 5;

    std::cout << std::string(padding, ' ') << std::setw(max_width) << std::abs(numerator) << std::endl;
    std::cout << (is_negative ? " -   " : "     ");
    for (int i = 0; i < max_width; ++i) {
        std::cout << "-";
    }
    std::cout << std::endl;
    std::cout << std::string(padding, ' ') << std::setw(max_width) << denominator << std::endl;
}
