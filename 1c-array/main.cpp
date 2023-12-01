#include <iostream>
#include <float.h>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    //task 1
    vector<int> vect(5);
    vector<int> vect1(5, 2);           
    vector<int> vect2{1, 2, 3, 4, 5};
    int* arr1 = new int[5];
    int* arr2 = new int[5] {1, 2, 3, 4, 5};
    int arr3[5] = {1, 2, 3, 4, 5};
    int* arr4 = (int *) malloc(sizeof(int) * 5);
    int * arr5 = (int *) calloc(5, sizeof(int));
    int* arr6;
    arr6 = (int *) realloc(arr6, 5 * sizeof(int));

    /*for (int i = 0; i < 5; i++){
        arr6[i] = i;
    }
    
    for (int i = 0; i < 5; i++){
        cout << arr6[i] << "\n";
    }*/

    // task 2
    double **p = 0;
    p = new double* {new double {2}};
    cout << **p;
    delete *p;
    delete p;
    return 0;
}