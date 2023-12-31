#include <iostream>
#include <vector>
#include <stdarg.h>

using namespace std;


class Stack {
    private:
        vector<int> p;
    public:
        void push(int a) {
            p.push_back(a);
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


class Queue {
    private:
        vector<int> p;
    public:
        Queue(int first = -1, ...) {
            if (first != -1) {
                p.push_back(first);
            }
            va_list factor;
            va_start(factor, first);
            while(*factor > 0){
                p.push_back(va_arg(factor, int));
            }; 
            va_end(factor);
        }
        void push(int a) {
            p.push_back(a);
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
    /*Queue q;
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
    }*/

    const int n = 5;
    Queue q(1, 2, 3);
    for (int i = 0; i < n; i++) {
        cout << q.pop() << " ";
    }
    cout << endl;
}
