//
// Created by Eduardo on 04/10/2017.
//

#ifndef HUFFMAN_COMPRESS_H
#define HUFFMAN_COMPRESS_H

#include <stdio.h>
#include "BinaryTree.h"

void compress(FILE *iFile, FILE *oFile);

void createTable(BinaryTree *bt, unsigned char table[][256], int pos, unsigned char *aux);

BinaryTree* huff(BinaryTree *bt);

void frequency(FILE *iFile, long long int *ch);

BinaryTree* createNode(long long int *ch, BinaryTree *bt);

int sizeTrash(FILE *iFile, unsigned char table[][256]);

void writeTrash_sizeTree(FILE *oFile, int lixo, BinaryTree *bt);

void Aconverter(FILE *iFile, FILE *oFile, unsigned char table[][256]);

#endif //HUFFMAN_COMPRESS_H

