#include <iostream>
#include <vector>
#include <list>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::vector<int> V;
    std::list<int> L;

    int num;
    
    // Ввод данных для вектора
    std::cout << "Введите 6 элементов для вектора (целые числа): " << std::endl;
    for (int i = 0; i < 6; ++i) {
        std::cin >> num;
        V.push_back(num);
    }

    // Ввод данных для списка
    std::cout << "Введите 7 элементов для списка (целые числа): " << std::endl;
    for (int i = 0; i < 7; ++i) {
        std::cin >> num;
        L.push_back(num);
    }

    // Убедимся, что вектор содержит как минимум 5 элементов
    if (V.size() < 5) {
        std::cerr << "Вектор должен содержать как минимум 5 элементов." << std::endl;
        return 1;
    }

    // Найдем итератор на 5-й элемент списка
    std::list<int>::iterator it = L.begin();
    std::advance(it, 4); // Перемещаем итератор на 5-й элемент

    // Вставка первых 5 элементов вектора в обратном порядке
    L.insert(it, V.rbegin(), V.rbegin() + 5);

    // Вывод элементов списка
    std::cout << "Элементы списка: ";
    for (const auto& elem : L) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
