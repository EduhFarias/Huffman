#ifndef PLOT_LINKEDLIST_H
#define PLOT_LINKEDLIST_H

typedef struct node Node;

Node* createLinkedList();

Node* insertNode(Node *node, int item);

int search(Node *node, int item);


#endif //PLOT_LINKEDLIST_H
