#include <iostream>
#include <string.h>
#include <excpt.h>


using namespace std;


int check(string str, string letter) {
    for (int i = 0; i < str.length(); i++) {
        if (letter.find(str[i]) == -1) {
            return 0;
        }
    }
    return 1;
}


int fibbonachi(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return fibbonachi(n - 1) + fibbonachi(n - 2);
}


int main() {
    string allowed = "1234567890";
    string a;
    cout << "Введите число: ";
    cin >> a;
    if (not check(a, allowed)) {
        cout << "Вы ввели не целое положительное число!" << endl;
    }
    else {
        unsigned long long int b = 0;
        b = std::stoi(a);
        if (b > 1000) {
            cout << "Слишком большое число!";
        }
        else if (b == 0) {
            cout << "Ноль вводить нельзя!";
        }
        else {
            try {
                unsigned long long int f1 = 1;
                unsigned long long int f2 = 1;
                unsigned long long int tmp;
                for (int i = 1; i < b + 1; i++) {
                    cout << f1 << " ";
                    tmp = f1;
                    f1 = f2;
                    if (INT64_MAX - tmp < f2) {
                        throw "Overflow!";
                    }
                    f2 = f2 + tmp;
                }
            }
            catch(const char* error_message){
                cout << error_message;
            }
        }
    }

    return 0;
}
