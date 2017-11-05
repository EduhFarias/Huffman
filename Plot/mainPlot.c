#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "BST.h"

#define MAX 1000

int main() {
    FILE *file;
    BST *bt = createEmptyBinaryTree();
    Node *node = createLinkedList();
    int i, valueN, valueT, random;

    file = fopen("C:\\Users\\Cabral\\Documents\\Prog\\count.txt","w+");
    for(i = 0; i < MAX; i++){
        random = rand() % MAX + 1;
        bt = add(bt, random);
        node = insertNode(node, random);
    }
    for(i = 0; i < MAX; i++){
        random = rand() % MAX + 1;
        valueN = search(node, random);
        valueT = searchTree(bt, random);
        fprintf(file, "%d %d %d\n", random, valueN, valueT);
    }

    fclose(file);

    return 0;
}
