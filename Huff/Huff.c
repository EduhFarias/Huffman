//
// Created by Eduardo on 04/10/2017.
//

#include "Huff.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

void compress(FILE *file){
    int c, i, aux = 0;
    BinaryTree *bt = createEmpty();
    int ch[256] = {0};

    while((c = fgetc(file)) != EOF){
        ch[c]++;
    }
    for(i = 0; i < 256; i++){
        if(ch[i] > 0){
            printf("%c %d\n", i, ch[i]);
            bt = createBinaryTree((unsigned char)i,ch[i],bt);
        }
    }
    printx(bt);
    //bt = huff(bt);
    //printPreOrder(bt);
}