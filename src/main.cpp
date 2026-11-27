#include "matrix.hpp"
#include "gemm.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        Matrix matrix_a {2, 2};
        Matrix matrix_b {2, 2};
        matrix_a.manual_fill({1, 2, 3, 4});
        matrix_b.manual_fill({5, 6, 7, 8});
        Matrix matrix_c {matrix_a.rows(), matrix_b.cols()};
        gemm::naive(matrix_a, matrix_b, matrix_c);
        matrix_c.print();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}