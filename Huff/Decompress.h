//
// Created by Eduardo on 24/10/17.
//

#ifndef HUFFMAN_DECOMPRESS_H
#define HUFFMAN_DECOMPRESS_H

#include "BinaryTree.h"

void decompress(FILE *iFile, FILE *oFile);

void converter(BinaryTree *bt, FILE *file, int trash, int size_tree, FILE *oFile);
#endif //HUFFMAN_DECOMPRESS_H
