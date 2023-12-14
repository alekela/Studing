#ifndef INTERFACE
#define INTERFACE

class Interface {
    protected:
        virtual void push(int a) = 0;
        virtual int pop() = 0;
};

#endif