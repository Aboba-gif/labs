#pragma once // Современная и простая замена традиционным include guards

#include <functional> // Для использования std::function
#include <stdexcept>  // Для std::invalid_argument

/**
 * @brief Вычисляет определенный интеграл функции с помощью метода трапеций.
 * 
 * @param func Интегрируемая функция. Использует std::function для гибкости.
 * @param a Нижний предел интегрирования.
 * @param b Верхний предел интегрирования.
 * @param n Количество интервалов разбиения.
 * @return Приблизительное значение интеграла.
 */
double trapezoidal_rule(const std::function<double(double)>& func, double a, double b, int n);

//   Ключевое улучшение: Мы заменили C-стиль указателя на функцию double (*func)(double) на std::function<double(double)>.
//   Почему это лучше? std::function — это полиморфная обертка. Она может хранить не только обычные функции,
// но и лямбда-функции, и объекты-функторы. Это делает ваш код гораздо более гибким и современным