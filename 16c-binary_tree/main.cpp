#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

typedef struct node_tree{
    int inf;
    struct node_tree *left;
    struct node_tree *right;
    int key;
} Node;

typedef struct node_queue {
    const void*  ptr;
    struct node_queue* next;
} node_t;

typedef struct {
    node_t* head;
    node_t* tail;
} queue_t;


void  queue_init(queue_t* q){
    q->head = NULL;
    q->tail = NULL;
}

int   queue_empty(queue_t* q) {
    return (q->head == NULL);
}

const void* queue_front(queue_t* q) {
    return q->head->ptr;
}


int queue_push(queue_t* q, const void* ptr){
    node_t* p = (node_t*)malloc(sizeof(node_t));
    if(p != NULL){
        p->ptr  = ptr;
        p->next = NULL;
        if(q->head == NULL)
            q->head = q->tail = p;
        else {
            q->tail->next = p;
            q->tail = p;
        }
    }
    return (p != NULL);
}


void queue_pop(queue_t* q){
    node_t* t;
    if(q->head != NULL){
        t       = q->head;
        q->head = q->head->next;
        free(t);
        if(q->head == NULL)
            q->tail = NULL;
    }
}


void insert(Node **p, int val) {
    if ((*p) == NULL) {
        (*p) = (Node *) malloc(sizeof(Node));
        (*p)->key = val;
        (*p)->left = NULL;
        (*p)->right = NULL;
    } else {
        if (val < (*p)->key){
            insert(&((*p)->left), val);
        }
        else {
            insert(&((*p)->right), val);
        }
    }
}


void lnrOrder(Node *p) {
    if (p != NULL) {
        lnrOrder(p->left);
        printf("%d ", p->key);
        lnrOrder(p->right);
    }
}


void preOrder(Node *p) {
    if (p != NULL) {
        printf("%3d", p->key);
        preOrder(p->left);
        preOrder(p->right);
    }
}


int levels(Node *p, int level){
    if (p->right == NULL && p->left == NULL){
        return 0;
    }
    int p1, p2;
    p1 = levels(p->left, level);
    p2 = levels(p->right, level);
    if (p1 > p2){
        return ++p1;
    }
    return ++p2;
}


int summ_leaves(Node *p, int s) {
    if (p != NULL) {
        if (p->right == NULL && p->left == NULL) {
            return p->key;
        }
        int s1, s2;
        s1 = summ_leaves(p->left, s);
        s2 = summ_leaves(p->right, s);
        return s1 + s2;
    }
    return 0;
}


void breadth_Order(Node* root){
    Node* p;
    queue_t q;
    queue_init(&q);

    queue_push(&q, root);
    while(! queue_empty(&q)){
        p = (Node*) queue_front(&q);
        queue_pop(&q);
        //выводим
        printf("%d ", p->key);

        if(p->left != NULL)
            queue_push(&q, p->left);
        if(p->right != NULL)
            queue_push(&q, p->right);
    }
    printf("\n");
}


void add(Node *p, int a, int b, int n){
    int k;
    for (int i = 0; i < n; i++){
        k = (rand() + a) % (b + 1);
        insert(&p, k);
    }
}


void del_tree(Node **p){
    if ((*p)->right == NULL && (*p)->left == NULL){
        free((*p));
    }
    else{
        del_tree(&((*p)->left));
        del_tree((&(*p)->right));
    }
}


Node* find(Node *p, int value){
    if (p != NULL){
        if (p->key == value){
            return p;
        }
        Node *p1, *p2;
        p1 = find(p->left, value);
        p2 = find(p->right, value);
        if (p1 != NULL){
            return p1;
        }
        if (p2 != NULL){
            return p2;
        }
    }
    return NULL;
}


int del(Node **p, int value){
    if (find(*p, value) == NULL){
        return -1;
    }

    if ((*p) != NULL) {
        if ((*p)->key == value) {
            Node *p1;
            if ((*p)->right == NULL && (*p)->left == NULL) {
                return 0;
            }
            else if ((*p)->right != NULL && (*p)->left != NULL){
                p1 = (*p)->right;
                while (p1->left != NULL){
                    p1 = p1->left;
                }
                Node **p2;
                p2 = p;
                del(p2, p1->key);
                p1->left = (*p)->left;
                p1->right = (*p)->right;
                (*p) = p1;
            }
            else if ((*p)->right == NULL && (*p)->left != NULL){
                p1 = (*p)->right;
                (*p) = p1;
            }
            else if ((*p)->right != NULL && (*p)->left == NULL){
                p1 = (*p)->left;
                (*p) = p1;
            }
        }
        else {
            int state = 1;
            state = del(&((*p)->left), value);
            if (state == 0){
                (*p)->left = NULL;
            }
            state = del(&((*p)->right), value);
            if (state == 0){
                (*p)->right = NULL;
            }
        }
    }
    return 1;
}


void interval_del(Node *p, int a, int b) {
    if (p != NULL) {
        for (int i = a; i <= b; i++) {
            if (find(p, i) != NULL) {
                del(&p, i);
            }
        }
    }
}


int main() {
    Node *root = NULL;
    int tmp;
    std::cin >> tmp;
    while (tmp != 0) {
        insert(&root, tmp);
        std::cin >> tmp;
    }

    preOrder(root);
    printf("\n");
    //breadth_Order(root);
    //printf("\n");

    int value, error;
    scanf("%d", &value);
    error = del(&root, value);
    if (error == -1){
        printf("!\n");
    }
    preOrder(root);
    printf("\n");

    int s = 0;
    printf("%d\n", summ_leaves(root, s));
}
