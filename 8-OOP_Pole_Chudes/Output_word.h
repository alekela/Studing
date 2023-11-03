#ifndef OUTPUT_WORD
#define OUTPUT_WORD

#include <iostream>
#include <string>

using namespace std;

class Output_word {
    public:
    void set_word(string new_word);

    void print_word() {cout << shown_word << endl;}

    int check_letter(char letter);

    int count_dashes();

    private:
        string word;
        string shown_word;
        int len;
        void open_letter(char letter);
};

#endif