#include <iostream>
#include <list>
#include <vector>
#include <numeric> // Для std::adjacent_difference
#include <iterator> // Для std::inserter
#include <windows.h>
#include <limits>

// Функциональный объект для вычисления среднего арифметического
class Average {
public:
    double operator()(int a, int b) const {
        return (a + b) / 2.0; // Возвращаем среднее арифметическое
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::list<int> L;
    int number;

    std::cout << "Введите целые числа (введите нечисловое значение для завершения ввода):" << std::endl;

    // Ввод данных пользователем
    while (std::cin >> number) {
        L.push_back(number);
    }

    // Очищаем флаг ошибок потока, чтобы можно было снова использовать cin
    std::cin.clear();
    // Игнорируем оставшиеся символы в буфере
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Создаем вектор для хранения средних значений
    std::vector<double> V;

    // Проверяем, что в списке больше одного элемента
    if (L.size() < 2) {
        std::cout << "Недостаточно элементов для вычисления средних значений." << std::endl;
        return 0;
    }

    // Используем std::adjacent_difference для вычисления средних значений
    std::vector<int> temp(L.begin(), L.end());
    std::adjacent_difference(temp.begin(), temp.end(), std::back_inserter(V), Average());

    // Удаляем первый элемент, так как он не нужен (это разность)
    V.erase(V.begin());

    // Выводим полученные средние значения
    std::cout << "Средние арифметические значения для соседних элементов:" << std::endl;
    for (const auto& avg : V) {
        std::cout << avg << std::endl;
    }

    return 0;
}
