//
// Created by Eduardo on 25/10/2017.
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
    int value = 0, i, x = 0, add = 1;
    for(i = 0; i < size; i++){
        if(aux[i]){
            if((size-1) - i == 0){
                value += 1;
            } else{
                while(x < ((size-1) - i) ){
                    add *= 2;
                    x++;
                }
                value += add;
                add = 1;
                x = 0;
            }
        }
    }
    return value;
}

