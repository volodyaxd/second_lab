#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <windows.h>

class Compare {
public:
    bool operator()(const std::string& a, const std::string& b) const {
        // Сравниваем по длине (по убыванию)
        if (a.size() != b.size()) {
            return a.size() > b.size();
        }
        // Если длины одинаковые, сравниваем в алфавитном порядке
        return a < b;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::deque<std::string> words;
    std::string word;

    std::cout << "Введите английские слова (введите 'stop' для завершения ввода):" << std::endl;

    // Ввод слов пользователем
    while (true) {
        std::cin >> word;
        if (word == "stop") {
            break;
        }
        words.push_back(word);
    }

    // Сортировка с использованием функционального объекта
    std::sort(words.begin(), words.end(), Compare());

    // Вывод отсортированных слов
    std::cout << "\nОтсортированные слова:" << std::endl;
    for (const auto& w : words) {
        std::cout << w << std::endl;
    }

    return 0;
}
