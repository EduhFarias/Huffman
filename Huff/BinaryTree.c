//
// Created by Eduardo on 03/10/2017.
//

#include "BinaryTree.h"


typedef struct b_tree{
    unsigned char c;
    int freq;
    struct b_tree *left;
    struct b_tree *right;
}BinaryTree;