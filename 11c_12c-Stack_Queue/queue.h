#ifndef QUEUE
#define QUEUE

#include "general.h"

class Queue : public General {
    public:
        Queue(std::initializer_list<int> a = {}) {
            p = a;
        }

        int pop();
};

#endif