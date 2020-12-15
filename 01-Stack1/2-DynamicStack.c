#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Stack {
	element *data;
	int capacity;
	int top;
} Stack;

void init(Stack *s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element *) malloc(s->capacity * sizeof(element));
}

int isEmpty(Stack *s) {
	return (s->top == -1);
}

int isFull(Stack *s) {
	return (s->top == s->capacity - 1);
}

void push(Stack *s, element item) {
	if(isFull(s)) {
		s->capacity *= 2;
		s->data = (element *) realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
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
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	
	return 0;
}
