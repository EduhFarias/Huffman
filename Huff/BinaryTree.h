//
// Created by Eduardo on 03/10/2017.
//

#ifndef HUFFMAN_BINARYTREE_H
#define HUFFMAN_BINARYTREE_H

#include <stdio.h>
typedef struct b_tree BinaryTree;

BinaryTree* createEmpty();

BinaryTree* createBinaryTree(unsigned char c, int freq, BinaryTree *bt, BinaryTree *left, BinaryTree *right);

BinaryTree* removeNode(BinaryTree *bt);

BinaryTree* getNode(BinaryTree *bt);

int sizeTree(BinaryTree *bt, FILE *file);

void printPreOrder(BinaryTree *bt, FILE *file);

BinaryTree* getLeft(BinaryTree *bt);

BinaryTree* getRight(BinaryTree *bt);

BinaryTree* getNext(BinaryTree *bt);

unsigned char getValue(BinaryTree *bt);

int getFreq(BinaryTree *bt);

int isEmpty(BinaryTree *bt);

#endif //HUFFMAN_BINARYTREE_H
