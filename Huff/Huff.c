//
// Created by Eduardo on 04/10/2017.
//

#include "Huff.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(FILE *file){
    int c, i, j;
    BinaryTree *bt = createEmpty();
    unsigned char ch[256] = {0};
    unsigned char table[256][256];

    for(i = 0; i < 256; i++){
        memset(table[i],'\0',256);
    }

    while((c = fgetc(file)) != EOF){ //Percorre o arquivo e soma +1 em toda posição referente ao caracter
        ch[c]++;
    }
    for(i = 0; i < 256; i++){        //Checa toda as 256 posições e cria um nó pra cara caracter
        if(ch[i] > 0){
            bt = createBinaryTree((unsigned char)i,ch[i],bt, NULL, NULL);
        }
    }
    bt = huff(bt);

    unsigned char aux[256];
    memset(aux,NULL,256);

    createTable(bt, table, 0, aux);

    FILE *oFile;
    oFile = fopen("C:\\Users\\Cabral\\Documents\\Prog\\saida.huff", "wb");

    int bits = 7, pos = 0, bit = 0;
    unsigned char b = 0;

    rewind(file);
    while((c = fgetc(file)) != EOF){
        while(table[c][pos] != '\0'){
            if(bits < 0){
                fprintf(oFile,"%c", b);
                //printf("%c",b);
                bits = 7;
                b = 0;
            }
            if(table[c][pos] == '1'){
                b = setBit(b, bits);
            }
            bits--;
            pos++;
            bit++;
        }
        pos = 0;
    }

    int rest = bit % 8;
    rewind(oFile);
    unsigned char size_tree = (unsigned char)printPreOrder(bt, oFile);
    unsigned char trash = (unsigned char)(8 - rest) << 5;
    unsigned char fByte = trash | (size_tree >> 8);

    rewind(oFile);
    fprintf(oFile,"%c", fByte);
    fprintf(oFile,"%c", size_tree);

    //---------- TESTE --------
    printf("- trash/size_tree: %d%d %d", trash, size_tree, rest);
    printOrder(bt);
    for(i = 0; i < 256; i++){
        if(ch[i] > 0){
                //printf("%c: %s\n", i,table[i]);
        }
    }
    //----------
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

BinaryTree* huff(BinaryTree *bt){                                           //Começa o merge
    while(getNext(bt)) {                                                             //Enquanto ouver mais de um nó
        BinaryTree *A, *B;                     //Cria dois nós auxiliares
        A = getNode(bt);                                                    //A recebe o nó de menor frequência
        B = getNode(getNext(bt));
        int freq = (getFreq(A)) + (getFreq(B));

        bt = removeNode(bt);
        bt = removeNode(bt);
        bt = createBinaryTree('*', freq, bt, A, B);
    }
    return bt;
}

int isBit_i_set(unsigned char c, int i){
    unsigned char mask = 1 << i;
    return mask & c;
}

unsigned char setBit(unsigned char c, int i){
    unsigned char mask = 1 << i;
    return c | mask;
}
