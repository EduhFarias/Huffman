//
// Created by Eduardo on 04/10/2017.
//

#include "Compress.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Helpful.h"


void compress(FILE *iFile, FILE *oFile){

    BinaryTree *bt = createEmpty();
    long long int ch[256] = {0};
    frequency(iFile, ch);
    bt = createNode(ch, bt);
    bt = huff(bt);
    unsigned char table[256][256], aux[256];
    initialize(table, aux);
    createTable(bt, table, 0, aux);
    rewind(iFile);
    int trash = sizeTrash(iFile, table);
    rewind(iFile);
    writeTrash_sizeTree(oFile, trash, bt);
    printPreOrder(bt, oFile);
    converterComp(iFile, oFile, table);

    fclose(iFile);
    fclose(oFile);
}

void frequency(FILE *iFile, long long int *ch){
    int c;
    while((c = fgetc(iFile)) != EOF){
        ch[c]++;
    }
}

BinaryTree* createNode(long long int *ch, BinaryTree *bt){
    int i;
    for(i = 0; i < 256; i++){
        if(ch[i] > 0){
            bt = createQueue((unsigned char) i, ch[i], bt, NULL, NULL);
        }
    }
    return bt;
}

int sizeTrash(FILE *iFile, unsigned char table[][256]){
    int pos = 0, bits = 0, c;

    while((c = fgetc(iFile)) != EOF){
        while(table[c][pos] != '\0'){
            bits++;
            pos++;
        }
        pos = 0;
    }
    int rest = bits % 8;
    return (8 - rest);
}

void writeTrash_sizeTree(FILE *oFile, int sizeTrash, BinaryTree *bt){
    int trash[3], count = 0;
    bin_converter((sizeTrash),3, trash);
    int size_tree[13];
    bin_converter(sizeTree(bt),13, size_tree);

    unsigned char byteTS = 0;
    int bits = 7;

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
}

void converterComp(FILE *iFile, FILE *oFile, unsigned char table[][256]){
    unsigned char oByte = 0;
    int pos = 0, bits = 7, c;

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
    if(bits != 7) fprintf(oFile, "%c", oByte);
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
        long long int freq = (getFreq(A)) + (getFreq(B));

        bt = removeNode(bt);
        bt = removeNode(bt);
        bt = createQueue('*', freq, bt, A, B);
    }
    return bt;
}
