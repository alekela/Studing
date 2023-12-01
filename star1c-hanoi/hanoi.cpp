#include <iostream>

using namespace std;


int hanoi(int n, int first, int second, int third){
    if (n == 1){
        cout << n << " —> " << third << endl;
    }
    else if (n == 2){
        cout << 1 << " —> " << second << endl;
        cout << 2 << " —> " << third << endl;
        cout << 1 << " —> " << third << endl;
    }
    else{
        hanoi(n - 1, first, second, third);
        cout << n << " —> " << second << endl;
        hanoi(n - 1, third, second, first);
        cout << n << " —> " << third << endl;
        hanoi(n - 1, first, second, third);
    }
    return 0;
}


int main()
{
    int n;
    cout << "Введите N: ";
    cin >> n;
    hanoi(n, 1, 2, 3);
    return 0;
}