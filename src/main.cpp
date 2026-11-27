#include "matrix.hpp"
#include <iostream>

int main() {
    Matrix test_matrix{3, 4};
    test_matrix.print();
    std::cout << test_matrix.cols() << '\n';
    std::cout << test_matrix.rows() << '\n';
    std::cout << test_matrix.size() << '\n';
}