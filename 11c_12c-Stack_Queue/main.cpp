#include <iostream>
#include <vector>
#include "stack.h"
#include "queue.h"

using namespace std;


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

    for (int i = 1; i < 7; i++) {
        cout << s.pop() << " ";
    }
}