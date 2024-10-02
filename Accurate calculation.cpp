#include <iostream>
#include <cmath>
#include <iomanip>
int main() {
    double x;
    int k, precision;
    std::cout << "X:";
    std::cin >> x;
    if (std::cin.fail() || x <= -1 || x >= 1) {
        std::cout << "Nood (x ∈ [-1, +1])" << std::endl;
        return 1;
    }
    std::cout << "k: ";
    std::cin >> k;
    if (std::cin.fail() || k <= 1) {
        std::cout << "Nood (K > 1)" << std::endl;
        return 1;
    }
    std::cout << "Decimal places: ";
    std::cin >> precision;
    if (std::cin.fail() || precision < 0) {
        std::cout << "Nood (n > 0)" << std::endl;
        return 1;
    }
    double epsilon = std::pow(10, -k);
    double exact_value = std::log(1 - x);
    double taylor_sum = 0;
    double term = -x;
    int n = 1;
    while (std::abs(term) >= epsilon) {
        taylor_sum += term;
        n++;
        term = -std::pow(x, n) / n;
    }
    std::cout << std::fixed << std::setprecision(precision);
    std::cout << "Taylor: " << taylor_sum << std::endl;
    std::cout << "Log: " << exact_value << std::endl;
    double difference = std::abs(taylor_sum - exact_value);
    std::cout << "The difference: " << difference << std::endl;
    return 0;
}
