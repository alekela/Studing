#include <iostream>
#include <string.h>


using namespace std;


int check(string str, string letter) {
    for (int i = 0; i < str.length(); i++) {
        if (letter.find(str[i]) == -1) {
            return 0; 
        }
    }
    return 1;
}


int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return factorial(n - 1) * n;
}


int main(){
    string allowed = "1234567890";
    string a;
    cout << "Введите число: ";
    cin >> a;
    if (not check(a, allowed)) {
        cout << "Вы ввели не целое положительное число!" << endl;
    }
    else {
        int b = 0;
        b = std::stoi(a);
        if (b > 100000) {
            cout << "Слишком большое число!";
        }
        else {
            int ans = 1;
            for (int i = 1; i < b + 1; i++) {
                ans = ans * i;
            }
            cout << ans;
        }
    }

    return 0;
}