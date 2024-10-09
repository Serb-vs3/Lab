#include <iostream>
#include <string>
char* test(char* strDestination, const char* strEntry) {
    char* test_1 = strDestination;
    while (*strEntry != '\0') {
        *strDestination = *strEntry;
        strDestination++;
        strEntry++;
    }
    *strDestination = '\0';
    return test_1;
}
int main() {
    std::string conclusion;
    std::cout << "String: ";
    std::getline(std::cin, conclusion);
    char* Entry = new char[conclusion.size() + 1];
    char* destination = new char[conclusion.size() + 1];
    for (size_t i = 0; i < conclusion.size(); ++i) {
        Entry[i] = conclusion[i];
    }
    Entry[conclusion.size()] = '\0';
    test(destination, Entry);
    std::cout << "Copied string: " << destination << std::endl;
    delete[] Entry;
    delete[] destination;
    return 0;
}
