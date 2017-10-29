//
// Created by Eduardo on 24/10/17.
//

#ifndef HUFFMAN_DECOMPRESS_H
#define HUFFMAN_DECOMPRESS_H

#include "BinaryTree.h"

void decompress(FILE *iFile, FILE *oFile);

void converterDecomp(BinaryTree *bt, FILE *file, int trash, int size_tree, FILE *oFile);

void getTree(FILE *iFile, char *tree, int size);

void getTrash_Tree(FILE *iFile, int *trash, int*size_tree);

#endif //HUFFMAN_DECOMPRESS_H
