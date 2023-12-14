#include "queue.h"
#include <iostream>

int Queue::pop() {
    try {
        if (p.size() == 0) {
            throw std::out_of_range("Queue is already empty!");
        }
        int tmp;
        tmp = p[0];
        p.erase(p.cbegin());  
        return tmp;
    }
    catch (std::out_of_range) {
        std::cout << "Queue is empty!" << std::endl;
        return -1;
    }
}
