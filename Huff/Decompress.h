//
// Created by Eduardo on 24/10/17.
//

#ifndef HUFFMAN_DECOMPRESS_H
#define HUFFMAN_DECOMPRESS_H

#include "BinaryTree.h"

// Recebe o arquivo de entrada e o arquivo de saída e gera o arquivo descompactado
void decompress(FILE *iFile, FILE *oFile);

/*
 * Recebe o arquivo de entrada e dois vetores de inteiros vazios. A partir dos dois
 * primeiros bytes do arquivo de entrada cria os vetores com os tamanhos de lixo e o
 * tamanho da árvore, em binário.
 */
void getTrash_Tree(FILE *iFile, int *trash, int *size_tree);

/*
 * Recebe o arquivo de entrada, um vetor de caracteres, vazio, e seu tamanho.
 * A partir desses dados monta o vetor com a sequência de caracteres que representa
 * a árvore de Huffman em pré-ordem.
 */
void getTree(FILE *iFile, char *tree, int size_tree);

/*
 * Recebe o nó raiz da árvore de Huffman, o arquivo de entrada, o tamanho do lixo e
 * o tamanho da árvore e o arquivo de saída. A partir desses dados gera a conversão e
 * imprime no arquivo de saída.
 */
void converterDecomp(BinaryTree *bt, FILE *file, int trash, int size_tree, FILE *oFile);

#endif //HUFFMAN_DECOMPRESS_H
