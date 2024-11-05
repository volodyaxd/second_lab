#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <windows.h>

template <typename Container>
void doubleElements(Container& container) {
    auto it = container.begin();
    auto midIt = container.begin();
    std::advance(midIt, container.size() / 2);
    auto lastIt = std::prev(container.end());

    *it *= 2;           // Удвоить первый элемент
    *midIt *= 2;       // Удвоить средний элемент
    *lastIt *= 2;      // Удвоить последний элемент
}

template <typename Container>
void printContainer(const Container& container) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void printContainerReverse(const Container& container) {
    for (auto it = container.rbegin(); it != container.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int size;

    // Запрос размера контейнеров
    std::cout << "Введите количество элементов (нечетное число, минимум 3): ";
    std::cin >> size;

    if (size < 3 || size % 2 == 0) {
        std::cout << "Неверное количество элементов!" << std::endl;
        return 1;
    }

    // Создание контейнеров
    std::vector<int> V(size);
    std::deque<int> D(size);
    std::list<int> L;

    std::cout << "Введите элементы для вектора V: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> V[i];
    }

    std::cout << "Введите элементы для дека D: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> D[i];
    }

    std::cout << "Введите элементы для списка L: ";
    for (int i = 0; i < size; ++i) {
        int value;
        std::cin >> value;
        L.push_back(value);
    }

    // Удвоение элементов
    doubleElements(V);
    doubleElements(D);
    doubleElements(L);

    // Вывод элементов
    std::cout << "Vector V: ";
    printContainer(V);
    std::cout << "Deque D: ";
    printContainer(D);
    std::cout << "List L: ";
    printContainer(L);

    // Вывод в обратном порядке
    std::cout << "Reverse Vector V: ";
    printContainerReverse(V);
    std::cout << "Reverse Deque D: ";
    printContainerReverse(D);
    std::cout << "Reverse List L: ";
    printContainerReverse(L);

    return 0;
}
