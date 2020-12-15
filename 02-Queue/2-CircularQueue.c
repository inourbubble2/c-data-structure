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
	q->front = 0;
	q->rear = 0;
}

int isEmpty(Queue *q) {
	return (q->front == q->rear);
}

int isFull(Queue *q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Queue *q, element item) {
	if(isFull(q)) fprintf(stderr, "QUEUE IS FULL!!!");
	q->data[++(q->rear) % MAX_QUEUE_SIZE] = item;
}

element dequeue(Queue *q) {
	if(isEmpty(q)) fprintf(stderr, "QUEUE IS EMPTY");
	return q->data[++(q->front) % MAX_QUEUE_SIZE];
}

int main(void) {
	Queue q;
	init(&q);
	
	enqueue(&q, 3);
	enqueue(&q, 2);
	enqueue(&q, 1);
	
	printf("%d ", dequeue(&q));
	printf("%d ", dequeue(&q));
	printf("%d ", dequeue(&q));
	
	return 0;
	
}
