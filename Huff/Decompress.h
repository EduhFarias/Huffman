//
// Created by Eduardo on 24/10/17.
//

#ifndef HUFFMAN_DECOMPRESS_H
#define HUFFMAN_DECOMPRESS_H

#include "BinaryTree.h"

void decompress(FILE *iFile);

BinaryTree* rebuildTree(BinaryTree *bt, char *tree, int size, int pos);

#endif //HUFFMAN_DECOMPRESS_H
