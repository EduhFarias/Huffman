//
// Created by Cabral on 25/10/2017.
//

#include "Helpful.h"

int isBit_i_set(unsigned char c, int i){
    unsigned char mask = 1 << i;
    return mask & c;
}

unsigned char setBit(unsigned char c, int i){
    unsigned char mask = 1 << i;
    return c | mask;
}

void converter(int item, int size, int *aux){
    int i = 0, j = 0;
    while(item != 0){

        j = item % 2;
        aux[size-1 - i] = j;
        i++;
        item = item / 2;
    }
}

