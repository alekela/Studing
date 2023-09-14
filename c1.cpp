#include <iostream>
#include <float.h>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    vector<int> vect(5);
    vector<int> vect1(5, 2);           
    vector<int> vect2{1, 2, 3, 4, 5};
    int* arr1 = new int[5];
    int* arr2 = new int[5] {1, 2, 3, 4, 5};
    int arr3[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++){
        cout << vect[i] << "\n";
    }

    return 0;
}