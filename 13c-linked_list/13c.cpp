#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <vector>

using namespace std;


struct Elem {
    int inf; /* inf - информационное поле */
    struct Elem *link; /* link - указательное поле */
};


class Interface {
    protected:
        virtual void push(int a) = 0;
        virtual int pop() = 0;
};


class List: public Interface {
private:
    Elem* start = NULL;
    Elem* end = NULL;
public:
    void push(int value) {
        Elem* p;
        p = new Elem;
        p->inf = value;
        p->link = NULL;
        if (!start) {
            start = p;
            end = p;
        }
        else {
            end->link = p;
            end = p;
        }
    }


    int pop() {
        if (start->link) {
            Elem *p;
            p = end;
            end->link = start;
            while (end->link != p) {
                end = end->link;
            }
            int tmp = p->inf;
            free(p);
            end->link = NULL;
            return tmp;
        }
        else {
            cout << "Error";
            return -1;
        }
    }

};

int main() {
    List list;
    for (int i = 0; i < 4; i++) {
        list.push(i);
    }

    for (int i = 0; i < 6; i++) {
        cout << list.pop() << " ";
    }
}