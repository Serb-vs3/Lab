#include "RationalFraction.h"

int main() {
    try {
        RationalFraction frac1(3, 4);
        RationalFraction frac2(2, -5); 

        std::cout << "Fraction 1: " << std::endl;
        frac1.print();

        std::cout << "Fraction 2: " << std::endl;
        frac2.print();

        RationalFraction sum = frac1.add(frac2);
        std::cout << "Summation: " << std::endl;
        sum.print();

        RationalFraction product = frac1.multiply(frac2);
        std::cout << "Produced by: " << std::endl;
        product.print();

        RationalFraction quotient = frac1.divide(frac2);
        std::cout << "Private: " << std::endl;
        quotient.print();
    } catch (const std::exception& e) {
        std::cerr << "Error:" << e.what() << std::endl;
    }

    return 0;
}
