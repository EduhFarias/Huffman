//
// Created by Eduardo on 01/10/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

typedef struct binary_tree{
    int item;
    struct binary_tree *left;
    struct binary_tree *right;
}BST;

BST* createEmptyBinaryTree(){
    return NULL;
}

BST* createBinaryTree(int item, BST *left, BST *right){
    BST *new_bt = (BST*) malloc(sizeof(BST));
    new_bt->item = item;
    new_bt->left = left;
    new_bt->right = right;
    return new_bt;
}

BST* add(BST *bt, int item){
    if(bt == NULL){
        bt = createBinaryTree(item, NULL, NULL);
    } else if(bt->item > item){
        bt->left = add(bt->left, item);
    } else {
        bt->right = add(bt->right, item);
    }
}

int searchTree(BST *bt, int item){   //tentar fazer a funçao ser int
    if(bt == NULL || bt->item == item){         //para usar o cont
        return 1;
    } else if(bt->item > item){
        return 1 + searchTree(bt->left, item);
    } else{
        return 1 + searchTree(bt->right, item);
    }
}
