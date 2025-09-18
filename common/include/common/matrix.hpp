#pragma once // Стандартная защита от двойного включения файла
#include <iostream>

// --- Вспомогательные функции для вывода ---

/**
 * @brief Печатает матрицу в консоль.
 * @tparam T Тип элементов матрицы (int, float, double).
 * @param matrix Указатель на начало 1D массива, представляющего матрицу.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 */
template<typename T>
void print_matrix(const T* matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Элемент (i, j) в 1D массиве находится по индексу i * cols + j
            std::cout << matrix[i * cols + j] << "\t";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Печатает вектор (1D массив) в консоль.
 * @tparam T Тип элементов вектора.
 * @param vector Указатель на начало массива.
 * @param size Размер вектора.
 */
template<typename T>
void print_vector(const T* vector, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << vector[i] << "\t";
    }
    std::cout << std::endl;
}

// --- Основные функции для умножения ---

/**
 * @brief Умножает матрицу на вектор. C = A * B
 * @param matrix_A Матрица A (m x n).
 * @param vector_B Вектор B (размер n).
 * @param result_C Результирующий вектор C (размер m).
 * @param rows_A Количество строк в A.
 * @param cols_A Количество столбцов в A (должно быть равно размеру B).
 */
template<typename T>
void multiply_matrix_vector(const T* matrix_A, const T* vector_B, T* result_C, int rows_A, int cols_A) {
    for (int i = 0; i < rows_A; ++i) {
        result_C[i] = 0; // Инициализируем элемент результирующего вектора
        for (int j = 0; j < cols_A; ++j) {
            result_C[i] += matrix_A[i * cols_A + j] * vector_B[j];
        }
    }
}

/**
 * @brief Умножает матрицу на скаляр. C = A * scalar
 * @param matrix_A Матрица A.
 * @param scalar Скаляр.
 * @param result_C Результирующая матрица C (тех же размеров, что и A).
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 */
template<typename T>
void multiply_matrix_scalar(const T* matrix_A, T scalar, T* result_C, int rows, int cols) {
    for (int i = 0; i < rows * cols; ++i) {
        result_C[i] = matrix_A[i] * scalar;
    }
}

/**
 * @brief Умножает матрицу A на матрицу B. C = A * B
 * @param matrix_A Матрица A (m x k).
 * @param matrix_B Матрица B (k x n).
 * @param result_C Результирующая матрица C (m x n).
 * @param rows_A Количество строк в A.
 * @param cols_A Количество столбцов в A (и строк в B).
 * @param cols_B Количество столбцов в B.
 */
template<typename T>
void multiply_matrix_matrix(const T* matrix_A, const T* matrix_B, T* result_C, int rows_A, int cols_A, int cols_B) {
    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            result_C[i * cols_B + j] = 0;
            for (int k = 0; k < cols_A; ++k) {
                result_C[i * cols_B + j] += matrix_A[i * cols_A + k] * matrix_B[k * cols_B + j];
            }
        }
    }
}