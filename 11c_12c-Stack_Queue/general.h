#ifndef GENERAL
#define GENERAL

#include <vector>
#include "interface.h"

class General : public Interface {
    protected:
        std::vector<int> p;
    public:
        void push(int a) {
            p.push_back(a);
        }
};

#endif