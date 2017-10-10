//
// Created by Eduardo on 03/10/2017.
//
#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"
#include "Huff.h"

int main(void){
    FILE *file;
    file = fopen("C:\\Users\\Cabral\\Documents\\Prog\\comp.txt", "rb");
    if(file == NULL){
        printf("Arquivo nao pode ser aberto\n");
        exit(1);
    }
    compress(file);
    //decompress(file);
    fclose(file);
}
