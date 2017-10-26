//
// Created by Eduardo on 03/10/2017.
//
#include <stdlib.h>
#include <stdio.h>
#include "Compress.h"
#include "Decompress.h"

int main(void){
    printf("Deseja (C)omprimir ou (D)escomprimir ?\n");
    char c;
    scanf("%c", &c);

    FILE *file;
    file = fopen("C:\\Users\\Cabral\\Documents\\Prog\\comp.txt", "rb");
    if(file == NULL){
        printf("Arquivo nao pode ser aberto\n");
        exit(1);
    }

    if(c == 'C'){
        compress(file);
    } else if(c == 'D'){
        decompress(file);
    } else{
        printf("Comando inválido, programa está sendo encerrado\n");
        system("pause");
        exit(1);
    }

}
