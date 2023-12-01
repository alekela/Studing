#include <iostream>
#include <string>

using namespace std;

template <class T>

T min(T&a, T&b) {
    return a < b ? a : b;
}


int main() {
    string s1 = "123";
    string s2 = "234";
    cout << min(s1, s2) << endl;
    cout << min<double>(2, 1.0);
}