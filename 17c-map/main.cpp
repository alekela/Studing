#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "windows.h"


using namespace std;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    map<char, long int> freqs;
    string alphabet = "¸יצףךוםדרשחץתפûגאןנמכהז‎ÿקסלטעüב‏"; 
    for (int i = 0; i < 33; i++) {
        freqs[alphabet[i]] = 0;
    }

    ifstream file;
    string data;
    file.open ("example.txt");
    file >> data;
    while (file) {
        // מבנאבמעךא data
        for (auto& i : data) {
            i = tolower(i);
            freqs[i]++;
        }
        file >> data;
    }
    file.close();
    for (int i = 0; i < 33; i++) {
        if (freqs[alphabet[i]] != 0) {
            cout << alphabet[i] << "  " << freqs[alphabet[i]] << endl;
        }
    }
    return 0;
}