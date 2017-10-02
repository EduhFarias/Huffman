//
// Created by Eduardo on 01/10/2017.
//

#ifndef PLOT_BINARYTREE_H
#define PLOT_BINARYTREE_H

typedef struct binary_tree BinaryTree;

BinaryTree* createEmptyBinaryTree();

BinaryTree* createBinaryTree(int item, BinaryTree *left, BinaryTree *right);

BinaryTree* add(BinaryTree *bt, int item);

int searchTree(BinaryTree *bt, int item);

#endif //PLOT_BINARYTREE_H
