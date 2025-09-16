#include <iostream>
#include <cstdlib>
#include <string>

// Структура элемента стека
struct StackNode {
    int index;          // Номер элемента
    void* data;         // Данные любого типа
    StackNode* next;    // Указатель на следующий элемент
};

// Структура стека
struct Stack {
    StackNode* top;     // Вершина стека
    int size;           // Размер стека
    size_t data_size;   // Размер одного элемента данных
};

// Создание нового стека
Stack* create_stack(size_t data_size) {
    Stack* stack = new Stack;
    stack->top = nullptr;
    stack->size = 0;
    stack->data_size = data_size;
    return stack;
}

// Добавление элемента на вершину стека
void push(Stack* stack, const void* data) {
    if (stack == nullptr || data == nullptr) return;
    
    StackNode* newNode = new StackNode;
    newNode->index = stack->size;
    newNode->data = malloc(stack->data_size);
    newNode->next = stack->top;
    
    // Копируем данные
    memcpy(newNode->data, data, stack->data_size);
    
    stack->top = newNode;
    stack->size++;
}

// Удаление верхнего элемента
bool pop(Stack* stack) {
    if (stack == nullptr || stack->top == nullptr) return false;
    
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp->data);   // Освобождаем данные
    delete temp;        // Освобождаем узел
    stack->size--;
    return true;
}

// Удаление всех элементов до указанного индекса (включительно)
void remove_until_index(Stack* stack, int target_index) {
    if (stack == nullptr || stack->top == nullptr || target_index < 0) return;
    
    // Удаляем элементы пока не дойдем до нужного индекса
    while (stack->top != nullptr && stack->top->index >= target_index) {
        pop(stack);
    }
}

// Просмотр верхнего элемента без удаления GUI решение уравнения теплопроводности двумерного
void* peek(const Stack* stack) {
    if (stack == nullptr || stack->top == nullptr) {
        return nullptr;
    }
    return stack->top->data;
}

// Проверка на пустоту
bool is_empty(const Stack* stack) {
    return (stack == nullptr || stack->top == nullptr);
}

// Очистка всего стека
void clear_stack(Stack* stack) {
    if (stack == nullptr) return;
    
    while (!is_empty(stack)) {
        pop(stack);
    }
}

// Удаление стека
void destroy_stack(Stack* stack) {
    if (stack == nullptr) return;
    
    clear_stack(stack);
    delete stack;
}

// Вспомогательные функции для демонстрации

// Вывод стека целых чисел
void display_int_stack(const Stack* stack) {
    if (stack == nullptr) return;
    
    StackNode* current = stack->top;
    std::cout << "Stack (size: " << stack->size << "): TOP -> ";
    while (current != nullptr) {
        std::cout << "[" << current->index << ": " << *(int*)current->data << "]";
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << " -> BOTTOM" << std::endl;
}

// Вывод стека строк
void display_string_stack(const Stack* stack) {
    if (stack == nullptr) return;
    
    StackNode* current = stack->top;
    std::cout << "Stack (size: " << stack->size << "): TOP -> ";
    while (current != nullptr) {
        std::cout << "[" << current->index << ": \"" << (char*)current->data << "\"]";
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << " -> BOTTOM" << std::endl;
}

// Вывод стека double
void display_double_stack(const Stack* stack) {
    if (stack == nullptr) return;
    
    StackNode* current = stack->top;
    std::cout << "Stack (size: " << stack->size << "): TOP -> ";
    while (current != nullptr) {
        std::cout << "[" << current->index << ": " << *(double*)current->data << "]";
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << " -> BOTTOM" << std::endl;
}

// Пример использования
int main() {
    std::cout << "=== Стек целых чисел ===" << std::endl;
    
    // Создаем стек для int
    Stack* int_stack = create_stack(sizeof(int));
    
    // Добавляем элементы
    for (int i = 1; i <= 5; i++) {
        push(int_stack, &i);
    }
    display_int_stack(int_stack);
    
    // Удаляем до индекса 2
    std::cout << "\nУдаляем до индекса 2:" << std::endl;
    remove_until_index(int_stack, 2);
    display_int_stack(int_stack);
    
    std::cout << "\n=== Стек строк ===" << std::endl;
    
    // Создаем стек для строк
    Stack* string_stack = create_stack(50);
    
    char str1[] = "Hello";
    char str2[] = "World";
    char str3[] = "C++";
    char str4[] = "Stack";
    
    push(string_stack, str1);
    push(string_stack, str2);
    push(string_stack, str3);
    push(string_stack, str4);
    display_string_stack(string_stack);
    
    // Удаляем до индекса 1
    std::cout << "\nУдаляем до индекса 1:" << std::endl;
    remove_until_index(string_stack, 1);
    display_string_stack(string_stack);
    
    std::cout << "\n=== Стек дробных чисел ===" << std::endl;
    
    // Создаем стек для double
    Stack* double_stack = create_stack(sizeof(double));
    
    double d1 = 3.14;
    double d2 = 2.71;
    double d3 = 1.41;
    
    push(double_stack, &d1);
    push(double_stack, &d2);
    push(double_stack, &d3);
    display_double_stack(double_stack);
    
    // Просмотр верхнего элемента
    double* top_value = (double*)peek(double_stack);
    if (top_value != nullptr) {
        std::cout << "\nВерхний элемент: " << *top_value << std::endl;
    }
    
    // Удаляем до индекса 0 (очищаем почти все)
    std::cout << "\nУдаляем до индекса 0:" << std::endl;
    remove_until_index(double_stack, 0);
    display_double_stack(double_stack);
    
    // Очищаем все стеки
    destroy_stack(int_stack);
    destroy_stack(string_stack);
    destroy_stack(double_stack);
    
    return 0;
}