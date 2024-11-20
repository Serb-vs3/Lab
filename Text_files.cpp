#include <iostream>
#include <fstream>
#include <string>
bool V(const std::string& str) {
    for (size_t i = 1; i < str.size(); ++i) {
        if (str[i] < str[i - 1]) {
            return false;
        }
    }
    return true;
}
bool N(const std::string& str) {
    for (size_t i = 1; i < str.size(); ++i) {
        if (str[i] > str[i - 1]) {
            return false;
        }
    }
    return true;
}
void processFiles() {
    const std::string inputFile = "input.txt";
    const std::string outputFile1 = "output_1.txt";
    const std::string outputFile2 = "output_2.txt";
    std::ifstream input(inputFile);
    if (!input.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return;
    }
    std::ofstream output1(outputFile1);
    if (!output1.is_open()) {
        std::cerr << "Error: Unable to open output file 1." << std::endl;
        return;
    }
    std::ofstream output2(outputFile2);
    if (!output2.is_open()) {
        std::cerr << "Error: Unable to open output file 2." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(input, line)) {
        if (V(line)) {
            output1 << line << std::endl;
        } else if (N(line)) {
            output2 << line << std::endl;
        }
    }
    std::cout << "Processing completed successfully." << std::endl;
}
int main() {
    processFiles();
    return 0;
}
