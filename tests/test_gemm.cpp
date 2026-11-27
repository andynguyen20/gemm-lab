#include "gemm.hpp"
#include "matrix.hpp"
#include <cassert>
#include <iostream>

void assert_matrix_equal(const Matrix& actual, const std::vector<float>& expected)
{
    assert(actual.size() == expected.size());

    for (std::size_t i = 0; i < actual.size(); ++i) {
        assert(actual.data()[i] == expected[i]);
    }
}

void test_square_multiplication()
{
    Matrix matrix_a {2, 2};
    Matrix matrix_b {2, 2};
    matrix_a.manual_fill({1, 2, 3, 4});
    matrix_b.manual_fill({5, 6, 7, 8});
    Matrix matrix_c {matrix_a.rows(), matrix_b.cols()};
    gemm::naive(matrix_a, matrix_b, matrix_c);
    
    assert_matrix_equal(matrix_c, {19.0f, 22.0f, 43.0f, 50.0f});
}

void test_rectangular_multiplication()
{
    
    Matrix matrix_a {2, 3};
    Matrix matrix_b {3, 2};
    matrix_a.manual_fill({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
    matrix_b.manual_fill({7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f});
    Matrix matrix_c {matrix_a.rows(), matrix_b.cols()};
    gemm::naive(matrix_a, matrix_b, matrix_c);
    
    assert_matrix_equal(matrix_c, {58.0f, 64.0f, 139.0f, 154.0f});
}

void test_wide_output_matrix()
{
    
    Matrix matrix_a {2, 3};
    Matrix matrix_b {3, 4};
    matrix_a.manual_fill({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
    matrix_b.manual_fill({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f});
    Matrix matrix_c {matrix_a.rows(), matrix_b.cols()};
    gemm::naive(matrix_a, matrix_b, matrix_c);
    
    assert_matrix_equal(matrix_c, {38.0f, 44.0f, 50.0f, 56.0f, 83.0f, 98.0f, 113.0f, 128.0f});
}

void test_tall_output_matrix()
{
    
    Matrix matrix_a {4, 2};
    Matrix matrix_b {2, 2};
    matrix_a.manual_fill({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f});
    matrix_b.manual_fill({2.0f, 3.0f, 4.0f, 5.0f});
    Matrix matrix_c {matrix_a.rows(), matrix_b.cols()};
    gemm::naive(matrix_a, matrix_b, matrix_c);
    
    assert_matrix_equal(matrix_c, {10.0f, 13.0f, 22.0f, 29.0f, 34.0f, 45.0f, 46.0f, 61.0f});
}

void test_negative_and_fractional_values()
{
    Matrix matrix_a {2, 2};
    Matrix matrix_b {2, 2};
    matrix_a.manual_fill({-1.0f, 2.5f, 3.0f, -4.0f});
    matrix_b.manual_fill({2.0f, -3.0f, 4.0f, 0.5f});
    Matrix matrix_c {matrix_a.rows(), matrix_b.cols()};
    gemm::naive(matrix_a, matrix_b, matrix_c);
    
    assert_matrix_equal(matrix_c, {8.0f, 4.25f, -10.0f, -11.0f});
}

void test_outer_product()
{
    Matrix matrix_a {3, 1};
    Matrix matrix_b {1, 4};
    matrix_a.manual_fill({1.0f, 2.0f, 3.0f});
    matrix_b.manual_fill({4.0f, 5.0f, 6.0f, 7.0f});
    Matrix matrix_c {matrix_a.rows(), matrix_b.cols()};
    gemm::naive(matrix_a, matrix_b, matrix_c);
    
    assert_matrix_equal(matrix_c, {4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 10.0f, 12.0f, 14.0f, 12.0f, 15.0f, 18.0f, 21.0f});
}

void test_identity_matrix_multiplication()
{
    Matrix matrix_a {2, 2};
    Matrix matrix_b {2, 2};
    matrix_a.manual_fill({1.0f, 2.0f, 3.0f,4.0f});
    matrix_b.manual_fill({1.0f, 0.0f, 0.0f, 1.0f});
    Matrix matrix_c {matrix_a.rows(), matrix_b.cols()};
    gemm::naive(matrix_a, matrix_b, matrix_c);
    
    assert_matrix_equal(matrix_c, {1.0f, 2.0f, 3.0f, 4.0f});
}

void test_zero_matrix_multiplication()
{
    Matrix matrix_a {2, 2};
    Matrix matrix_b {2, 2};
    matrix_a.manual_fill({1.0f, 2.0f, 3.0f,4.0f });
    matrix_b.manual_fill({0.0f, 0.0f, 0.0f, 0.0f});
    Matrix matrix_c {matrix_a.rows(), matrix_b.cols()};
    gemm::naive(matrix_a, matrix_b, matrix_c);
    
    assert_matrix_equal(matrix_c, {0.0f, 0.0f, 0.0f, 0.0f});
}

void test_incompatible_input_dimensions()
{
    Matrix matrix_a {2, 3};
    Matrix matrix_b {4, 2};
    Matrix matrix_c {matrix_a.rows(), matrix_b.cols()};
    gemm::naive(matrix_a, matrix_b, matrix_c);
}

void test_incorrect_output_dimensions_1()
{
    Matrix matrix_a {2, 3};
    Matrix matrix_b {3, 4};
    Matrix matrix_c {2, 5};
    gemm::naive(matrix_a, matrix_b, matrix_c);
}

void test_incorrect_output_dimensions_2()
{
    Matrix matrix_a {2, 3};
    Matrix matrix_b {3, 4};
    Matrix matrix_c {3, 4};
    gemm::naive(matrix_a, matrix_b, matrix_c);
}

void test_incorrect_output_dimensions_3()
{
    Matrix matrix_a {2, 3};
    Matrix matrix_b {3, 4};
    Matrix matrix_c {3, 5};
    gemm::naive(matrix_a, matrix_b, matrix_c);
}

void test_repeated_multiplication()
{
    
    Matrix matrix_a {2, 2};
    Matrix matrix_b {2, 2};
    matrix_a.manual_fill({1.0f, 2.0f, 3.0f,4.0f });
    matrix_b.manual_fill({5.0f, 6.0f, 7.0f, 8.0f});
    Matrix matrix_c {matrix_a.rows(), matrix_b.cols()};
    gemm::naive(matrix_a, matrix_b, matrix_c);
    
    assert_matrix_equal(matrix_c, {19.0f, 22.0f, 43.0f, 50.0f});

    gemm::naive(matrix_a, matrix_b, matrix_c);
    
    assert_matrix_equal(matrix_c, {19.0f, 22.0f, 43.0f, 50.0f});

    gemm::naive(matrix_a, matrix_b, matrix_c);
    
    assert_matrix_equal(matrix_c, {19.0f, 22.0f, 43.0f, 50.0f});
}

void test_zero_length_shared_dimensions()
{
    Matrix matrix_a {2, 0};
    Matrix matrix_b {0, 3};
    Matrix matrix_c {matrix_a.rows(), matrix_b.cols()};
    gemm::naive(matrix_a, matrix_b, matrix_c);
}

int main() {
    try {
        test_square_multiplication();
        test_rectangular_multiplication();
        test_wide_output_matrix();
        test_tall_output_matrix();
        test_negative_and_fractional_values();
        test_outer_product();
        test_identity_matrix_multiplication();
        test_outer_product();
        test_zero_matrix_multiplication();
        //test_incompatible_input_dimensions();
        //test_incorrect_output_dimensions_1();
        //test_incorrect_output_dimensions_2();
        //test_incorrect_output_dimensions_3();
        test_repeated_multiplication();
        //test_zero_length_shared_dimensions();
        std::cout << "Tested Passed!!!!" << '\n';
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}
