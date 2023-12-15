#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "windows.h"
#include <clocale> //Обязательно для функции setlocale()



using namespace std;


struct Rchar
{
    char first;
    char second;
};


int main() {
    map<wchar_t, long int> freqs;
    char char_alphabet[33] = {'ё', 'й', 'ц','у','к','е','н','г','ш',
    'щ','з','х','ъ','ф','ы','в','а','п','р','о','л','д','ж','э',
    'я','ч','с','м','и','т','ь','б','ю'};

    wchar_t alphabet[33] = {'ё', 'й', 'ц','у','к','е','н','г','ш',
    'щ','з','х','ъ','ф','ы','в','а','п','р','о','л','д','ж','э',
    'я','ч','с','м','и','т','ь','б','ю'};
    for (int i = 0; i < 33; i++) {
        freqs[alphabet[i]] = 0;
    }

    ifstream file;
    string data;
    file.open ("example.txt");
    file >> data;
    Rchar tmp;
    wchar_t letter;
    int flag = 0;
    while (file) {
        for (char i : data) {
            if (flag == 0) {
                tmp.first = i;
                flag++;
            }
            else if (flag == 1) {
                tmp.second = i;
                flag++;
            }
            if (flag == 2) {
                letter = ((int) tmp.first + 256) * 256 + 256 + (int)tmp.second;
                freqs[letter]++;
                flag = 0;
            }
        }
        file >> data;
    }
    file.close();
    for (int i = 0; i < 33; i++) {
        if (freqs[alphabet[i]] != 0) {
            cout << (char) (int)alphabet[i] << "  " << freqs[alphabet[i]] << endl;
        }
    }
    return 0;
}