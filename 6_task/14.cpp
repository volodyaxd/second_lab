#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n;

    // Запрос количества элементов у пользователя
    std::cout << "Введите четное количество элементов вектора: ";
    std::cin >> n;

    // Проверяем, что количество элементов четное
    if (n % 2 != 0) {
        std::cout << "Количество элементов должно быть четным!" << std::endl;
        return 1;
    }

    std::vector<int> V(n);

    // Ввод элементов вектора
    std::cout << "Введите элементы вектора: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i];
    }

    // Выделяем вторую половину вектора
    std::vector<int> V0(V.begin() + n / 2, V.end());

    // Вектор для хранения положительных элементов
    std::vector<int> positives;

    // Копируем положительные элементы из второй половины вектора V0
    std::copy_if(V0.begin(), V0.end(), std::back_inserter(positives),
                 [](int x) { return x > 0; });

    // Объединяем положительные элементы с первоначальными элементами вектора V
    V.insert(V.begin(), positives.begin(), positives.end());

    // Выводим результат
    std::cout << "Результат: ";
    for (const int &elem : V) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
