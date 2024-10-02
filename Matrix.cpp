#include <iostream>
#include <vector>
void inputMatrix(std::vector<std::vector<int>>& matrix, int& m, int& n) {
    std::cout << "Strings: ";
    std::cin >> m;
    std::cout << "Columns: ";
    std::cin >> n;

    if (m % 2 != 0 || m > 10 || n > 10) {
        std::cout << "Error" << std::endl;
        exit(1);
    }
    m /= 2;
    matrix.resize(2 * m, std::vector<int>(n));
    std::cout << "Entry:" << std::endl;
    for (int i = 0; i < 2 * m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}
void Matrix(const std::vector<std::vector<int>>& matrix) {
    std::cout << "Check it out:" << std::endl;
    for (const auto& row : matrix) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}
int Zero(const std::vector<std::vector<int>>& matrix, int m, int n) {
    int count = 0;
    for (int j = 0; j < n; ++j) {
        bool hasZero = false;
        for (int i = 0; i < 2 * m; ++i) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (!hasZero) {
            count++;
        }
    }
    return count;
}
int Row(const std::vector<std::vector<int>>& matrix, int m, int n) {
    int maxLength = 0;
    int rowIndex = -1;
    for (int i = 0; i < 2 * m; ++i) {
        int length = 1;
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] > matrix[i][j - 1]) {
                length++;
            } else {
                length = 1;
            }
            if (length > maxLength) {
                maxLength = length;
                rowIndex = i + 1;
            }
        }
    }
    return rowIndex;
}
int main() {
    int m, n;
    std::vector<std::vector<int>> matrix;
    inputMatrix(matrix, m, n);
    Matrix(matrix);
    int nonZeroCols = Zero(matrix, m, n);
    std::cout << "Zeroes: " << nonZeroCols << std::endl;
    int longestRow = Row(matrix, m, n);
    if (longestRow != -1) {
        std::cout << "First line: " << longestRow << std::endl;
    } else {
        std::cout << "Error" << std::endl;
    }
    return 0;
}
