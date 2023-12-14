#include <iostream>
#include "general.h"
#include "stack.h"

int Stack::pop() {
    try {
        if (p.size() == 0) {
            throw std::out_of_range("Stack is already empty!");
        }
        int tmp;
        tmp = p[p.size() - 1];
        p.pop_back();  
        return tmp;
    }
    catch (std::out_of_range) {
        std::cout << "Stack is empty!" << std::endl;
        return -1;
    }
}
