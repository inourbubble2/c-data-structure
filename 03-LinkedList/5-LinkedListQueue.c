#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node *link;
}Node;
typedef struct Queue {
	Node *front, *rear;
} Queue;

void init(Queue *q) {
	q->front = q->rear = NULL;
}

int isEmpty(Queue *q) {
	return (q->front == NULL);
}

int isFull(Queue *q) {
	return 0;
}

void printQueue(Queue *q) {
	Node *node = q->front;
	while(node != NULL)	{
		printf("%d -> ", node->data);
		node = node->link;
	}
	printf("\n");
}

void enqueue(Queue *q, element data) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->link = NULL;
	if(isEmpty(q)) {
		q->front = q->rear = node;
	} else {
		q->rear->link = node;
		q->rear = node;	
	}
}

element dequeue(Queue *q) {
	if(isEmpty(q)) {
		fprintf(stderr, "QUEUE IS EMPTY!!!");
	}
	Node *node = q->front;
	element data = node->data;
	q->front = q->front->link;
	free(node);
	return data;
}

int main(void) {
	Queue *q = (Queue *)malloc(sizeof(Queue));
	init(q);
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 99);
	printQueue(q);
	printf("%d\n", dequeue(q));
	printf("%d\n", dequeue(q));
	printf("%d\n", dequeue(q));
	printf("%d\n", dequeue(q));
	printQueue(q);
	return 0;
}
