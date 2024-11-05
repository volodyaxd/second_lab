#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <windows.h>
#include <limits>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Введите вещественные числа (введите 'end' для завершения ввода):" << std::endl;
    
    std::vector<double> numbers;
    double num;
    
    // Ввод чисел
    while (std::cin >> num) {
        numbers.push_back(num);
    }
    
    // Очищаем поток ввода после ввода чисел
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Копируем числа с четными порядковыми номерами (второе, четвертое и т.д.)
    std::cout << "Числа с четными порядковыми номерами:" << std::endl;

    std::ostream_iterator<double> out_it(std::cout, " ");
    
    std::remove_copy_if(numbers.begin(), numbers.end(), out_it, 
        [&](double value) {
            static int index = 0;
            return ++index % 2 != 0; // Условие для нечетных индексов
        }
    );

    return 0;
}
