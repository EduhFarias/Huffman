#ifndef HUFFMAN_BINARYTREE_H
#define HUFFMAN_BINARYTREE_H

#include <stdio.h>
typedef struct b_tree BinaryTree;


// Inicia um nó.
BinaryTree* createEmpty();

/*
 *  Recebe o tipo de dado, a frequência desse dado, a cabeça da fila e dois nós
 *  para serem os filhos do novo nó. Retorna um novo nó que já está adequadamente
 *  inserido na fila de prioridade.
 */
BinaryTree* createQueue(void *c, long long int freq, BinaryTree *bt, BinaryTree *left, BinaryTree *right);

// Recebe um nó da fila de prioridade e o elimina. Retorna o nó de menor frequência.
BinaryTree* removeNode(BinaryTree *bt);

// Recebe o nó raiz de uma árvore e retorna sua quantidade de elementos.
int sizeTree(BinaryTree *bt);

// Recebe o nó raiz de uma árvore e o arquivo de saída e imprime a árvore em pré-ordem.
void printPreOrder(BinaryTree *bt, FILE *file);

// Recebe um nó de uma árvore e retorna seu filho à esquerda.
BinaryTree* getLeft(BinaryTree *bt);

// Recebe um nó de uma árvore e retorna seu filho à direita.
BinaryTree* getRight(BinaryTree *bt);

// Recebe um nó e retorna o próximo nó em relação ao atual.
BinaryTree* getNext(BinaryTree *bt);

// Recebe um nó e retorna seu dado.
void* getValue(BinaryTree *bt);

// Recebe um nó e retorna a frequência de seu dado.
long long int getFreq(BinaryTree *bt);

// Recebe um nó e verifica se ele está vazio. Se não estiver vazio retorna 1.
int isEmpty(BinaryTree *bt);

/*
 * Cria um novo nó para uma árvore. Recebe um item do tipo dado, e dois nós para
 * serem os filhos do novo nó criado
 */
BinaryTree* createBinaryTree(void *item, BinaryTree *left, BinaryTree *right);

/*
 * Reconstrói um árvore a partir de um nó raiz, um vetor de caracteres que contenha a
 * sequência da árvore em pré-ordem e o tamanho desse vetor.
 */
BinaryTree* rebuildTree(BinaryTree *bt, char *tree, int size);

#endif //HUFFMAN_BINARYTREE_H
