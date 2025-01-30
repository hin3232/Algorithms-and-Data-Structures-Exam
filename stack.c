#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  
#include <string.h>
#include "stack&.h"  
#define MAX_SIZE 100  
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
void infix_to_postfix(const char* infix) {
    Stack stack;
    initStack(&stack);
    char postfix[MAX_SIZE] = "";
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[k++] = ch;
        } 
        else if (ch == '(') {
            push(&stack, ch);
        } 
        else if (ch == ')') {
            while (!is_empty_s(&stack) && peek_s(&stack) != '(')
                postfix[k++] = pop(&stack);
            pop(&stack);
        } 
        else {
            while (!is_empty_s(&stack) && precedence(peek_s(&stack)) >= precedence(ch))
                postfix[k++] = pop(&stack);
            push(&stack, ch);
        }
    }
    while (!is_empty_s(&stack))
        postfix[k++] = pop(&stack);
    postfix[k] = '\0'; 
    printf("Postfix: %s\n", postfix);
}
