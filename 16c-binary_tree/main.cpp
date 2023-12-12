#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>


template <typename T>
struct Node{
    struct node_tree *left;
    struct node_tree *right;
    T key;
};

template <typename T>
class Binary_Tree {
private:
    vector<T> args;
    Node *p;

    void sort() {
        for (int i = 0; i < args.size(); i++) {
            for (int j = 0; j < args.size() - 1 - i; j++) {
                if (args[j] > args[j + 1]) {
                    swap(args[j], args[j + 1]);
                }
            }
        }
    }

public:
    Binary_Tree(initializer_list<T> a = {}) {
        args = a;
        sort();
    }

    void insert(T val) {
        if (p == NULL) {
            p = (Node *) malloc(sizeof(Node));
            p->key = val;
            p->left = NULL;
            p->right = NULL;
        } else {
            if (val < p->key){
                insert((p->left), val);
            }
            else {
                insert((p->right), val);
            }
        }
    }

    void preOrder() {
        if (p != NULL) {
            printf("%3d", p->key);
            preOrder(p->left);
            preOrder(p->right);
        }
    }

    Node* find(T value){
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

    int del(int value){
        if (find(*p, value) == NULL){
            return -1;
        }

        if (p != NULL) {
            if (p->key == value) {
                Node *p1;
                if (p->right == NULL && p->left == NULL) {
                    return 0;
                }
                else if (p->right != NULL && p->left != NULL){
                    p1 = p->right;
                    while (p1->left != NULL){
                        p1 = p1->left;
                    }
                    Node *p2;
                    p2 = p;
                    del(p2, p1->key);
                    p1->left = p->left;
                    p1->right = p->right;
                    p = p1;
                }
                else if (p->right == NULL && p->left != NULL){
                    p1 = p->right;
                    p = p1;
                }
                else if (p->right != NULL && p->left == NULL){
                    p1 = p->left;
                    p = p1;
                }
            }
            else {
                int state = 1;
                state = del((p->left), value);
                if (state == 0){
                    p->left = NULL;
                }
                state = del((p->right), value);
                if (state == 0){
                    p->right = NULL;
                }
            }
        }
        return 1;
    }
};


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
