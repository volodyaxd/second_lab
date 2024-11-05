#include <iostream>
#include <vector>
#include <list>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Создаем вектор и список
    std::vector<int> V;
    std::list<int> L;

    // Заполнение вектора
    std::cout << "Введите элементы для вектора (введите 'q' для завершения ввода):" << std::endl;
    while (true) {
        int value;
        std::cin >> value;
        V.push_back(value);
        if (std::cin.peek() == '\n') break; // Завершение ввода по новой строке
    }

    // Заполнение списка
    std::cout << "Введите элементы для списка (введите 'q' для завершения ввода):" << std::endl;
    while (true) {
        int value;
        std::cin >> value;
        L.push_back(value);
        if (std::cin.peek() == '\n') break; // Завершение ввода по новой строке
    }

    // Проверяем, достаточно ли элементов в списке
    if (std::distance(L.begin(), L.end()) < 6) {
        std::cout << "В списке должно быть не менее 6 элементов." << std::endl;
        return 1;
    }

    // Находим итератор на 5-й элемент списка (отсчет с 0)
    auto it = L.begin();
    std::advance(it, 5); // Перемещаем итератор на 5-й элемент

    // Вставляем первые 5 элементов вектора в обратном порядке
    L.insert(it, V.rbegin(), V.rbegin() + 5);

    // Вывод элементов списка
    std::cout << "Элементы списка после вставки:" << std::endl;
    for (const auto& elem : L) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Вывод элементов списка в обратном порядке
    std::cout << "Элементы списка в обратном порядке:" << std::endl;
    for (auto i = L.rbegin(); i != L.rend(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}
