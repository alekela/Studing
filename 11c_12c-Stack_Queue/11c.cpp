#include <iostream>
#include <vector>

using namespace std;


class Interface {
    protected:
        virtual void push(int a) = 0;
        virtual int pop() = 0;
};


class General : public Interface {
    protected:
        vector<int> p;
    public:
        void push(int a) {
            p.push_back(a);
        }
};


class Stack: public General {
    public:
        Stack(initializer_list<int> a = {}) {
            p = a;
        }
        
        int pop() {
            if (p.size() != 0) {
                int tmp;
                tmp = p[p.size() - 1];
                p.pop_back();  
                return tmp;
            }
            else {
                return -1;
            }
        }
};


class Queue : public General {
    public:
        /*Queue(int size, ...) {
            va_list factor;       
            va_start(factor, size);
            for(int i = 0; i < size; i++)
            {
                p.push_back(va_arg(factor, int));
            }
            va_end(factor);
        }
        void push(int a) {
            p.push_back(a);
        }*/
        Queue(initializer_list<int> a = {}) {
            p = a;
        }

        int pop() {
            if (p.size() != 0) {
                int tmp;
                tmp = p[0];
                p.erase(p.cbegin());  
                return tmp;
            }
            else {
                return -1;
            }
        }
};


int main(){
    Queue q;
    Stack s;
    for (int i = 1; i< 6; i++) {
        q.push(i);
        s.push(i);
    }

    for (int i = 1; i < 6; i++) {
        cout << q.pop() << " ";
    }
    cout << endl;

    for (int i = 1; i < 6; i++) {
        cout << s.pop() << " ";
    }
}