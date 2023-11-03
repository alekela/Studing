#include <vector>
#include "Output_word.h"

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