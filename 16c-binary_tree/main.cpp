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


void preOrder(Node *p) {
    if (p != NULL) {
        printf("%3d", p->key);
        preOrder(p->left);
        preOrder(p->right);
    }
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

    int value, error;
    scanf("%d", &value);
    error = del(&root, value);
    if (error == -1){
        printf("!\n");
    }
    preOrder(root);
    printf("\n");
}
