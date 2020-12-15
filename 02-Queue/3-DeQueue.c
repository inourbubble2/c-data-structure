#include <stdio.h>
#include <stdlib.h>

#define MAX_DEQUE_SIZE 10

typedef int element;
typedef struct Deque {
	element data[MAX_DEQUE_SIZE];
	int front, rear;
} Deque;

void init(Deque *d) {
	d->front = d->rear = 0;
}

int isEmpty(Deque *d) {
	return (d->front == d->rear);
}

int isFull(Deque *d) {
	return ((d->rear + 1) % MAX_DEQUE_SIZE == d->front);
} 

void printDeque(Deque *d) {
	printf("DEQUE(front=%d, rear=%d) = ", d->front, d->rear);
	if(!isEmpty(d)) {
		int i = d->front;
		do {
			i = (i + 1) % MAX_DEQUE_SIZE;
			printf("%d | ", d->data[i]);
			if (i == d->rear)
				break;
		} while (i != d->front);
	}
	printf("\n");
}

void addFront(Deque *d, element item) {
	if(isFull(d)) fprintf(stderr, "DEQUE IS FULL!!!");
	d->data[(--(d->front) + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE] = item;
}

void addRear(Deque *d, element item) {
	if(isFull(d)) fprintf(stderr, "DEQUE IS FULL!!!");
	d->data[(++(d->rear) + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE] = item;
}

element deleteFront(Deque *d) {
	if(isEmpty(d)) fprintf(stderr, "DEQUE IS EMPTY!!!");
	return d->data[(++(d->front) + 1) % MAX_DEQUE_SIZE];
}

element deleteRear(Deque *d) {
	if(isEmpty(d)) fprintf(stderr, "DEQUE IS EMPTY!!!");
	return d->data[(--(d->rear) + 1 ) % MAX_DEQUE_SIZE];
}

int main(void) 
{
	Deque d;
	init(&d);
	
	addFront(&d, 1);
	printDeque(&d);
	addRear(&d, 2);
	printDeque(&d);
	addRear(&d, 3);
	printDeque(&d);
	addRear(&d, 4);
	printDeque(&d);
	addFront(&d, 0);
	printDeque(&d);
	deleteFront(&d);
	printDeque(&d);
	deleteRear(&d);
	printDeque(&d);
	addFront(&d, 0);
	printDeque(&d);
	
}
