#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::vector<int> L;
    int n;

    std::cout << "Введите количество элементов в списке: ";
    std::cin >> n;

    std::cout << "Введите элементы списка (целые числа): ";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        L.push_back(value);
    }

    // Найти первый отрицательный элемент
    auto first_neg = std::find_if(L.begin(), L.end(), [](int x) { return x < 0; });
    // Найти последний положительный элемент
    auto last_pos = std::find_if(L.rbegin(), L.rend(), [](int x) { return x > 0; });

    if (first_neg != L.end() && last_pos.base() != L.begin()) {
        // Вставить 0 после первого отрицательного элемента
        L.insert(++first_neg, 0);
        // Вставить 0 перед последним положительным элементом
        L.insert(last_pos.base(), 0);
    }

    // Вывод результата
    std::cout << "Результат: ";
    for (int x : L) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
