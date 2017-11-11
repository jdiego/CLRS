// C program for array implementation of queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a queue
typedef struct queue_t
{
    int front, rear;
    unsigned size, capacity;
    int* buffer;
} queue;

queue* create_queue(unsigned capacity)
{
    queue* q = (queue*) malloc(sizeof(struct queue_t));
    q->buffer = (int*) malloc(sizeof(int) * capacity);
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    return q;
}
int is_full(const queue* q)
{
    return q->size == q->capacity;
}
int is_empty(const queue* q)
{
    return q->size == 0;
}

void enqueue(queue* q, int item)
{
    if(is_full(q))
        return;
    q->rear = (q->rear + 1) % q->capacity;
    q->buffer[q->rear] = item;
    q->size++;
}
int dequeue(queue* q)
{
    if(is_empty(q))
        return INT_MIN;
    int temp = q->buffer[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return temp;
}
// Function to get front of queue
int front(queue* q)
{
    if (is_empty(q))
        return INT_MIN;
    return q->buffer[q->front];
}
void clear(queue** ptr)
{
    queue* q = *ptr;
    free(q->buffer);
    free(q);
    *ptr = NULL;
}
int main(void)
{
    queue* q = create_queue(1000);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    printf("%d dequeued from queue\n", dequeue(q));

    printf("Front item is %d\n", front(q));
    clear(&q);
}
