#include "common/heat.hpp"
#include <iostream>
#include <iomanip> // Для форматированного вывода

void simulation_step(double** grid, double** next_grid, int size, double c, double h, double tau) {
    double alpha = c * tau / (h * h);

    // Проходим по всем внутренним точкам сетки
    // Границы (i=0, i=size-1, j=0, j=size-1) не трогаем, там всегда 0
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            double laplacian = grid[i + 1][j] + grid[i - 1][j] + grid[i][j + 1] + grid[i][j - 1] - 4 * grid[i][j];
            next_grid[i][j] = grid[i][j] + alpha * laplacian;
        }
    }
}

void initialize_grid(double** grid, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = 0.0;
        }
    }
    // Ставим 1 в центральной точке
    if (size % 2 != 0) {
        int center = size / 2;
        grid[center][center] = 1.0;
    }
}

void print_grid(double** grid, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // Простой способ визуализации: чем больше значение, тем "плотнее" символ
            if (grid[i][j] > 0.8) std::cout << "@ ";
            else if (grid[i][j] > 0.5) std::cout << "O ";
            else if (grid[i][j] > 0.2) std::cout << "o ";
            else if (grid[i][j] > 0.01) std::cout << ". ";
            else std::cout << "  "; // Пробелы для нуля
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;
}