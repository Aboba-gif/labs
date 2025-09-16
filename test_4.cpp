#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>
#include <locale>

// BST - Дерево Бинарного Поиска
struct Node {
    long double key;
    Node* left;
    Node* right;
};

Node* buildBalanced(const long double* a, long long l, long long r) {
    if (l >= r) return nullptr;
    long long m = l + (r - l) / 2;  // long long для больших N
    Node* n = new Node{a[m], nullptr, nullptr};
    n->left = buildBalanced(a, l, m);
    n->right = buildBalanced(a, m + 1, r);
    return n;
}

// Ищем predecessor (max < target) и successor (min >= target)
std::pair<const Node*, const Node*> findPredSucc(const Node* root, long double target) {
    const Node* pred = nullptr;
    const Node* succ = nullptr;
    while (root) {
        if (root->key >= target) {
            succ = root;
            root = root->left;
        } else {
            pred = root;
            root = root->right;
        }
    }
    return {pred, succ};
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
// -------------------------------------------------------------

int main(int argc, char* argv[]) {
    std::locale::global(std::locale("C"));  // Фикс локали для . в doubles
    if (argc != 4) {
        std::cerr << "Использование: " << argv[0] << " N start target" << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Объявляем переменные заранее, чтобы они были в scope
    long long N = 0;
    long double start = 0.0L;
    long double target = 0.0L;

    try {
        N = std::stoll(argv[1]);
        start = std::stold(argv[2]);
        target = std::stold(argv[3]);
    } catch(const std::exception& e) {
        std::cerr << "Ошибка парсинга: " << e.what() << std::endl;
        return 1;
    }

    if (N <= 0) {
        std::cout << "Не найдено\n";
        return 0;
    }

    long double* data = new long double[N];

    // Генерация данных
    long double current = start;
    for (long long i = 0; i < N; i++) {
        data[i] = current;
        current += static_cast<long double>(std::rand()) / RAND_MAX + 1e-10;  // +минимальный шаг для уникальности
    }

    // Линейный поиск
    auto t_lin_start = std::chrono::high_resolution_clock::now();
    long double* it = data;
    for (; it != data + N; ++it) {
        if (*it >= target) break;
    }
    auto t_lin_end = std::chrono::high_resolution_clock::now();

    // Вывод интервала (линейный)
    if (it != data + N) {  // Есть succ
        if (it != data) {
            std::cout << *(it - 1) << " " << *it << '\n';
        } else {
            std::cout << *it << '\n';
        }
    } else {  // Только pred
        std::cout << data[N-1] << '\n';
    }
    std::cout << "Линейный поиск занял: "
              << std::chrono::duration_cast<std::chrono::microseconds>(t_lin_end - t_lin_start).count()
              << " мкс\n";

    // Бинарный поиск
    auto t_bin_start = std::chrono::high_resolution_clock::now();
    long long left = 0, right = N - 1, result = -1;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (data[mid] >= target) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    auto t_bin_end = std::chrono::high_resolution_clock::now();

    // Вывод интервала (бинарный)
    if (result != -1) {  // Есть succ
        if (result > 0) {
            std::cout << data[result - 1] << " " << data[result] << '\n';
        } else {
            std::cout << data[result] << '\n';
        }
    } else {  // Только pred
        std::cout << data[N-1] << '\n';
    }
    std::cout << "Бинарный поиск занял: "
              << std::chrono::duration_cast<std::chrono::microseconds>(t_bin_end - t_bin_start).count()
              << " мкс\n";

    // Построение дерева и поиск в дереве
    auto t_build_start = std::chrono::high_resolution_clock::now();
    Node* root = buildBalanced(data, 0, N);
    auto t_build_end = std::chrono::high_resolution_clock::now();

    auto t_tree_search_start = std::chrono::high_resolution_clock::now();
    auto [pred, succ] = findPredSucc(root, target);
    auto t_tree_search_end = std::chrono::high_resolution_clock::now();

    // Вывод интервала (дерево)
    if (pred && succ) {
        std::cout << pred->key << " " << succ->key << '\n';
    } else if (succ) {
        std::cout << succ->key << '\n';
    } else if (pred) {
        std::cout << pred->key << '\n';
    } else {
        std::cout << "Не найдено\n";
    }
    std::cout << "Построение дерева заняло: "
              << std::chrono::duration_cast<std::chrono::microseconds>(t_build_end - t_build_start).count()
              << " мкс\n";
    std::cout << "Поиск в дереве занял: "
              << std::chrono::duration_cast<std::chrono::microseconds>(t_tree_search_end - t_tree_search_start).count()
              << " мкс\n";

    freeTree(root);
    delete[] data;
    return 0;
}