#ifndef QUEUE_H
#define QUEUE_H
#define MAX_SIZE 5 
typedef struct {
    int queue[MAX_SIZE];  
    int rear;             
} Queue;
void initializeQueue(Queue *q);
int is_empty(Queue *q);
int is_full(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int peek(Queue *q);

#endif
