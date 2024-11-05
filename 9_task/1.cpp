#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Вектор V0
    std::vector<int> V0;
    int sizeV0;

    std::cout << "Введите количество элементов вектора V0: ";
    std::cin >> sizeV0;

    std::cout << "Введите элементы вектора V0: ";
    for (int i = 0; i < sizeV0; ++i) {
        int element;
        std::cin >> element;
        V0.push_back(element);
    }

    // Удаляем дубликаты, создавая множество из V0
    std::set<int> uniqueV0(V0.begin(), V0.end());

    // Число векторов
    int N;
    std::cout << "Введите количество векторов N: ";
    std::cin >> N;

    int count = 0; // Счетчик векторов, содержащих все элементы V0

    for (int i = 1; i <= N; ++i) {
        std::vector<int> Vi;
        int sizeVi;

        std::cout << "Введите количество элементов вектора V" << i << ": ";
        std::cin >> sizeVi;

        std::cout << "Введите элементы вектора V" << i << ": ";
        for (int j = 0; j < sizeVi; ++j) {
            int element;
            std::cin >> element;
            Vi.push_back(element);
        }

        // Удаляем дубликаты, создавая множество из Vi
        std::set<int> uniqueVi(Vi.begin(), Vi.end());

        // Проверяем, содержит ли uniqueVi все элементы uniqueV0
        if (std::includes(uniqueVi.begin(), uniqueVi.end(), uniqueV0.begin(), uniqueV0.end())) {
            count++;
        }
    }

    std::cout << "Количество векторов, содержащих все элементы V0: " << count << std::endl;

    return 0;
}
