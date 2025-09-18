#pragma once

// Функция для одного шага симуляции уравнения теплопроводности
// Принимает текущую сетку `grid` и записывает результат в `next_grid`
void simulation_step(double** grid, double** next_grid, int size, double c, double h, double tau);

// Функция для инициализации сетки согласно начальным условиям
// В центре 1, в остальных местах 0.
void initialize_grid(double** grid, int size);

// Функция для красивой печати сетки в консоль
void print_grid(double** grid, int size);