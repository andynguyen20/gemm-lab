#include "matrix.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

Matrix::Matrix(std::size_t rows, std::size_t cols) 
    : rows_(rows), cols_(cols), data_(rows * cols, 0)
{
    if (rows == 0 || cols == 0) 
        throw std::runtime_error{"Zero dimension matrix"};
}

void Matrix::print() const
{
    for (std::size_t i = 0; i < rows_ * cols_; ++i) {
        if (i % cols_ == 0) 
            std::cout << "[";
        std::cout << data_[i];
        if (i % cols_ == cols_ - 1) 
            std::cout << "]\n";
        else 
            std::cout << ", ";
    }
}

std::size_t Matrix::rows() const
{
    return rows_;
}

std::size_t Matrix::cols() const
{
    return cols_;
}

std::size_t Matrix::size() const
{
    return rows_ * cols_;
}

float& Matrix::operator()(std::size_t index)
{
    return data_[index];
}

const float Matrix::operator()(std::size_t index) const
{
    return data_[index];
}

float* Matrix::data()
{
    return data_.data();
}

const float* Matrix::data() const
{
    return data_.data();
}

void Matrix::fill(float fill_val)
{
    for (float& val : data_) {
        val = fill_val;
    }
}

void Matrix::manual_fill(std::initializer_list<float> matrix)
{
    if (matrix.size() != rows_ * cols_) 
        throw std::runtime_error{"Invalid matrix size to fill"};

    std::size_t count = 0;
    for (const float& index : matrix) {
        data_[count++] = index;
    }
}