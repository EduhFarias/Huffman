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

    FILE *iFile;
    iFile = fopen("C:\\Users\\Cabral\\Documents\\Prog\\saida.huff", "rb");   //DEPOS MODIFICAR PARA LER O DIRETORIO DO ARQ
    if(iFile == NULL){
        printf("Arquivo nao pode ser aberto\n");
        exit(1);
    }

    if(c == 'C'){
        FILE *oFile = fopen("C:\\Users\\Cabral\\Documents\\Prog\\saida.huff", "wb");
        compress(iFile, oFile);
    } else if(c == 'D'){
        FILE *oFile = fopen("C:\\Users\\Cabral\\Documents\\Prog\\saida.txt", "wb");
        decompress(iFile, oFile);
    } else{
        printf("Comando inválido, programa está sendo encerrado\n");
        system("pause");
        exit(1);
    }

}
