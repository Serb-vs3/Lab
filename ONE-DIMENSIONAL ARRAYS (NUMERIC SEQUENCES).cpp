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
    int* arr1 = new int[n];
    int* arr2 = new int[n];
    int size1 = 0, size2 = 0;
    for (int i = 0; i < n; ++i) {
        if (abs(arr[i]) <= X) {
            arr1[size1++] = arr[i];
        } else {
            arr2[size2++] = arr[i];
        }
    }
    for (int i = 0; i < size1; ++i) {
        arr[i] = arr1[i];
    }
    for (int i = 0; i < size2; ++i) {
        arr[size1 + i] = arr2[i];
    }
    std::cout << "New:";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    return 0;
}
