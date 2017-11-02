//
// Created by Eduardo on 25/10/2017.
//

#ifndef HUFFMAN_HELPFUL_H
#define HUFFMAN_HELPFUL_H

// Recebe um byte e uma posição e checa se nessa posição
// o byte está setado.
int isBit_i_set(unsigned char c, int i);

// Recebe um byte e uma posição e seta essa posição.
unsigned char setBit(unsigned char c, int i);

// Recebe um vetor bidimensional e um vetor e inicializa-os.
void initialize(char table[][256], char *aux);

/*
 * Recebe um item, um vetor de inteiros vazio e seu tamanho.
 * Conveter o item em seu representante em binário e o
 * armazena no vetor.
 */
void bin_converter(int item, int size, int *aux);

/*
 * Recebe um vetor de inteiro e seu tamanho, contendo uma
 * sequência em binário, e converte essa sequência no seu
 * representante em decimal.
 */
int dec_converter(int *aux, int size);

#endif //HUFFMAN_HELPFUL_H
