//
// Created by Eduardo on 01/10/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct node{
    int item;
    struct node *next;
}Node;

Node* createLinkedList(){
    return NULL;
}

Node* insertNode(Node *node, int item){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->item = item;
    new_node->next = node;
    return new_node;
}

int search(Node *node, int item){
    int count = 0;
    while(node){
        if(node->item == item){
            return count;
        }
        count++;
        node = node->next;
    }
}