//
// Created by Eduardo on 03/10/2017.
//

#ifndef HUFFMAN_BINARYTREE_H
#define HUFFMAN_BINARYTREE_H

typedef struct b_tree BinaryTree;

BinaryTree* createBinaryTree(unsigned char c, int freq, BinaryTree *bt);

BinaryTree* removeNode(BinaryTree *bt);

#endif //HUFFMAN_BINARYTREE_H
