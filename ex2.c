#include <stdio.h>
#include <stdlib.h>
#include "Reverse.h"


void reverseList(Node** head) {
    if (*head == NULL) {
        return; 
    }
    Node* current = *head;
    Node* temp = NULL;
    while (current != NULL) {
        temp = getNext(current);
        setNext(current, getPrev(current));
        setPrev(current, temp);
        current = getPrev(current);
    }
    *head = temp;
}


void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", getValue(current));
        current = getNext(current);
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    head = createNode(10);
    Node* second = createNode(11);
    Node* third = createNode(15);

  
    setNext(head, second);
    setPrev(second, head);
    setNext(second, third); 
    setPrev(third, second);  

    printf("Original List:\n");
    printList(head);

    reverseList(&head);  

    printf("Reversed List:\n");
    printList(head);

    return 0;
}
