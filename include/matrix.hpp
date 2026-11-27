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
    std::size_t rows() const;
    std::size_t cols() const;
    std::size_t size() const;
    float& operator()(std::size_t index);
    const float operator()(std::size_t index) const;
    void fill(float fill_val);
    void test_fill();
};