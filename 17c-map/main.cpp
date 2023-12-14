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
    map<int, long int> freqs;
    int alphabet[33] = {'ё', 'й', 'ц','у','к','е','н','г','ш',
    'щ','з','х','ъ','ф','ы','в','а','п','р','о','л','д','ж','э',
    'я','ч','с','м','и','т','ь','б','ю'};
    for (int i = 0; i < 33; i++) {
        freqs[alphabet[i]] = 0;
    }

    ifstream file;
    string data;
    file.open ("example.txt");
    file >> data;
    while (file) {
        // обработка data
        for (auto i : data) {
            if (i < -32 && i > -65) {
                i += 32;
            }
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