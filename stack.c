#include <stdio.h>
#include "stack.h"


void initStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, int item) {
    if (stack->top < MAX_SIZE_S - 1) {
        stack->items[++stack->top] = item;
    } else {
        printf("Stack Overflow: Unable to push %d\n", item);
    }
}


int pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top--];
    } else {
        printf("Stack Underflow: Unable to pop\n");
        return -1; 
    }
}


int peek_s(const Stack* stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top];
    } else {
        printf("Stack is empty: No item to peek\n");
        return -1;
    }
}
int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 6);
    push(&stack, 3);

    printf("Top element is %d\n", peek_s(&stack));

    printf("Popped element is %d\n", pop(&stack));
    printf("Top element after pop is %d\n", peek_s(&stack));

    return 0;
}