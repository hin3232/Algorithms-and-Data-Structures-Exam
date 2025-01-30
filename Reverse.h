#ifndef REVERSE_H
#define REVERSE_H
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;
Node* getNext(Node* node);
void setNext(Node* node, Node* nextNode);
Node* getPrev(Node* node);
void setPrev(Node* node, Node* prevNode);
#endif