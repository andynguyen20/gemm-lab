#include "matrix.hpp"
#include <iostream>

Matrix::Matrix(std::size_t rows, std::size_t cols) 
    : rows_(rows), cols_(cols), data_(rows * cols, 0)
{

}

void Matrix::print() const
{
    for (std::size_t i = 0; i < rows_ * cols_; ++i) {
        if (i % cols_ == 0) 
            std::cout << "[" << data_[i] << ", ";
        else if (i % cols_ == cols_ - 1) 
            std::cout << data_[i] << "]\n";
        else
            std::cout << data_[i] << ", ";
    }
}