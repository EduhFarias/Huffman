#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct b_tree{
    void *c;        //-> void* c
    long long int freq;
    struct b_tree *next;
    struct b_tree *left;
    struct b_tree *right;
}BinaryTree;

BinaryTree *head = NULL;

BinaryTree* createEmpty(){
    return NULL;
}

BinaryTree* createQueue(void *c, long long int freq, BinaryTree *bt, BinaryTree *left, BinaryTree *right){
    BinaryTree *new_bt = (BinaryTree*) malloc(sizeof(BinaryTree));
    new_bt->c = c;
    new_bt->freq = freq;
    new_bt->left = left;
    new_bt->right = right;
    new_bt->next = NULL;

    if(bt == NULL){
        head = new_bt;
    }else {
        BinaryTree *current = bt, *prev = NULL;
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

BinaryTree* getLeft(BinaryTree *bt){
    return bt->left;
}

BinaryTree* getRight(BinaryTree *bt){
    return bt->right;
}

void* getValue(BinaryTree *bt){
    return bt->c;
}

BinaryTree* getNext(BinaryTree *bt){
    return bt->next;
}

long long int getFreq(BinaryTree *bt){
    return bt->freq;
}

BinaryTree* removeNode(BinaryTree *bt){
    BinaryTree *tmp = bt;
    bt = bt->next;
    head = bt;
    tmp->next = NULL;
    return bt;
}

int size = 0;

int sizeTree(BinaryTree *bt)  {
    if(isEmpty(bt)){
        if(bt->left == NULL && bt->right == NULL){
            if( (*(char*)(bt->c) == '*') || (*(char*)(bt->c) == '\\') ){
                size++;
            }
        }
        size++;
        sizeTree(bt->left);
        sizeTree(bt->right);
    }
    return size;
}

void printPreOrder(BinaryTree *bt, FILE *file)  {
    if(isEmpty(bt)){
        if(bt->left == NULL && bt->right == NULL){
            if(*(unsigned char*)(bt->c) == '*'){
                fprintf(file,"\\%c", *(unsigned char*)(bt->c));
            }
            else if(*(unsigned char*)(bt->c) == '\\') {
                fprintf(file, "\\%c", *(unsigned char*)(bt->c));
            } else fprintf(file, "%c", *(unsigned char*)(bt->c));

        } else fprintf(file, "%c", *(unsigned char*)(bt->c));

        printPreOrder(bt->left,file);
        printPreOrder(bt->right,file);
    }
}

int isEmpty(BinaryTree *bt){
    return (bt != NULL);
}

BinaryTree* createBinaryTree(void *item, BinaryTree *left, BinaryTree *right){
    BinaryTree *new_bt = (BinaryTree*) malloc(sizeof(BinaryTree));
    new_bt->c = item;
    new_bt->left = left;
    new_bt->right = right;
    return new_bt;
}

int pos = 0;

BinaryTree* rebuildTree(BinaryTree *bt, char *tree, int size){
    if(tree[pos] != '*'){
        if(tree[pos] == '\\') pos++;
        void *item = &tree[pos];
        bt = createBinaryTree(item, NULL, NULL);
        return bt;
    }
        void *item = &tree[pos];
        bt = createBinaryTree(item, NULL, NULL);
        pos++;

        bt->left = rebuildTree(bt->left, tree, size);
        pos++;
        bt->right = rebuildTree(bt->right, tree, size);

    return bt;
}
