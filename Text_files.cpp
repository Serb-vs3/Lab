#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
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
std::vector<std::string> readFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cerr << "Error: " << filename << std::endl;
        return lines;
    }
    std::string line;
    while (std::getline(input, line)) {
        lines.push_back(line);
    }
    input.close();
    return lines;
}
void F(const std::string& filename, const std::vector<std::string>& lines) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: " << filename << std::endl;
        return;
    }
    for (const auto& line : lines) {
        outputFile << line << std::endl;
    }
    outputFile.close();
}
void processFiles() {
    const std::string input = "input.txt";
    const std::string output1 = "output_1.txt";
    const std::string output2 = "output_2.txt";
    std::vector<std::string> lines = readFile(input);
    std::vector<std::string> Decreasing;
    std::vector<std::string> Increasing;
    for (const auto& line : lines) {
        if (V(line)) {
            Decreasing.push_back(line);
        } else if (N(line)) {
            Increasing.push_back(line);
        }
    }
    if (Decreasing.empty()) {
        std::ofstream(output1).close();
    } else {
       F(output1, Decreasing);
    }
    if (Increasing.empty()) {
        std::ofstream(output2).close();
    } else {
       F(output2, Increasing);
    }
    std::cout << "Successful" << std::endl;
}
int main() {
    processFiles();
    return 0;
}
