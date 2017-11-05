#ifndef HUFFMAN_COMPRESS_H
#define HUFFMAN_COMPRESS_H

#include <stdio.h>
#include "BinaryTree.h"

/*
 * Recebe o arquivo de entrada e o arquivo de saída
 * e gera o arquivo compactado.
*/
void compress(FILE *iFile, FILE *oFile);

/*
 * Recebe um nó raiz de uma árvore, uma posição inicial, um vetor
 * bidimensional e um vetor, ambos do tipo caractere. Cria a tabela
 * de conversão a partir da sequência da árvore.
 */
void createTable(BinaryTree *bt, char table[][256], int pos, char *aux);

// Monta a árvore de Huffman a partir da fila de prioridades recebida.
BinaryTree* huff(BinaryTree *bt);

// Calcula a frequência de cada caractere contido no arquivo de entrada.
void frequency(FILE *iFile, long long int *ch);

/*
 * Recebe uma lista de frequência e um nó cabeça de uma fila de prioridade.
 * Para cada posição da lista de frequência é criado um novo nó e adicionado
 * adequeadamente na lista de prioridade.
 */
BinaryTree* createNode(long long int *ch, BinaryTree *bt);
/*
 * Recebe o arquivo de entrada e a tabela de conversão, calcula  e retorna
 * o tamanho do lixo do último byte que será impresso no arquivo de saída.
 */
int sizeTrash(FILE *iFile, char table[][256]);

/*
 * Recebe o arquivo de saída, o tamanho do lixo e o nó raiz da árvore de Huffman
 * e imprime no arquivo de saída dois bytes, referentes ao tamanho de lixo e o
 * tamanho da árvore.
 */
void writeTrash_sizeTree(FILE *oFile, int sizeTrash, BinaryTree *bt);

/*
 * Recebe o arquivo de entrada e o arquivo de saída, e a tabela de conversão.
 * Imprime no arquivo de saída a combinação formada pela tabela de conversão
 * de acordo com o conteúdo do arquivo de entrada.
 */
void converterComp(FILE *iFile, FILE *oFile, char table[][256]);

#endif //HUFFMAN_COMPRESS_H

