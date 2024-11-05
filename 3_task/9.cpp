#include <iostream>
#include <deque>

int main() {
    int n;
    std::cout << "Введите количество элементов в деке (кратное 4): ";
    std::cin >> n;

    // Проверка, что количество элементов кратно 4
    if (n % 4 != 0) {
        std::cerr << "Количество элементов должно быть кратно 4." << std::endl;
        return 1;
    }

    std::deque<int> d;
    std::cout << "Введите " << n << " элементов дека: ";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        d.push_back(value);
    }

    // Удаление элементов с четными порядковыми номерами в первой половине дека
    int half_size = n / 2;
    for (int i = 0; i < half_size / 2; ++i) {
        auto it = d.begin() + (2 * i + 1); // Четные номера (2, 4, ...) в первой половине
        it = d.erase(it); // Удаляем элемент и обновляем итератор
    }

    // Вывод оставшихся элементов дека
    std::cout << "Оставшиеся элементы дека: ";
    for (const int& value : d) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
