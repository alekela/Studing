#ifndef NARATOR
#define NARATOR

#include <iostream>
#include <vector>
#include "Output_word.h"

using namespace std;

class Narator {
    public:
    void set_word(string word);

    void say_start();

    void get_letter();

    bool check_word();

    private:
    int check_error(char letter);
    string used_letters;
    string appropriate_letters = "��������������������������������";
    Output_word hidden_word;
    string player_name;
};

#endif