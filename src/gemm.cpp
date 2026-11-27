#include "gemm.hpp"
#include <iostream>
#include <stdexcept>

namespace gemm {
    void naive(const Matrix& A, const Matrix& B, Matrix& C)
    {
        if (A.cols() != B.rows()) 
            throw std::runtime_error{"Invalid input matrix dimensions"}; 
        if ((C.rows() != A.rows()) || (C.cols() != B.cols())) 
            throw std::runtime_error{"Invalid output matrix dimension"};

        const float* matrix_a = A.data();
        const float* matrix_b = B.data();
        float* matrix_c = C.data();

        for (std::size_t k = 0; k < C.rows() * C.cols(); ++k) {
            float temp = 0.0f;
            std::size_t row = (k / C.cols()) * A.cols();
            std::size_t col = k % B.cols();
            for (std::size_t j = col; j < B.rows() * B.cols(); j += B.cols()) { 
                temp += matrix_a[row++] * matrix_b[j];
            }
            matrix_c[k] = temp;
        }
    }
}