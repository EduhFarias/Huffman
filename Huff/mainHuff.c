//
// Created by Eduardo on 03/10/2017.
//
#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"
#include "Compress.h"

int main(void){
    printf("Deseja (C)omprimir ou (D)escomprimir ?\n");
    char c;
    scanf("%c", &c);
    system("clear");

    if(c == 'C'){
        compress();
    } else if(c == 'D'){
        //decompress();
    } else{
        printf("Comando inválido, programa está sendo encerrado\n");
    }

}
