#include <windows.h>
#include "8c_1.h"

using namespace std; 


void Output_word::set_word(string new_word) {
    word = new_word;
    len = word.length();
    for (int i = 0; i < len; i++){
        shown_word.push_back('-');
    }
}


int Output_word::check_letter(char letter) {
    for (int i = 0; i < len; i++){
        if (word[i] == letter){
            open_letter(letter);
            return 1;
        }
    }
    return 0;
}

int Output_word::count_dashes() {
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (word[i] != shown_word[i]) {
            ans++;
        }
    }
    return ans;
}

void Output_word::open_letter(char letter) {
    for (int i = 0; i < len; i++){
        if (word[i] == letter){
            shown_word[i] = letter;
        }
        }
}


void Narator::set_word(string word) {
    hidden_word.set_word(word);
}

void Narator::say_start() {
    cout << "What is your name?" << endl;
    cin >> player_name;
    cout << "Welcome to your game, " << player_name << ", let's start!" << endl;
}

void Narator::get_letter() {
    hidden_word.print_word();
    char letter;
    cout << player_name << ", give a letter:" << endl;
    cin >> letter;
    check_error(letter);
    int ans = hidden_word.check_letter(letter);
    if (ans) {
        cout << "Right!!! Open the letter " << letter << "!!!" << endl;
    }
    else {
        cout << "Sorry, there is no such letter!" << endl;
    }
}

bool Narator::check_word() {
    return hidden_word.count_dashes();
}

void Narator::check_error(char letter) {
    bool flag = true;
    for (int i = 0; i < appropriate_letters.length(); i++) {
        if (appropriate_letters[i] == letter) {
            flag = false;
        }
    }
    if (flag) {
        throw exception();
    }
}


void Pole_chudes::start_game() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(nullptr));
    narator.set_word(dictionary[rand() % dictionary_len]);
    narator.say_start();
    while(check_end()) {
        try {
            narator.get_letter();
        }
        catch (exception) {
            cout << "Are you serious? There is not a letter at all..." << endl;
        }
    }
    end_game();
}

bool Pole_chudes::check_end() {
    return narator.check_word();
}

void Pole_chudes::end_game() {
    char ans;
    cout << "Would you like to start a new game? Y/N" << endl;
    cin >> &ans;
    if (ans == 'Y' || ans == 'y') {
        start_game();
    }
}