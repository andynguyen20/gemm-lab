#include "matrix.hpp"
#include <iostream>

int main() {
    Matrix test_matrix{3, 4};
    test_matrix.print();
    test_matrix.fill(7);
    test_matrix.print();
}