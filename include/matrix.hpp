#pragma once 
#include <cstddef>
#include <vector>

class Matrix {
private:
    std::size_t rows_;
    std::size_t cols_;
    std::vector<float> data_;
public:
    Matrix(std::size_t rows, std::size_t cols);
    void print() const;
};