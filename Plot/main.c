#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "LinkedList.h"
#include "BinaryTree.h"

int main() {
    FILE *file;
    file = fopen("C:\\Users\\Cabral\\Documents\\Prog\\teste.txt","w+");     //Dps trocar diretório para "teste.txt"
    fputs("Testando saida", file);
    fclose(file);

    return 0;
}