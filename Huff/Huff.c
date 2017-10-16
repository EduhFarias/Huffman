//
// Created by Eduardo on 04/10/2017.
//

#include "Huff.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(FILE *file){
    int c, i, size_tree, j;
    BinaryTree *bt = createEmpty();
    unsigned char ch[256] = {0};
    unsigned char table[256][256];


    while((c = fgetc(file)) != EOF){ //Percorre o arquivo e soma +1 em toda posição referente ao caracter
        ch[c]++;
    }
    for(i = 0; i < 256; i++){        //Checa toda as 256 posições e cria um nó pra cara caracter
        if(ch[i] > 0){
            bt = createBinaryTree((unsigned char)i,ch[i],bt);
        }
    }
    bt = huff(bt);

    unsigned char *aux, rest;
    createTable(bt, table, 0, aux);
    for (i = 0; i < 256; i++){
        if(ch[i] > 0){
            int freq = ch[i];
            for (j = 0; strlen(table[i]); j++){
            }
            rest+= (freq * j);
        }
    }

    unsigned char trash = (8 - rest) << 5;
    FILE *oFile;
    oFile = fopen("C:\\Users\\Cabral\\Documents\\Prog\\saida.huff", "wb");


    size_tree = printPreOrder(bt, oFile);
    rewind(oFile);
    fprintf(oFile,"%c", trash);
    fprintf(oFile,"%c",size_tree);
    for(i = 0; i < 256; i++){
        if(ch[i] > 0){
            for(j = 0; j < 256; j++){
                printf("%c", table[i][j]);
            }
        }
    }
}

void createTable(BinaryTree *bt, unsigned char table[][256], int pos, unsigned char *aux) {
    if (bt->left == NULL && bt->right == NULL) {
        aux[pos] = '\0';
        strcpy(table[bt->c], aux);
        return;
    } else {
        aux[pos] = '0';
        createTable(bt->left, table, pos + 1, aux);
        aux[pos] = '1';
        createTable(bt->right, table, pos + 1, aux);
    }
}


int isBit_i_set(unsigned char c, int i){
    unsigned char mask = 1 << i;
    return mask & c;
}
