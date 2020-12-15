#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10

typedef int element;
typedef struct Stack {
	int top;
	element data[MAX_STACK_SIZE];
} Stack;

void init(Stack *s) {
	s->top = -1;
}

int isEmpty(Stack *s) {
	return (s->top == -1);
}

int isFull(Stack *s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(Stack *s, element data) {
	if(isFull(s)) fprintf(stderr, "STACK IS FULL!!!");
	s->data[++(s->top)] = data;
}

element pop(Stack *s) {
	if(isEmpty(s)) fprintf(stderr, "STACK IS EMPTY!!!\n");
	return s->data[s->top--];
}

element peek(Stack *s) {
	if(isEmpty(s)) fprintf(stderr, "STACK IS EMPTY!!!\n");
	return s->data[s->top];
}

int main(void) {
	Stack s;
	init(&s);
	
	push(&s, 10);
	push(&s, 11);
	push(&s, 12);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	return 0;
}
