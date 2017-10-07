//
// Created by Eduardo on 07/10/2017.
//

#include "Helpful.h"

void Swap(int *x, int *y){
    int aux;
    aux = *y;
    *y = *x;
    *x = aux;
}

int* Quick(int *v, int size){
    if(size <= 1){
        return v;
    }
    else{
        int pivot = v[size / 2];
        int a, b;
        a = 0;
        b = size - 1;

        while(a < b){
            while(v[a] < pivot){a++;}
            while(v[b] > pivot){b--;}
            if(a < b){
                Swap(&v[a], &v[b]);
                a++;
                b--;
            }
        }
        Quick(v, a);
        Quick(v+a, size - a);
    }
    return v;
}