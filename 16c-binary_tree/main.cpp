#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>


template <typename T>
struct Node{
    struct Node* left;
    struct Node* right;
    T key;
};

template <typename T>
class Binary_Tree {
private:
    Node<T>* root;

    void inside_insert(Node<T>** p, int val) {
        if ((*p) == NULL) {
            (*p) = (Node<T>*) malloc(sizeof(Node<T>));
            (*p)->key = val;
            (*p)->left = NULL;
            (*p)->right = NULL;
        } else {
            if (val < (*p)->key){
                inside_insert(&((*p)->left), val);
            }
            else {
                inside_insert(&((*p)->right), val);
            }
        }
    }

    void inside_preOrder(Node<T> *p) {
        if (p != NULL) {
            printf("%3d", p->key);
            inside_preOrder(p->left);
            inside_preOrder(p->right);
        }
    }

    void inside_lnrOrder(Node<T>* p) {
        if (p != NULL) {
            inside_lnrOrder(p->left);
            printf("%3d ", p->key);
            inside_lnrOrder(p->right);
        }
    }

    Node<T>* inside_find(Node<T> *p, int value){
        if (p != NULL){
            if (p->key == value){
                return p;
            }
            Node<T>* p1;
            Node<T>* p2;
            p1 = inside_find(p->left, value);
            p2 = inside_find(p->right, value);
            if (p1 != NULL){
                return p1;
            }
            if (p2 != NULL){
                return p2;
            }
        }
        return NULL;
    }

    int inside_del(Node<T> **p, int value){
        if (inside_find(*p, value) == NULL){
            return -1;
        }

        if ((*p) != NULL) {
            if ((*p)->key == value) {
                Node<T>* p1;
                if ((*p)->right == NULL && (*p)->left == NULL) {
                    return 0;
                }
                else if ((*p)->right != NULL && (*p)->left != NULL){
                    p1 = (*p)->right;
                    while (p1->left != NULL){
                        p1 = p1->left;
                    }
                    Node<T>** p2;
                    p2 = p;
                    inside_del(p2, p1->key);
                    p1->left = (*p)->left;
                    p1->right = (*p)->right;
                    (*p) = p1;
                }
                else if ((*p)->right == NULL && (*p)->left != NULL){
                    p1 = (*p)->left;
                    (*p) = p1;
                }
                else if ((*p)->right != NULL && (*p)->left == NULL){
                    p1 = (*p)->right;
                    (*p) = p1;
                }
            }
            else {
                int state = 1;
                state = inside_del(&((*p)->left), value);
                if (state == 0){
                    (*p)->left = NULL;
                }
                state = inside_del(&((*p)->right), value);
                if (state == 0){
                    (*p)->right = NULL;
                }
            }
        }
        return 1;
    }

public:
    Binary_Tree() {
        root = NULL;
    }

    void insert(T val) {
        inside_insert(&root, val);
    }

    void preOrder() {
        inside_preOrder(root);
    }

    void lnrOrder() {
        inside_lnrOrder(root);
    }

    Node<T>* find(T value){
        return inside_find(root, value);
    }

    int del(T value){
        return inside_del(&root, value);
    }
};


int main() {
    Binary_Tree<int> tree;
    for (int i = 10; i > 2; i--) {
        tree.insert(i);
    }
    tree.preOrder();
    std::cout << std::endl;
    tree.del(5);
    tree.preOrder();
}
