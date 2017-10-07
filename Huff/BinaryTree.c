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

BinaryTree* createBinaryTree(unsigned char c, int freq, BinaryTree *bt){
    BinaryTree *new_bt = (BinaryTree*) malloc(sizeof(BinaryTree));
    new_bt->c = c;
    new_bt->freq = freq;
    new_bt->left = NULL;
    new_bt->right = NULL;
    new_bt->next = NULL;
    BinaryTree *current = bt, *prev = NULL;
    while(current != NULL || current->freq >= new_bt->freq){
        prev = current;
        current = current->next;
    }
    if(prev == NULL){
        new_bt->next = current;
    } else if(prev != NULL){
        prev->next = new_bt;
        new_bt->next = current;
    }
}

BinaryTree* removeNode(BinaryTree *bt){
    BinaryTree *tmp = bt;
    bt = bt->next;
    free(tmp);
    return bt;
}