#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <windows.h>

using namespace std;


void stat_tolstoy(string name) {
    map<char, int> alphabet{};
    char c;

    for (int i = 0, c = 'À'; i < 33; ++i,++c){
        alphabet[c] = 0;
    }  

    string s;
    ifstream file(name);

    while(getline(file, s)){ 
        for(const auto& i : s) {
            if ('À' <= i && i <= 'ß'){
                alphabet[i]++;
            }
            else if ('à' <= i && i <= 'ÿ'){
                alphabet[char(toupper(i))]++;
            }
        }

    }
    file.close();
    for (auto it = alphabet.begin(); it != alphabet.end(); ++it){
        cout << (*it).first << " : " << (*it).second << endl;
    }
    cout << endl << endl;
}


int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    stat_tolstoy("volume_1.txt");
    stat_tolstoy("volume_2.txt");
    stat_tolstoy("volume_3.txt");
    stat_tolstoy("volume_4.txt");
    return 0;
}