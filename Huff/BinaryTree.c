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

BinaryTree* createBinaryTree(unsigned char c, int freq, BinaryTree *bt){ //Cria um novo nó
    BinaryTree *new_bt = (BinaryTree*) malloc(sizeof(BinaryTree));
    new_bt->c = c;
    new_bt->freq = freq;
    new_bt->left = NULL;
    new_bt->right = NULL;
    new_bt->next = NULL;

    if(bt == NULL){                                                      //Checa se o nó inicial é nulo
        head = new_bt;                                                   //Se for a nova cabeça será o novo nó
    }else {                                                              //Se não percorre toda a lista de nós
        BinaryTree *current = bt, *prev = NULL;                          //até achar uma posição ideal
        while(current != NULL && current->freq <= new_bt->freq){
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

BinaryTree* huff(BinaryTree *bt){                                           //Começa o merge
    while(bt->next) {                                                             //Enquanto ouver mais de um nó
        BinaryTree *A, *B, *prev = NULL, *current = bt;                     //Cria dois nós auxiliares
        A = getNode(bt);                                                    //A recebe o nó de menor frequência
        B = getNode(bt->next);

        BinaryTree *new_parent = (BinaryTree*) malloc(sizeof(BinaryTree));  //Cria um novo nó que será a raiz
        new_parent->c = '*';
        new_parent->freq = (A->freq) + (B->freq);
        new_parent->left = A;
        new_parent->right = B;

        while(current != NULL && current->freq < new_parent->freq){        //Procura a melhor posição pra colocar
            prev = current;                                                 //o novo nó
            current = current->next;
        }
        if(prev == NULL){
            new_parent->next = current;
            head = new_parent;
        } else if(prev != NULL){
            prev->next = new_parent;
            new_parent->next = current;
        }
        head = new_parent;
        bt = removeNode(bt);
        bt = removeNode(bt);
    }
    return head;
}

BinaryTree* getNode(BinaryTree *bt){
    BinaryTree *tmp = bt;
    return tmp;
}

BinaryTree* removeNode(BinaryTree *bt){
    BinaryTree *tmp = bt;
    bt = bt->next;
    head = bt;
    tmp->next = NULL;
    return bt;
}

void printPreOrder(BinaryTree *bt)  {
    if(isEmpty(bt)){
        printf("%c", bt->c);
        printPreOrder(bt->left);
        printPreOrder(bt->right);
    }
}

int isEmpty(BinaryTree *bt){
    return (bt != NULL);
}

void printx(BinaryTree *bt){
    while(bt){
        printf("-%c %d ", bt->c, bt->freq);
        bt = bt->next;
    }
}