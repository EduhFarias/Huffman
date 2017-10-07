//
// Created by Cabral on 04/10/2017.
//

#include "Huff.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include "Helpful.h"

void compress(FILE *file){
    int c;
    int ch[256] = {0};
    while((c = fgetc(file)) != EOF){
        ch[c]++;
    }
    int i;
    for(i = 0; i < 256; i++){
        if(ch[i] > 0){
            printf("%c %d\n", i, ch[i]);
        }
    }
    ch = quickSort(ch,256);
}

/*BinaryTree* huff(BinaryTree *head){
    while(head->next) {
        BinaryTree *A, *B, *prev = NULL;
        A = removeNode(head);
        B = removeNode(head);

    }
}*/