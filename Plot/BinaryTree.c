//
// Created by Eduardo on 01/10/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

typedef struct binary_tree{
    int item;
    struct binary_tree *left;
    struct binary_tree *right;
}BinaryTree;

BinaryTree* createEmptyBinaryTree(){
    return NULL;
}

BinaryTree* createBinaryTree(int item, BinaryTree *left, BinaryTree *right){
    BinaryTree *new_bt = (BinaryTree*) malloc(sizeof(BinaryTree));
    new_bt->item = item;
    new_bt->left = left;
    new_bt->right = right;
    return new_bt;
}

BinaryTree* add(BinaryTree *bt, int item){
    if(bt == NULL){
        createBinaryTree(item, NULL, NULL);
    } else if(bt->item > item){
        bt->left = add(bt->left, item);
    } else{}
    bt->right = add(bt->right, item);
}

BinaryTree* search(BinaryTree *bt, int item){   //tentar fazer a funçao ser int
    if(bt == NULL || bt->item == item){         //para usar o cont
        return bt;
    } else if(bt->item > item){
        bt->left = search(bt->left, item);
    } else{
        bt->right = search(bt->right, item);
    }
}
