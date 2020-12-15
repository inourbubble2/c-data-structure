#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	Node *prev;
	Node *next;
} Node;

void init(Node *head) {
	head->prev = head;
	head->next = head;
}

void printList(Node *head) {
	Node *node;
	for(node = head->next; node != head; node = node->next) {
		printf(" <-%d-> ", node->data);
	}
	printf("\n");
}

//노드 prev 뒤에 새로운 노드를 생성해서 데이터를 삽입 
Node* insert(Node *prev, element data) {
	Node *node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->prev = prev;
	node->next = prev->next;
	prev->next->prev = node;
	prev->next = node;
	return node;
}

//특정 데이터를 찾아서 삭제 
void deleteByData(Node *head, element data) {
	Node *node;
	for(node = head->next; node != head; node = node->next) {
		if(node->data == data) {
			break;
		}
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
}

//삭제할 노드와 삭제할 노드의 왼쪽 링크를 매개변수로 줘서 삭제 
void deleteByNode(Node *head, Node *removed) {
	if(removed == head) return;
	removed->prev->next = removed->next;
	removed->next->prev = removed->prev;
	free(removed);
}

int main(void) {
	Node *head = (Node *) malloc(sizeof(Node));
	init(head);
	
	Node *node;
	node = insert(head, 1);
	node = insert(node, 3);
	node = insert(node, 5);
	printList(head);
	
	deleteByNode(head, node);
	printList(head);
	
	deleteByData(head, 3);
	printList(head);
	
	return 0;
}
