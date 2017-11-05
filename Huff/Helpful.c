#include "Helpful.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int isBit_i_set(unsigned char c, int i){
    unsigned char mask = 1 << i;
    return mask & c;
}

unsigned char setBit(unsigned char c, int i){
    unsigned char mask = 1 << i;
    return c | mask;
}

void initialize(char table[][256],  char *aux){
    int i;
    for(i = 0; i < 256; i++){
        memset(table[i],'\0',256);
    }
    memset(aux,NULL,256);
}

void bin_converter(int item, int size, int *aux){
    int i = 0, j = 0;
    while(item != 0){
        j = item % 2;
        aux[size-1 - i] = j;
        i++;
        item = item / 2;
    }
}

int dec_converter(int *aux, int size){
    int value = 0, i;
    for(i = 0; i < size; i++){
        if(aux[i]){
            if((size-1) - i == 0){
                value += 1;
            } else{
                value += pow(2,(size-1) - i);
            }
        }
    }
    return value;
}

