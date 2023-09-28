#include <iostream>
#include <ctime>

using namespace std;

bool check_bites(unsigned int a) {
    return not (a << 31);
}


bool check_bites_2(unsigned int a) {
    unsigned int b = a >> 1;
    b = b << 1;
    return (a == b);
}


bool usual_check(unsigned int a) {
    return not (a % 2);
}


int main() {
    clock_t start, finish;
    long long int n = 300000;
    unsigned int numbers[n];
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1;
    }
    bool result;

    time_t res = time(nullptr);
    start = clock();
    for (int i = 0; i < n; i++) {
        result = usual_check(numbers[i]);
    }
    finish = clock();
    cout << "Time of one cycle of usual_check: " << ((float) finish - (float) start) / CLOCKS_PER_SEC  << endl;

    start = clock();
    for (int i = 0; i < n; i++) {
        result = check_bites(numbers[i]);
    }
    finish = clock();
    cout << "Time of one cycle of check_bites: " << (double)(finish - start) / CLOCKS_PER_SEC;
}
