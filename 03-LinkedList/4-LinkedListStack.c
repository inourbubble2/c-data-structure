#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node {
	element data;
	Node *link;
}Node;

typedef struct Stack {
	Node *top;
}Stack;

void init(Stack *s) {
	s->top = NULL;
}

int isEmpty(Stack *s) {
	return (s->top == NULL);
}

int isFull(Stack *s) {
	return 0;
}

void printStack(Stack *s) {
	Node *node = s->top;
	while(node != NULL) {
		printf("|%d|\n", node->data);
		node = node->link;
	}
	printf("\n");
}

void push(Stack *s, element data) {
	Node *node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->link = s->top;
	s->top = node;
}
 
element pop(Stack *s) {
	if(isEmpty(s)) fprintf(stderr, "STACK IS EMPTY!!!");
	Node *node = s->top;
	element temp = s->top->data;
	s->top = s->top->link;
	free(node);
	return temp;	
}

int main(void) {
	Stack *s = (Stack *) malloc(sizeof(Stack));
	init(s);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	printStack(s);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	return 0;
}
