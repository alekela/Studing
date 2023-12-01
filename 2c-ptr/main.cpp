#include <iostream>

using namespace std;


int main(){
    double **p = 0;
    p = new double* {new double {2}};
    cout << **p;
    delete *p;
    delete p;
    return 0;
    }