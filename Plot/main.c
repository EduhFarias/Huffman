#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "LinkedList.h"
#include "BinaryTree.h"

#define MAX 1000

int main() {
    FILE *file;
    BinaryTree *bt = createEmptyBinaryTree();
    Node *node = createLinkedList();
    int i, valueN, valueT, random;

    file = fopen("C:\\Users\\Cabral\\Documents\\Prog\\teste.txt","w+");     //Dps trocar diretório para "teste.txt"
    for(i = 0; i < MAX; i++){
        random = rand() % MAX + 1;
        bt = add(bt, random);
        node = insertNode(node, random);
    }
    /*for(i = 0; i < 10; i++){
        scanf("%d", &random);
        valueN = search(node,random);
        valueT = searchTree(bt,random)
        fprintf(file,"%d %d\n", random, valueN, valueT);
    }*/
    for(i = 0; i < MAX; i++){
        random = rand() % MAX + 1;
        valueN = search(node, random);
        valueT = searchTree(bt, random);
        fprintf(file, "%d %d %d\n", random, valueN, valueT);
    }

    fclose(file);

    return 0;
}