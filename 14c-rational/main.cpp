#include "Rational.h"

using namespace std;


int main() {
    Rational q1 (1.4);
    Rational q2 (0.25);
    Rational q3;
    q1.print();
    q2.print();
    q3 = q1 * q2;
    q3.print();
    q3 = q1 + q2;
    q3.print();

}