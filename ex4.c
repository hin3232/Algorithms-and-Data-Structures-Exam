#include <stdio.h>
#include "queue.h"

/*مكدس باستخدام طابورين*/ 
typedef struct {
    Queue q1, q2;
} StackTwoQueues;
void initStackTwo(StackTwoQueues *stack) {
    initializeQueue(&stack->q1);
    initializeQueue(&stack->q2);
}
void pushTwo(StackTwoQueues *stack, int value) {
    enqueue(&stack->q2, value); 
    while (!is_empty(&stack->q1)) {
        enqueue(&stack->q2, dequeue(&stack->q1));
    }
    Queue temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}
int popTwo(StackTwoQueues *stack) {
    return dequeue(&stack->q1);
}
int peekTwo(StackTwoQueues *stack) {
    return peek(&stack->q1);
}
int isEmptyTwo(StackTwoQueues *stack) {
    return is_empty(&stack->q1);
}
int main() {
    StackTwoQueues s2;
    initStackTwo(&s2);
    printf("Using Two Queues:\n");
    pushTwo(&s2, 1);
    pushTwo(&s2, 2);
    pushTwo(&s2, 3);
    printf("Top: %d\n", peekTwo(&s2));
    printf("Popped: %d\n", popTwo(&s2));
    printf("Top after pop: %d\n", peekTwo(&s2));
    return 0;
}
