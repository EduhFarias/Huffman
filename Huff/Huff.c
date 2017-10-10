//
// Created by Eduardo on 04/10/2017.
//

#include "Huff.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(FILE *file){
    int c, i, aux = 0;
    BinaryTree *bt = createEmpty();
    unsigned char ch[256] = {0};
    unsigned char table[256][50];


    while((c = fgetc(file)) != EOF){ //Percorre o arquivo e soma +1 em toda posição referente ao caracter
        ch[c]++;
    }
    for(i = 0; i < 256; i++){        //Checa toda as 256 posições e cria um nó pra cara caracter
        if(ch[i] > 0){
            //printf("%c %d\n", i, ch[i]);
            bt = createBinaryTree((unsigned char)i,ch[i],bt);
        }
    }
    //printx(bt);
    bt = huff(bt);

    //createTable(bt,table[256][50],ch);

    unsigned char rest = 2;
    unsigned char trash = (8 - rest) << 5;
    FILE *oFile;
    //oFile = fopen("C:\\Users\\Cabral\\Documents\\Prog\\saida.huff", "wb");

    //fprintf(oFile,"%c", trash);
    //fprintf(oFile,"%c",);
    printPreOrder(bt);
}

void createTable(BinaryTree *bt,unsigned char table[][50], unsigned char *ch){
    int i;
    unsigned char string[50];
    for(i = 0; i < 256; i++){
        if(ch[i] > 0){
            *string = createCode(bt,(unsigned char)i,string);
            strcat(table[i][50],string[50]);
        }
    }
}

unsigned char* createCode(BinaryTree *bt, unsigned char position, unsigned char *string){
    if(bt->left == NULL && bt->right == NULL || bt->c == position){
        return string;
    } else{
        string = createCode(bt,position+1,string) + '0';
        string = createCode(bt,position+1,string) + '1';
    }
}

int isBit_i_set(unsigned char c, int i){
    unsigned char mask = 1 << i;
    return mask & c;
}
