#ifndef RATIONAL
#define RATIONAL

#include <iostream>

using namespace std;

class Rational {
    private:
        long int ch;
        long int zn;
    public:
        Rational (){}
        Rational (int, int);

        Rational (float);

        Rational operator * (Rational &);

        Rational operator + (Rational &);

        long int NOD(long int, long int);

        void print(int form = 2);
};

#endif