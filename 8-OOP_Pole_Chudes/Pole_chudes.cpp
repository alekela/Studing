#include <windows.h>
#include "Pole_chudes.h"
#include <ctime>


void Pole_chudes::start_game() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(nullptr));
    narator.set_word(dictionary[rand() % dictionary_len]);
    narator.say_start();
    while(check_end()) {
        narator.get_letter();
    }
    end_game();
}

bool Pole_chudes::check_end() {
    return narator.check_word();
}

void Pole_chudes::end_game() {
    char ans;
    cout << "Хотите начать новую игру? Y/N";
    cin >> &ans;
    if (ans == 'Y' || ans == 'y') {
        start_game();
    }
}
