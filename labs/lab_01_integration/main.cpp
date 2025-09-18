#include <iostream>
#include <cmath>
#include <vector>

// Подключаем нашу новую библиотеку!
#include "common/integration.hpp"

// Примеры простых функций для интегрирования (остаются здесь, т.к. специфичны для лабы)
double func_sin(double x) {
    return sin(x);
}

double func_exp(double x) {
    return exp(-x * x);
}

int main() {
    try {
        const int N = 1000; // Количество точек разбиения

        std::cout << "--- Lab 01: Numerical Integration ---" << std::endl;

        // Тест 1: Интеграл от sin(x) на [0, PI]. Ожидаемый результат: 2.0
        double integral_sin = trapezoidal_rule(func_sin, 0, 3.14, N);
        std::cout << "Integral of sin(x) on [0, PI]: " << integral_sin << std::endl;

        // Тест 2: Интеграл от exp(-x^2) на [-2, 2] (близко к интегралу Пуассона)
        double integral_exp = trapezoidal_rule(func_exp, -2, 2, N);
        std::cout << "Integral of exp(-x^2) on [-2, 2]: " << integral_exp << std::endl;

        // Тест 3: Интеграл от x^3 на [-1, 1] с помощью лямбда-функции. Ожидаемый результат: 0.0
        // Демонстрация мощи std::function: мы передаем функцию "на лету"!
        double integral_cube = trapezoidal_rule(
            [](double x) { return x * x * x; }, // Лямбда-функция
            -1.0, 1.0, N
        );
        std::cout << "Integral of x^3 on [-1, 1]: " << integral_cube << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}