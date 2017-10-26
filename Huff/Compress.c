//
// Created by Eduardo on 04/10/2017.
//

#include "Compress.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Helpful.h"

void compress(FILE *iFile){

    FILE *oFile = fopen("C:\\Users\\Cabral\\Documents\\Prog\\saida.huff", "wb");

    int c, i, j;
    BinaryTree *bt = createEmpty();
    unsigned char ch[256] = {0};

    //-------------------------------------------------------------------------------

    while((c = fgetc(iFile)) != EOF){ //Percorre o arquivo e soma +1 em toda posição referente ao caracter
        ch[c]++;
    }
    for(i = 0; i < 256; i++){        //Checa toda as 256 posições e cria um nó pra cara caracter
        if(ch[i] > 0){
            bt = createBinaryTree((unsigned char)i,ch[i],bt, NULL, NULL);
        }
    }
    bt = huff(bt);
    //-------------------------------------------------------------------------------

    unsigned char aux[256];
    unsigned char table[256][256];

    for(i = 0; i < 256; i++){
        memset(table[i],'\0',256);
    }
    memset(aux,NULL,256);

    createTable(bt, table, 0, aux);
    //-------------------------------------------------------------------------------

    int bits = 7, pos = 0, bit = 0;

    rewind(iFile);
    while((c = fgetc(iFile)) != EOF){
        while(table[c][pos] != '\0'){
            bit++;
            pos++;
        }
        pos = 0;
    }
    rewind(iFile);

    int rest = bit % 8;
    //-------------------------------------------------------------------------------

    int trash[3], count = 0;
    converter((8-rest),3, trash);
    int size_tree[13];
    converter(sizeTree(bt, oFile),13, size_tree);

    unsigned char byteTS = 0;

    while(count < 17){
        if(bits < 0){
            fprintf(oFile,"%c", byteTS);
            bits = 7;
            byteTS = 0;
        }
        if(count < 3){
            if(trash[count] == 1) byteTS = setBit(byteTS, bits);
        } else {
            if(size_tree[count-3] == 1) byteTS = setBit(byteTS, bits);
        }
        bits--;
        count++;
    }
    printPreOrder(bt, oFile);
    //-------------------------------------------------------------------------------

    unsigned char oByte = 0;
    pos = 0, bits = 7;

    while((c = fgetc(iFile)) != EOF){
        while(table[c][pos] != '\0'){
            if(bits < 0){
                fprintf(oFile,"%c", oByte);
                bits = 7;
                oByte = 0;
            }
            if(table[c][pos] == '1'){
                oByte = setBit(oByte, bits);
            }
            bits--;
            pos++;
        }
        pos = 0;
    }
    //-------------------------------------------------------------------------------

    fclose(iFile);
    fclose(oFile);
}

void createTable(BinaryTree *bt, unsigned char table[][256], int pos, unsigned char *aux) {
    if ( (getLeft(bt) == NULL) && (getRight(bt) == NULL) ){
        aux[pos] = '\0';
        strcpy(table[getValue(bt)], aux);
        pos--;
        return;
    } else {
        aux[pos] = '0';
        createTable(getLeft(bt), table, pos + 1, aux);
        aux[pos] = '1';
        createTable(getRight(bt), table, pos + 1, aux);
    }
    pos--;
}

BinaryTree* huff(BinaryTree *bt){
    while(getNext(bt)) {
        BinaryTree *A, *B;
        A = getNode(bt);
        B = getNode(getNext(bt));
        int freq = (getFreq(A)) + (getFreq(B));

        bt = removeNode(bt);
        bt = removeNode(bt);
        bt = createBinaryTree('*', freq, bt, A, B);
    }
    return bt;
}
