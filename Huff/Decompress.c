//
// Created by Eduardo on 24/10/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "Decompress.h"

void decompress(FILE *iFile){

    FILE *oFile  = fopen("C:\\Users\\Cabral\\Documents\\Prog\\saida.huff", "wb");

    int fByte, sByte;
    fByte = fgetc(iFile);
    sByte = fgetc(iFile);

    int trash, size_tree;

    trash = (unsigned char)fByte >> 5;
    size_tree = sByte;

    int i = 0, c;

    char tree[size_tree];

    while(i < size_tree){
        c = fgetc(iFile);
        tree[i] = (char)c;
    }

    fseek(iFile, NULL, SEEK_END);

    int count = ftell(iFile);
    int bits_max = count - trash;
    i = 0;
    while(i < bits_max){
        //Realiza a operação de conversão
    }



    fclose(iFile);
    fclose(oFile);
}