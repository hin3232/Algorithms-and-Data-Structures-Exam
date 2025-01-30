#include <stdio.h>
#include "Queue.h"

/* طابور واحد*/ 
typedef struct {
    Queue q;
} StackSingleQueue;

void initStackSingle(StackSingleQueue *stack) {
    initializeQueue(&stack->q);
}
void pushSingle(StackSingleQueue *stack, int value) {
    int size = stack->q.rear + 1;
    enqueue(&stack->q, value);  
    for (int i = 0; i < size; i++) {
        enqueue(&stack->q, dequeue(&stack->q));
    }
}
int popSingle(StackSingleQueue *stack) {
    return dequeue(&stack->q);
}
int peekSingle(StackSingleQueue *stack) {
    return peek(&stack->q);
}
int isEmptySingle(StackSingleQueue *stack) {
    return is_empty(&stack->q);
}
int main() {
    StackSingleQueue s1;
    initStackSingle(&s1);
    printf("Using Single Queue:\n");
    pushSingle(&s1, 1);
    pushSingle(&s1, 2);
    pushSingle(&s1, 3);
    printf("Top: %d\n", peekSingle(&s1));
    printf("Popped: %d\n", popSingle(&s1));
    printf("Top after pop: %d\n", peekSingle(&s1));
    return 0;
}
