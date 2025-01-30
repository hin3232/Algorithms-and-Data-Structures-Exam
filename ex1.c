


#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
void insertAtPosition(Node** head, int value, int k) {
    /*empty list*/
    if (*head == NULL) {
        if (k == 0) {
            *head = createNode(value);  
        } else {
            printf("Error: Index out of bounds.\n");
        }
        return;
    }

    /*Insert at the head */ 
    if (k == 0) {
        Node* newNode = createNode(value);  
        setNext(newNode, *head);            
        *head = newNode;                  
        return;
    }

    /* Insert at the end*/ 
    Node* current = *head;
    int index = 0;

    while (current != NULL && index < k - 1) {
        current = getNext(current);  
        index++;
    }

    /* نتحقق إذا كان الموضع خارج الحدود*/
    if (current == NULL || index != k - 1) {
        printf("Error\n");
        return;
    }

    /* نذرج العقدة الجديدة بعد العقدة الحالية*/
    Node* newNode = createNode(value);      
    setNext(newNode, getNext(current));     
    setNext(current, newNode);              
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", getValue(current));
        current = getNext(current);
    }
    printf("NULL\n");
}
int main() {
    Node* head = NULL;  
    insertAtPosition(&head, 1, 0);  
    insertAtPosition(&head, 45, 1);  
    insertAtPosition(&head, 300, 2);   
    printList(head);  
    return 0;
}
