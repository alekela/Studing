#ifndef STACK
#define STACK

#include <iostream>
#include "general.h"

class Stack: public General {
    public:
        Stack(std::initializer_list<int> a = {}) {
            p = a;
        }
        
        int pop();
};

#endif