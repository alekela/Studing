#ifndef POLE
#define POLE


#include <iostream>
#include <random>
#include <ctime>
#include <string.h>

using namespace std;


class Output_word {
    public:
    void set_word(string new_word);

    void print_word() {std::cout << shown_word << std::endl;}

    int check_letter(char letter);

    int count_dashes();

    private:
    string word;
    string shown_word;
    int len;
    void open_letter(char letter);
};


class Narator {
    public:
    void set_word(string word);

    void say_start();

    void get_letter();

    bool check_word();

    private:
    void check_error(char letter);
    string used_letters;
    string appropriate_letters = "ёйцукенгшщзхъфывапролджэячсмитьбю";
    Output_word hidden_word;
    string player_name;
};


class Pole_chudes { 
    public:

    void start_game();

    private:
    bool check_end();

    void end_game();
    Narator narator;
    string dictionary[3] = {"стегозавр", "молодец", "корова"};
    int dictionary_len = 3;
}; 

#endif