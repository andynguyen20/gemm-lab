#include "matrix.hpp"
#include "gemm.hpp"
#include <random>
#include <iostream>
#include <chrono>

constexpr unsigned int SEED_A = 42;
constexpr unsigned int SEED_B = 43;
constexpr int WARMUP_ITERATIONS = 3;

void fill_random(Matrix& matrix, unsigned int seed)
{
    std::mt19937 gen(seed);
    std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
    
    float* matrix_ptr = matrix.data();

    for (std::size_t i = 0; i < matrix.size(); ++i) {
        matrix_ptr[i] = dist(gen);
    }
}

double checksum(const Matrix& matrix) {
    double accumulator = 0;
    const float* matrix_ptr = matrix.data();
    for (std::size_t i = 0; i < matrix.size(); ++i) {
        accumulator += matrix_ptr[i];
    }
    return accumulator;
}

int main() {
    Matrix matrix_a {256, 256};
    Matrix matrix_b {256, 256};
    Matrix matrix_c {matrix_a.rows(), matrix_b.cols()};
    fill_random(matrix_a, SEED_A);
    fill_random(matrix_b, SEED_B);

    for (int i = 0; i < WARMUP_ITERATIONS; ++i) {
        gemm::naive(matrix_a, matrix_b, matrix_c);
    }

    auto start = std::chrono::steady_clock::now();
    gemm::naive(matrix_a, matrix_b, matrix_c);
    auto end = std::chrono::steady_clock::now();

    auto elapsed = end - start;

    std::chrono::duration<double> elapsed_s = elapsed;
    std::chrono::duration<double, std::milli> elapsed_ms = elapsed;

    std::cout << "Naive GEMM Benchmark\n";
    std::cout << "Matrix A: " << matrix_a.rows() << " x " << matrix_a.cols() << '\n'; 
    std::cout << "Matrix B: " << matrix_b.rows() << " x " << matrix_b.cols() << '\n'; 
    std::cout << "Matrix C: " << matrix_c.rows() << " x " << matrix_c.cols() << '\n'; 
    std::cout << "Checksum: " << checksum(matrix_c) << '\n';
    std::cout << '\n';
    std::cout << "Elapsed time: " << elapsed_s << '\n';
    std::cout << "Elapsed time: " << elapsed_ms << '\n';
}