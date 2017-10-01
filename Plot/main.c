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
    int i, value, random;

    file = fopen("C:\\Users\\Cabral\\Documents\\Prog\\teste.txt","w+");     //Dps trocar diretório para "teste.txt"
    for(i = 0; i < MAX; i++){
        value = rand() % MAX + 1;
        bt = add(bt, value);
        node = insertNode(node, value);
    }
    for(i = 0; i < 10; i++){
        scanf("%d", &random);
        value = search(node,random);
        fprintf(file,"%d %d\n", random, value);
    }

    fclose(file);

    return 0;
}