//
// Created by Eduardo on 25/10/2017.
//

#ifndef HUFFMAN_HELPFUL_H
#define HUFFMAN_HELPFUL_H

int isBit_i_set(unsigned char c, int i);

unsigned char setBit(unsigned char c, int i);

void initialize(unsigned char table[][256], unsigned char *aux);

void bin_converter(int item, int size, int *aux);

int dec_converter(int *aux, int size);

#endif //HUFFMAN_HELPFUL_H
