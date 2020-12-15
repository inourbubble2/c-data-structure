#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10
typedef int element;
typedef struct Queue {
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
} Queue;

void init(Queue *q) {
	q->front = -1;
	q->rear = -1;
}

int isFull(Queue *q) {
	return (q->rear == MAX_QUEUE_SIZE - 1);
}

int isEmpty(Queue *q) {
	return (q->front == q->rear);
}

void enqueue(Queue *q, element item) {
	if(isFull(q)) fprintf(stderr, "QUEUE IS FULL!!!\n");
	q->data[++(q->rear)] = item;
}

element dequeue(Queue *q) {
	if(isEmpty(q)) fprintf(stderr, "QUEUE IS EMPTY!!!\n");
	return q->data[++(q->front)];
}

int main(void) {
	Queue q;
	init(&q);
	
	
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 3);
	enqueue(&q, 3);
	enqueue(&q, 3);
	
	printf("%d ", dequeue(&q));
	printf("%d ", dequeue(&q));
	printf("%d ", dequeue(&q));
	
	return 0;
}
