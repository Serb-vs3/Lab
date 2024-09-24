#include <iostream>
#include <cmath>
#include <iomanip>
double roundToK(double value, int k) {
    double factor = pow(10, k);
    return round(value * factor) / factor;
}
int main() {
    double x;
    int k;
    std::cout << "x= ";
    std::cin >> x;
    if (x >= 1 || x <= -1) {
        std::cout << "noob" << std::endl;
        return 1;
    }
    std::cout << "k: ";
    std::cin >> k;
    if (k <= 1) {
        std::cout << "nood" << std::endl;
        return 1;
    }
    double result = log(1 - x);
    result = roundToK(result, k);
    std::cout <<"good: " << std::fixed << std::setprecision(k) << result << std::endl;
    return 0;
}
