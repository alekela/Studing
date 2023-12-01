#include <iostream>
#include <chrono>


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


bool check_bites3(unsigned int a){
    return not (a & 1 == 0);
}


double benchmark(bool func(unsigned int)) {
    long long int n = 5000000000;
    bool result;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        result = func(i);
    }
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = finish - start;
    return duration.count() * 1000;
}


int main() {
    double alpha = 0;
    int n = 10;
    for (int k = 0; k < n; k++) {
        double t1 = benchmark(usual_check);
        double t2 = benchmark(check_bites);
        alpha += t2 / t1;
        std::cout << t2 / t1 << std::endl;
    }
    std::cout << "Побитовый быстрее классики на " << (1 - alpha / n) * 100 << " %";
}