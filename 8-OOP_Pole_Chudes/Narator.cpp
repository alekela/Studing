#include "Narator.h"

using namespace std;


void Narator::set_word(string word) {
    hidden_word.set_word(word);
}

void Narator::say_start() {
    cout << "Как Вас зовут, игрок?" << endl;
    cin >> player_name;
    cout << "Добро пожаловать в игру, " << player_name << ", давайте начнём!" << endl;
}

void Narator::get_letter() {
    hidden_word.print_word();
    char letter;
    cout << player_name << ", введите букву:" << endl;
    cin >> letter;
    while (check_error(letter)) {
        cout << "У вас всё хорошо? Такой буквы даже нет в алфавите..." << endl;
        hidden_word.print_word();
        cout << player_name << ", введите букву:" << endl;
        cin >> letter;
    }
    int ans = hidden_word.check_letter(letter);
    if (ans) {
        cout << "Верно!!! Откройте букву " << letter << "!!!" << endl;
    }
    else {
        cout << "Неправильно, такой буквы в слове нет!" << endl;
    }
}

bool Narator::check_word() {
    return hidden_word.count_dashes();
}

int Narator::check_error(char letter) {
    for (int i = 0; i < appropriate_letters.length(); i++) {
        if (appropriate_letters[i] == letter) {
            return 0;
        }
    }
    return 1;
}
