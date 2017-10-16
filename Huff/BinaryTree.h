//
// Created by Eduardo on 03/10/2017.
//

#ifndef HUFFMAN_BINARYTREE_H
#define HUFFMAN_BINARYTREE_H

#include <stdio.h>
typedef struct b_tree BinaryTree;

BinaryTree* createEmpty();

BinaryTree* createBinaryTree(unsigned char c, int freq, BinaryTree *bt);

BinaryTree* removeNode(BinaryTree *bt);

BinaryTree* getNode(BinaryTree *bt);

int printPreOrder(BinaryTree *bt, FILE *file);

BinaryTree* huff(BinaryTree *bt);

int isEmpty(BinaryTree *bt);

#endif //HUFFMAN_BINARYTREE_H
