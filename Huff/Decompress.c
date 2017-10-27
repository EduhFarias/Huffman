//
// Created by Eduardo on 24/10/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "Decompress.h"
#include "Helpful.h"

void decompress(FILE *iFile){

    FILE *oFile  = fopen("C:\\Users\\Cabral\\Documents\\Prog\\saida.txt", "wb");
    //-------------------------------------------------------------------------------

    unsigned char fByte, sByte, b;
    fByte = (unsigned char)fgetc(iFile);
    sByte = (unsigned char)fgetc(iFile);
    b = fByte;

    int trash[3], size_tree[13];

    int count = 0;
    int bits = 7;
    while(count < 16){
        if(bits < 0) {
            bits = 7;
            b = sByte;
        }
        if(count < 3){
            if(isBit_i_set(b,bits)){
                trash[count] = 1;
            } else trash[count] = 0;
        } else{
            if(isBit_i_set(b,bits)){
                size_tree[count-3] = 1;
            } else size_tree[count-3] = 0;
        }
        bits--;
        count++;
    }

    int lixo = dec_converter(trash,3);
    int size = dec_converter(size_tree,13);
    printf("lixo %d size %d\n", lixo, size);
    //-------------------------------------------------------------------------------

   char tree[size];
    int i = 0, c, aux;

    while(i < size){
        c = fgetc(iFile);
        if((char)c == '\\') {
            aux = fgetc(iFile);
            tree[i] = (char)aux;
        }   else tree[i] = (char)c;
        i++;
    }

    BinaryTree *bt = createEmpty();
    bt = rebuildTree(bt, tree, size);
    printOrder(bt);


    fclose(iFile);
    fclose(oFile);
}

