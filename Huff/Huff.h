//
// Created by Eduardo on 04/10/2017.
//

#ifndef HUFFMAN_COMPRESS_H
#define HUFFMAN_COMPRESS_H

#include <stdio.h>
#include "BinaryTree.h"

void compress(FILE *file);

void createTable(BinaryTree *bt, unsigned char table[][50], unsigned char *ch);

unsigned char createCode(BinaryTree *bt, unsigned char position, unsigned char *string);
<<<<<<< HEAD
=======

int isBit_i_set(unsigned char c, int i);

>>>>>>> f0dec830842ebffd568ec2f86cd5f334ee6907f7
#endif //HUFFMAN_COMPRESS_H

