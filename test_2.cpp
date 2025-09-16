#include <iostream>

void multiply(const int A[], const int B[], int C[]) {
    // Фиксированные размеры: M=2, N=3, P=2
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            int sum = 0;
            for (size_t k = 0; k < 3; ++k) {
                sum += A[i * 3 + k] * B[k * 2 + j];
            }
            C[i * 2 + j] = sum;
        }
    }
}

int main() {
    int A[2 * 3] = {1, 2, 3, 4, 5, 6};  // 2x3
    int B[3 * 2] = {7, 8, 9, 10, 11, 12};  // 3x2
    int C[2 * 2] = {};  // 2x2

    multiply(A, B, C);

    std::cout << "test_2 result (flat arrays):\n";
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            std::cout << C[i * 2 + j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}