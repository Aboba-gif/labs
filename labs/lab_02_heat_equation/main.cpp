#include <iostream>
#include "common/heat.hpp"

// Функция для создания двумерного динамического массива
double** create_grid(int size) {
    double** grid = new double*[size];
    for (int i = 0; i < size; ++i) {
        grid[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            grid[i][j] = 0.0;
        }
    }
    return grid;
}

// Функция для освобождения памяти
void delete_grid(double** grid, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

int main() {
    std::cout << "Lab 02: 2D Heat Equation" << std::endl;

    // --- Параметры симуляции ---
    const int GRID_SIZE = 21; // Размер сетки (нечетный, чтобы был центр)
    const double L = 1.0;     // Размер области (1.0 x 1.0)
    const double C = 0.1;     // Коэффициент теплопроводности
    const int TIME_STEPS = 10; // Количество шагов по времени

    const double H = L / (GRID_SIZE - 1); // Шаг по пространству
    // Вычисляем шаг по времени из условия устойчивости
    const double TAU = (H * H) / (4.0 * C) * 0.9; // Берем с запасом 0.9

    // --- Создание и инициализация сеток ---
    double** current_grid = create_grid(GRID_SIZE);
    double** next_grid = create_grid(GRID_SIZE);

    initialize_grid(current_grid, GRID_SIZE);
    initialize_grid(next_grid, GRID_SIZE); // next_grid также инициализируется нулями на границах

    std::cout << "Initial state:" << std::endl;
    print_grid(current_grid, GRID_SIZE);

    // --- Основной цикл симуляции ---
    for (int t = 0; t < TIME_STEPS; ++t) {
        simulation_step(current_grid, next_grid, GRID_SIZE, C, H, TAU);


        // Обмен указателями. Теперь next_grid становится current_grid для следующей итерации,
        // а бывший current_grid будет использован для записи нового состояния.
        // Это эффективнее, чем копировать все данные.
        double** temp = current_grid;
        current_grid = next_grid;
        std::cout << "State after " << t << " steps:" << std::endl;
        print_grid(current_grid, GRID_SIZE);
        next_grid = temp;
    }

    // --- Очистка памяти ---
    delete_grid(current_grid, GRID_SIZE);
    delete_grid(next_grid, GRID_SIZE);

    return 0;
}
