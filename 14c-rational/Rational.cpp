#include "Rational.h"

using namespace std;


Rational::Rational (int ch1, int zn1) {
    ch = ch1;
    try {
        if (zn1 == 0) {
            throw overflow_error("Division by zero");
        }
        zn = zn1;
        long int tmp = NOD(ch, zn);
        if (tmp > 1) {
            ch /= tmp;
            zn /= tmp;
        }
    }
    catch (overflow_error) {
        cout << "Division by zero, denominator changed";
        zn = 1;
    }
}

Rational::Rational (float k) {
    k = (long int) (k * 100000000);
    *this = Rational(k, 100000000);
}

Rational Rational::operator * (Rational &q) {
    Rational q2 (this->ch * q.ch, this->zn * q.zn);
    return q2;
}

Rational Rational::operator + (Rational &q) {
    Rational q2 (this->ch * q.zn + q.ch * this->zn, this->zn * q.zn);
    return q2;
}

long int Rational::NOD(long int a, long int b) {
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return NOD(a % b, b);
    return NOD(a, b % a);
}

void Rational::print(int form) {
    if (form == 1) {
        cout << ch << "/" << zn << endl;
    }
    else if (form == 2) {
        if (ch >= zn) {
            cout << ch / zn << " ";
            cout << ch % zn << "/" << zn << endl;
        }
        else {
            cout << ch << "/" << zn << endl;
        }
    }
}