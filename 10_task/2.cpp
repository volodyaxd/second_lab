#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::vector<std::string> V;
    std::string word;

    std::cout << "Введите английские слова (введите 'stop' для завершения ввода):" << std::endl;

    // Ввод слов пользователем
    while (true) {
        std::cin >> word;
        if (word == "stop") {
            break;
        }
        V.push_back(word);
    }

    // Создаем отображение для хранения суммарной длины слов по начальным буквам
    std::unordered_map<char, int> M;

    // Заполняем отображение M
    for (const auto& w : V) {
        char firstLetter = w[0]; // Первая буква слова
        M[firstLetter] += w.size(); // Увеличиваем длину для этой буквы
    }

    // Создаем вектор для хранения уникальных букв
    std::vector<char> letters;
    for (const auto& entry : M) {
        letters.push_back(entry.first);
    }

    // Сортируем буквы в алфавитном порядке
    std::sort(letters.begin(), letters.end());

    // Выводим результаты
    std::cout << "Суммарная длина слов по начальным буквам:" << std::endl;
    for (const auto& letter : letters) {
        std::cout << letter << ": " << M[letter] << std::endl; // Выводим букву и суммарную длину
    }

    return 0;
}
