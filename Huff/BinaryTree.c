//
// Created by Eduardo on 03/10/2017.
//

#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct b_tree{
    unsigned char c;
    int freq;
    struct b_tree *next;
    struct b_tree *left;
    struct b_tree *right;
}BinaryTree;

BinaryTree *head = NULL;

BinaryTree* createEmpty(){
    return NULL;
}

BinaryTree* createBinaryTree(unsigned char c, int freq, BinaryTree *bt){
    BinaryTree *new_bt = (BinaryTree*) malloc(sizeof(BinaryTree));
    new_bt->c = c;
    new_bt->freq = freq;
    new_bt->left = NULL;
    new_bt->right = NULL;
    new_bt->next = NULL;

    if(bt == NULL){
        head = new_bt;
    }else {
        BinaryTree *current = bt, *prev = NULL;
        while(current != NULL && current->freq <= new_bt->freq){
            prev = current;
            current = current->next;
        }
        if(prev == NULL){
            new_bt->next = current;
            head = new_bt;
        } else if(prev != NULL){
            prev->next = new_bt;
            new_bt->next = current;
            head = prev;
        }
    }
    return head;
}

BinaryTree* huff(BinaryTree *bt){
    while(bt) {
        BinaryTree *A, *B, *prev = NULL, *current = bt;
        A = removeNode(bt);
        B = removeNode(bt);
        head = B->next;

        BinaryTree *new_parent = (BinaryTree*) malloc(sizeof(BinaryTree));
        new_parent->c = '*';
        new_parent->freq = (A->freq) + (B->freq);
        new_parent->left = A;
        new_parent->right = B;

        while(current != NULL && current->freq <= new_parent->freq){
            prev = current;
            current = current->next;
        }
        if(prev == NULL){
            new_parent->next = current;
            head = new_parent;
        } else if(prev != NULL){
            prev->next = new_parent;
            new_parent->next = current;
            head = prev;
        }
    }
}

BinaryTree* removeNode(BinaryTree *bt){
    BinaryTree *tmp = bt;
    bt = bt->next;
    head = bt;
    return tmp;
}

void printPreOrder(BinaryTree *bt){
    if(isEmpty(bt)){
        printf("%c", bt->c);
        printPreOrder(bt->left);
        printPreOrder(bt->right);
    }
}

int isEmpty(BinaryTree *bt){
    return (bt != NULL);
}

void printx(BinaryTree *bt){
    while(bt){
        printf("-%c ", bt->c);
        bt = bt->next;
    }
}