#include <iostream>

template<typename T, size_t M, size_t N, size_t P>
void multiply(const T (&A)[M][N], const T (&B)[N][P], T (&C)[M][P]) {
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < P; ++j) {
            T sum = T{};
            for (size_t k = 0; k < N; ++k) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

int main() {
    int A[2][3] = {{1,2,3},{4,5,6}};
    int B[3][2] = {{7,8},{9,10},{11,12}};
    int C[2][2] = {};

    multiply(A, B, C);

    std::cout << "test_1 result:\n";
    for (size_t i=0; i<2; ++i){
        for (size_t j=0; j<2; ++j) std::cout << C[i][j] << ' ';
        std::cout << '\n';
    }
    return 0;
}