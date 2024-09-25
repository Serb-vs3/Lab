#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int MIN = arr[0];
    int IND = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < MIN) {
            MIN = arr[i];
            IND = i;
        } else if (arr[i] == MIN) {
            IND = i;
        }
    }
    std::cout << "Min:" << MIN << std::endl;
    std::cout << "Index:" << IND << std::endl;
    int firstNegativeIndex = -1;
    int lastNegativeIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }
            lastNegativeIndex = i;
        }
    }
    if (firstNegativeIndex != -1 && lastNegativeIndex != -1) {
        int sum = 0;
        for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; ++i) {
            sum += arr[i];
        }
        std::cout << "Amount:" << sum << std::endl;
    } else {
        std::cout << "-=0" << std::endl;
    }
    int X;
    std::cout << "x: ";
    std::cin >> X;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (abs(arr[i]) <= X) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
    std::cout << "New:";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;
    return 0;
}
