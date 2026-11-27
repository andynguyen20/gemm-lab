#include "matrix.hpp"
#include <iostream>

int main() {
    Matrix test_matrix{3, 4};
    test_matrix.test_fill();
    test_matrix.print();
    test_matrix(4) = 7;
    const Matrix& test_matrix_ref = test_matrix;
    std::cout << test_matrix(4) << '\n';
    std::cout << test_matrix_ref(4) << '\n';
    test_matrix.print();
}