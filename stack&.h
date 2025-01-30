#ifndef STACK_H
#define STACK_H
#define MAX_SIZE_S 100
typedef struct {
    int items[MAX_SIZE_S];
    int top;
} Stack;
void initStack(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek_s(const Stack* stack);
#endif 