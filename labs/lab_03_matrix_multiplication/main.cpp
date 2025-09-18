#include <iostream>
#include "common/matrix.hpp"

int main() {
    // --- Демонстрация на целых числах (int) ---
    std::cout << "--- DEMO WITH INTEGERS ---" << std::endl;

    // Матрица 3x2
    const int a_rows = 3, a_cols = 2;
    int matrix_a[] = {
        1, 2,
        3, 4,
        5, 6
    };

    // Вектор размера 2
    int vector_b[] = {10, 20};
    int result_c[a_rows]; // Результат будет 3x1

    std::cout << "Matrix A:" << std::endl;
    print_matrix(matrix_a, a_rows, a_cols);

    std::cout << "\nVector B:" << std::endl;
    print_vector(vector_b, a_cols);

    multiply_matrix_vector(matrix_a, vector_b, result_c, a_rows, a_cols);
    std::cout << "\nResult A * B:" << std::endl;
    print_vector(result_c, a_rows); // Ожидаем: [50, 110, 170]

    // --- Демонстрация на числах с плавающей точкой (double) ---
    std::cout << "\n\n--- DEMO WITH DOUBLES ---" << std::endl;

    // Матрица 2x3
    const int m1_rows = 2, m1_cols = 3;
    double matrix_m1[] = {
        1.1, 1.2, 1.3,
        2.1, 2.2, 2.3
    };

    // Матрица 3x2
    const int m2_rows = 3, m2_cols = 2;
    double matrix_m2[] = {
        1.0, 2.0,
        3.0, 4.0,
        5.0, 6.0
    };

    double result_m3[m1_rows * m2_cols]; // Результат будет 2x2

    std::cout << "Matrix M1:" << std::endl;
    print_matrix(matrix_m1, m1_rows, m1_cols);

    std::cout << "\nMatrix M2:" << std::endl;
    print_matrix(matrix_m2, m2_rows, m2_cols);

    multiply_matrix_matrix(matrix_m1, matrix_m2, result_m3, m1_rows, m1_cols, m2_cols);
    std::cout << "\nResult M1 * M2:" << std::endl;
    print_matrix(result_m3, m1_rows, m2_cols);

    // Демонстрация умножения на скаляр
    double result_scalar[m1_rows * m1_cols];
    multiply_matrix_scalar(matrix_m1, 10.0, result_scalar, m1_rows, m1_cols);
    std::cout << "\nResult M1 * 10.0:" << std::endl;
    print_matrix(result_scalar, m1_rows, m1_cols);

    return 0;
}