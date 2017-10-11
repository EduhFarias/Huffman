//
// Created by Eduardo on 04/10/2017.
//

#ifndef HUFFMAN_COMPRESS_H
#define HUFFMAN_COMPRESS_H

#include <stdio.h>
#include "BinaryTree.h"

void compress(FILE *file);

void createTable(BinaryTree *bt, unsigned char table[256][256], unsigned char *ch);

unsigned char createCode(BinaryTree *bt, unsigned char position, unsigned char *string);

int isBit_i_set(unsigned char c, int i);


#endif //HUFFMAN_COMPRESS_H

