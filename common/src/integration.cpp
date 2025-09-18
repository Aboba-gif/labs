#include "common/integration.hpp" // Подключаем наш заголовочный файл

double trapezoidal_rule(const std::function<double(double)>& func, double a, double b, int n) {
    if (n <= 0) {
        throw std::invalid_argument("Количество интервалов должно быть больше нуля.");
    }

    double h = (b - a) / n;
    // Обратите внимание: func(a) и func(b) вызываются точно так же, как и раньше.
    double sum = 0.5 * (func(a) + func(b));

    for (int i = 1; i < n; ++i) {
        sum += func(a + i * h); // формула Ньютона - Котса
    }

    return sum * h;
}