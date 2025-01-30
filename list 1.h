#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int value;
    struct Node* next;
} Node
Node* createNode(int value);
int getValue(Node* node);
void setValue(Node* node, int value);