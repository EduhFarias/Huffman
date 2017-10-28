//
// Created by Eduardo on 24/10/17.
//

#ifndef HUFFMAN_DECOMPRESS_H
#define HUFFMAN_DECOMPRESS_H

#include "BinaryTree.h"

void decompress(FILE *iFile);

void converter(BinaryTree *bt, FILE *file);
#endif //HUFFMAN_DECOMPRESS_H
