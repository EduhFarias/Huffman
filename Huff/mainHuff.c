#include <stdlib.h>
#include <stdio.h>
#include "Compress.h"
#include "Decompress.h"

int main(void){
    printf("Deseja (C)omprimir ou (D)escomprimir ?\n");
    char c;
    scanf("%c", &c);

    FILE *iFile;
    iFile = fopen("C:\\Users\\Cabral\\Documents\\Prog\\saida.huff", "rb");
    if(iFile == NULL){
        printf("Arquivo nao pode ser aberto\n");
        exit(1);
    }

    if(c == 'C'){
        FILE *oFile = fopen("C:\\Users\\Cabral\\Documents\\Prog\\saida.huff", "wb");
        compress(iFile, oFile);
    } else if(c == 'D'){
        FILE *oFile = fopen("C:\\Users\\Cabral\\Documents\\Prog\\saida.3gp", "wb");
        decompress(iFile, oFile);
    } else{
        printf("Comando inválido, programa está sendo encerrado\n");
        exit(1);
    }

}
