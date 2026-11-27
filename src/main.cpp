#include "matrix.hpp"
#include <iostream>

int main() {
    Matrix test_matrix{3, 4};
    test_matrix.test_fill();
    float* matrix_ptr = test_matrix.data();
    std::cout << matrix_ptr[0] << '\n';
    std::cout << matrix_ptr[6] << '\n';
    const float* const_matrix_ptr = test_matrix.data();
    //const_matrix_ptr[0] = 10.0f;
    matrix_ptr[0] = 10.0f;
    test_matrix.print();
}