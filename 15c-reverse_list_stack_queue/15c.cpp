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


class General : public Interface {
    protected:
        vector<int> p;
    public:
        vector<int> get_data() {
            return p;
        }
        void push(int a) {
            p.push_back(a);
        }
};


class List: public Interface {
private:
    Elem* start = NULL;
    Elem* end = NULL;
    int length = 0;
public:
    int len() {
        return length;
    }
    void push(int value) {
        Elem* p;
        p = new Elem;
        p->inf = value;
        p->link = NULL;
        if (length == 0) {
            start = p;
            end = p;
        }
        else {
            end->link = p;
            end = p;
        }
        length++;
    }


    int pop() {
        if (length == 1) {
            int tmp = start->inf;
            free(start);
            length--;
            return tmp;
        }
        else if (length != 0) {
            Elem *p;
            p = end;
            end->link = start;
            while (end->link != p) {
                end = end->link;
            }
            int tmp = p->inf;
            free(p);
            end->link = NULL;
            length--;
            return tmp;
        }
        else {
            cout << "Error";
            return -1;
        }
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


template <typename T>
void reverse(T& example) {
    for (int i = 0; i < example.get_data().size() / 2; i++) {
        swap(example.get_data()[i], example.get_data()[example.get_data().size() - i - 1]);
    }
}

void reverse(List& example) {
    vector<int> tmp;
    int l = example.len();
    for (int i = 0; i < l; i++) {
        tmp.push_back(example.pop());
    }
    for (int i = 0; i < l; i++) {
        example.push(tmp[i]);
    }
}


int main(){
    Queue q;
    Stack s;
    List list;
    for (int i = 1; i < 6; i++) {
        q.push(i);
        s.push(i);
        list.push(i);
    }

    reverse(list);
    for (int i = 1; i < 6; i++) {
        cout << list.pop() << " ";
    }
    cout << endl;
}