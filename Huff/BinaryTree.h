//
// Created by Eduardo on 03/10/2017.
//

#ifndef HUFFMAN_BINARYTREE_H
#define HUFFMAN_BINARYTREE_H

#include <stdio.h>
typedef struct b_tree BinaryTree;

BinaryTree* createEmpty();

BinaryTree* createQueue(unsigned char c, long long int freq, BinaryTree *bt, BinaryTree *left, BinaryTree *right);

BinaryTree* removeNode(BinaryTree *bt);

BinaryTree* getNode(BinaryTree *bt);

int sizeTree(BinaryTree *bt);

void printPreOrder(BinaryTree *bt, FILE *file);

BinaryTree* getLeft(BinaryTree *bt);

BinaryTree* getRight(BinaryTree *bt);

BinaryTree* getNext(BinaryTree *bt);

unsigned char getValue(BinaryTree *bt);

long long int getFreq(BinaryTree *bt);

int isEmpty(BinaryTree *bt);

BinaryTree* createBinaryTree(unsigned char item, BinaryTree *left, BinaryTree *right);

BinaryTree* rebuildTree(BinaryTree *bt, char *tree, int size);

#endif //HUFFMAN_BINARYTREE_H
