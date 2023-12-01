#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct elem {
    int inf; /* inf - информационное поле */
    struct elem *link; /* link - указательное поле */
} Elem;


int *split(char *str, int *len) {
    char tmp[10];
    memset(tmp, 0, 10);
    int i = 0, c = 0;
    *len = 0;
    while (str[i] != 'n') {
        if (str[i++] == ' ') {
            (*len)++;
        }
    }
    int *mas;
    mas = (int *) malloc((*len) * sizeof(Elem));
    int count = 0;
    i = 0;
    while (str[i] != 'n') {
        if (isdigit(str[i])) {
            tmp[c++] = str[i];
        } else {
            c = 0;
            mas[count++] = atoi(tmp);
            memset(tmp, 0, 10);
        }
        i++;
    }
    return mas;
}


void add_end(Elem **start, Elem **end, int value) {
    Elem *p;
    p = (Elem *) malloc(sizeof(Elem));
    p->inf = value;
    p->link = NULL;
    (*end)->link = p;
    *end = p;
}


void add_start(Elem **start, Elem **end, int value) {
    Elem *p;
    p = (Elem *) malloc(sizeof(Elem));
    p->inf = value;
    p->link = (*start);
    (*start) = p;
}


void delete_start(Elem **start, Elem **end) {
    Elem *p;
    p = *start;
    (*start) = (*start)->link;
    free(p);
}


void delete_end(Elem **start, Elem **end) {
    Elem *p;
    p = (*end);
    (*end)->link = (*start);
    while ((*end)->link != p) {
        (*end) = (*end)->link;
    }
    free(p);
    (*end)->link = NULL;
}


void delete(Elem **start, Elem **end, Elem *elem) {
    (*end)->link = (*start);
    Elem *p;
    p = (*start);
    while (p->link != elem) {
        p = p->link;
    }
    p->link = elem->link;
    elem->link = NULL;
    free(elem);
    (*end)->link = NULL;
}


Elem *find(Elem *start, Elem *end, int value) {
    int flag = 0;
    while (start->link != NULL) {
        if (start->inf == value) {
            flag = 1;
            break;
        }
        start = start->link;
    }
    if (start->inf == value) flag = 1;
    if (flag) {
        return start;
    }
    return 0;
}


void print(Elem *start, Elem *end) {
    while (start->link != NULL) {
        printf("%4d", start->inf);
        start = start->link;
    }
    printf("%4d\n", start->inf);
}


int summ(Elem *start) {
    int s = 0;
    while (start->link != NULL) {
        s += start->inf;
        start = start->link;
    }
    s += start->inf;
    return s;
}


int main() {
    Elem *BegQ, *EndQ;
    BegQ = (Elem *) malloc(sizeof(Elem));
    EndQ = BegQ;
    char tmp[100];
    gets(tmp);

    char tmp2[10];
    memset(tmp2, 0, 10);
    int i = 0, c = 0;
    int len = 0;
    while (tmp[i] != 'n') {
        if (tmp[i++] == ' ') {
            len++;
        }
    }
    int count = 0;
    i = 0;
    while (tmp[i] != 'n') {
        if (isdigit(tmp[i])) {
            tmp2[c++] = tmp[i];
        } else {
            c = 0;
            if (count == 0) {
                BegQ->inf = atoi(tmp2);
                BegQ->link = NULL;
            } else {
                add_end(&BegQ, &EndQ, atoi(tmp2));
            }
            memset(tmp2, 0, 10);
            count++;
        }
        i++;
    }
    memset(tmp2, 0, 20);
    gets(tmp2);
    int del;
    del = atoi(tmp2);

    Elem *p;
    p = find(BegQ, EndQ, del);
    if (p == BegQ) {
        delete_start(&BegQ, &EndQ);
    } else if (p == EndQ) {
        delete_end(&BegQ, &EndQ);
    } else if (p != 0) {
        delete(&BegQ, &EndQ, p);
    } else {
        printf("Can't find element to delete\n");
    }

    print(BegQ, EndQ);
}
