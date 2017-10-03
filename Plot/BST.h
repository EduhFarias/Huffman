//
// Created by Eduardo on 01/10/2017.
//

#ifndef BST_H
#define BST_H

typedef struct binary_tree BST;

BST* createEmptyBinaryTree();

BST* createBinaryTree(int item, BST *left, BST *right);

BST* add(BST *bt, int item);

int searchTree(BST *bt, int item);

#endif //BST_H
