//
// Created by Eduardo on 04/10/2017.
//

#ifndef HUFFMAN_COMPRESS_H
#define HUFFMAN_COMPRESS_H

#include <stdio.h>
#include "BinaryTree.h"

void compress(FILE *iFile);

void createTable(BinaryTree *bt, unsigned char table[][256], int pos, unsigned char *aux);

BinaryTree* huff(BinaryTree *bt);

#endif //HUFFMAN_COMPRESS_H

