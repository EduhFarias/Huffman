//
// Created by Eduardo on 24/10/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "Decompress.h"

void decompress(){
    printf("Digite o nome do arquivo de entrada: \n");
    char A1[500];
    scanf("%s", A1);                                    //Fazer uma função no arquivo helpful.c para fazer este processo

    FILE *iFile = fopen("A1", "rb");

    printf("Digite o nome do arquivo de saída: \n");
    char A2[500];
    scanf("%s", A2);
    FILE *oFile = fopen("A2", "wb"); //Posição dessa chamada ainda não definida

    if(iFile == NULL){
        printf("O arquivo nao pode ser aberto\n");
        exit(1);
    }

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