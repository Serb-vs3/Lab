#include <iostream>
#include <cstring>
const int MAX = 300;
bool isStrictlyIncreasing(const char* word) {
    for (int i = 1; word[i] != '\0'; i++) {
        if (word[i] <= word[i - 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    char input[MAX];
    std::cout << "300 >: ";
    std::cin.getline(input, MAX);
    char word[MAX];
    int index = 0;
    bool found = false;
    for (int i = 0; ; i++) {
        if (input[i] == ' ' || input[i] == '\0') {
            if (index > 0) {
                word[index] = '\0';
                if (isStrictlyIncreasing(word)) {
                    std::cout << "Result: " << word << std::endl;
                    found = true;
                    break;
                }
                index = 0;
            }
            if (input[i] == '\0') {
                break;
            }
        } else {
            word[index++] = input[i];
        }
    }
    if (!found) {
        std::cout << "No result" << std::endl;
    }
    return 0;
}
