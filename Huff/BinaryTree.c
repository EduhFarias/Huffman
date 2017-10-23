//
// Created by Eduardo on 03/10/2017.
//

#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct b_tree{
    unsigned char c;
    int freq;
    struct b_tree *next;
    struct b_tree *left;
    struct b_tree *right;
}BinaryTree;

BinaryTree *head = NULL;

BinaryTree* createEmpty(){
    return NULL;
}

BinaryTree* createBinaryTree(unsigned char c, int freq, BinaryTree *bt, BinaryTree *left, BinaryTree *right){ //Cria um novo nó
    BinaryTree *new_bt = (BinaryTree*) malloc(sizeof(BinaryTree));
    new_bt->c = c;
    new_bt->freq = freq;
    new_bt->left = left;
    new_bt->right = right;
    new_bt->next = NULL;

    if(bt == NULL){                                                      //Checa se o nó inicial é nulo
        head = new_bt;                                                   //Se for a nova cabeça será o novo nó
    }else {                                                              //Se não percorre toda a lista de nós
        BinaryTree *current = bt, *prev = NULL;                          //até achar uma posição ideal
        while(current != NULL && current->freq < new_bt->freq){
            prev = current;
            current = current->next;
        }
        if(prev == NULL){
            new_bt->next = current;
            head = new_bt;
        } else if(prev != NULL){
            prev->next = new_bt;
            new_bt->next = current;
        }
    }
    return head;
}

BinaryTree* getNode(BinaryTree *bt){
    BinaryTree *tmp = bt;
    return tmp;
}

BinaryTree* getLeft(BinaryTree *bt){
    return bt->left;
}

BinaryTree* getRight(BinaryTree *bt){
    return bt->right;
}

unsigned char getValue(BinaryTree *bt){
    return bt->c;
}

BinaryTree* getNext(BinaryTree *bt){
    return bt->next;
}

int getFreq(BinaryTree *bt){
    return bt->freq;
}

BinaryTree* removeNode(BinaryTree *bt){
    BinaryTree *tmp = bt;
    bt = bt->next;
    head = bt;
    tmp->next = NULL;
    return bt;
}

short int size = 0;

int printPreOrder(BinaryTree *bt, FILE *file)  { //Vễ se coloco no huff.c
    if(isEmpty(bt)){size++;
        fprintf(file,"%c", bt->c);        //Colocar um condicional, se bt->c for '*' imprimir '\*', se for '\' imprimir '\\'
        printPreOrder(bt->left,file);
        printPreOrder(bt->right,file);
    }
    return size;
}

void printOrder(BinaryTree *bt)  {
    if(isEmpty(bt)){size++;
        printf("%c", bt->c);
        printOrder(bt->left);
        printOrder(bt->right);
    }
}

int isEmpty(BinaryTree *bt){
    return (bt != NULL);
}

