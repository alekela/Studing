#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

int check(string str, char letter){
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == letter) {
            return 1;
        }
    }
    return 0;
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string word;
    string alphabet = "��������������������������������";
    string used_letters = "";
    string shown_word;
    int alph_len = alphabet.length();
    char letter;
    cout << "������� �����: ";
    cin >> word;
    int len = word.length();
    for (int i = 0; i < len; i++) {
        if (not check(alphabet, word[i])) {
            cout << "�� ����������� ����� �����!";
            exit(-1);
        }
    }

    for (int i = 0; i < len; i++) {
        shown_word.push_back('-');
    }
    bool flag = true;
    while (flag) {
        cout <<  "�����: " << shown_word << endl;
        cout << "������� �����: ";
        cin >> letter;
        if (check(used_letters, letter)) {
            cout << "�� ��� ������������ ��� �����!" << endl;
        }
        else if (not check(alphabet, letter)) {
            cout << "����� ����� ��� � ��������!" << endl;
        }
        else if (not check(word, letter)) {
            cout << "����� ����� � ����� ���!" << endl;

        }
        else if (check(word, letter)) {
            cout << "�����, �������� ����� " << letter << "!" << endl;
            used_letters.push_back(letter);
            for (int i = 0; i < len; i++) {
                if (word[i] == letter) {
                    shown_word[i] = letter;
                }
            }
        }
        if (not check(shown_word, '-')) {
            flag = false;
        }
        cout << endl;
    }

    cout << "����������, �� �������� ����� " << word << "!" << endl;
    return 0;
}