//
// Created by Eduardo on 04/10/2017.
//

#include "Huff.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(FILE *file){
    int c, i, size_tree, j, rest = 0;
    BinaryTree *bt = createEmpty();
    unsigned char ch[256] = {0};
    unsigned char table[256][256];


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
    for (i = 0; i < 256; i++){
        if(ch[i] > 0){
            int freq = ch[i];
            for (j = 0; strlen(table[i]); j++){
            }
            rest+= (freq * j);
        }
    }
    rest = rest % 8;
    unsigned char trash = (8 - rest) << 5;
    FILE *oFile;
    oFile = fopen("C:\\Users\\Cabral\\Documents\\Prog\\saida.huff", "wb");

    printOrder(bt);
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
    return;;
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
