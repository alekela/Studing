#include <iostream>
#include <string.h>
#include <random>
#include <ctime>
#include <windows.h>

using namespace std; 


class Output_word {
    public:
    void set_word(string new_word) {
        word = new_word;
        len = word.length();
        for (int i = 0; i < len; i++){
            shown_word.push_back('-');
        }
    }

    void print_word() {
        cout << shown_word << endl;
    }

    int check_letter(char letter) {
        for (int i = 0; i < len; i++){
            if (word[i] == letter){
                open_letter(letter);
                return 1;
            }
        }
        return 0;
    }

    int count_dashes() {
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (word[i] != shown_word[i]) {
                ans++;
            }
        }
        return ans;
    }

    private:
    string word;
    string shown_word;
    int len;
    void open_letter(char letter) {
        for (int i = 0; i < len; i++){
            if (word[i] == letter){
                shown_word[i] = letter;
            }
         }
    }
};


class Narator {
    public:

    void set_word(string word) {
        hidden_word.set_word(word);
    }

    void say_start() {
        cout << "Как Вас зовут, игрок?" << endl;
        cin >> player_name;
        cout << "Добро пожаловать на игру Поле Чудес, " << player_name << ", начнём игру!" << endl;
    }

    void get_letter() {
        hidden_word.print_word();
        char letter;
        cout << player_name << ", назовите букву:" << endl;
        cin >> letter;
        while (check_error(letter)) {
            cout << "У Вас всё хорошо? Такой буквы даже нет в алфавите..." << endl;
            hidden_word.print_word();
            cout << player_name << ", назовите букву:" << endl;
            cin >> letter;
        }
        int ans = hidden_word.check_letter(letter);
        if (ans) {
            cout << "Верно!!! Откройте букву " << letter << "!!!" << endl;
        }
        else {
            cout << "Извините, такой буквы в слове нет!" << endl;
        }
    }

    bool check_word() {
        return hidden_word.count_dashes();
    }

    private:
    int check_error(char letter) {
        for (int i = 0; i < appropriate_letters.length(); i++) {
            if (appropriate_letters[i] == letter) {
                return 0;
            }
        }
        return 1;
    }

    string used_letters;
    string appropriate_letters = "йцукенгшщзхъфывапролдэячсмитьбюё";
    Output_word hidden_word;
    string player_name;
};


class Pole_chudes { 
    public:

    void start_game() {
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

    private:
    bool check_end() {
        return narator.check_word();
    }

    void end_game() {
        char ans;
        cout << "Хотите начать новую игру? Y/N";
        cin >> &ans;
        if (ans == 'Y' || ans == 'y') {
            start_game();
        }
    }

    Narator narator;
    string dictionary[3] = {"стегозавр", "молодец", "апертура"};
    int dictionary_len = 3;
}; 