#include <iostream>
#include <string.h>


using namespace std;


int check(string str, string letter){
    for (int i = 0; i < str.length(); i++){
        if (letter.find(str[i]) == -1){
            return 0;
        }
    }
    return 1;
}


int main(){
    string allowed = "1234567890";
    string a;
    cout << "Введите число: ";
    cin >> a;
    if (not check(a, allowed)){
        cout << "Вы ввели не целое положительное число!" << endl;
    }
    else{
        int b = 0;
        b = std::stoi(a);
        if (b > 100){
            cout << "Слишком большое число!";
        }
        else if (b == 0){
            cout << "Ноль вводить нельзя!";
        }
        else{
            int f1 = 1;
            int f2 = 1;
            int tmp;
            for (int i = 1; i < b + 1; i++){
                cout << f1 << " ";
                tmp = f1;
                f1 = f2;
                f2 = f2 + tmp;
            }
        }
    }

    return 0;
}
