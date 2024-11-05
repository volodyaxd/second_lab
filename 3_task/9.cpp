#include <iostream>
#include <deque>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::deque<int> myDeque;
    int n;
    std::cout << "Введите количество элементов дека (должно быть кратно 4): ";
    std::cin >> n;
    // Заполнение дека
    for (int i = 0; i < n; i++) {
        int val;
        std::cout << "Введите " << i + 1 << " элемент дека: ";
        std::cin >> val;
        myDeque.push_back(val);
    }
    // Удаление элементов с четными порядковыми номерами
    auto it = myDeque.begin();
    for (int i = 0; i < n / 4; i++) {
        it = myDeque.erase(it + i * 2);
    }
    // Вывод элементов дека
    std::cout << "Элементы дека: ";
    for (it = myDeque.begin(); it != myDeque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // Вывод элементов дека в обратном порядке
    std::cout << "Элементы дека в обратном порядке: ";
    for (auto rit = myDeque.rbegin(); rit != myDeque.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    return 0;
}
