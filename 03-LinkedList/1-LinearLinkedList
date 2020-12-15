#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, int value)
{
	ListNode *p = (ListNode *) malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *) malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete_(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL; p = p->link) {
		printf("%d -> ", p->data);
	}
	printf("NULL \n");
}

element get_entry(ListNode *head, int index) 
{
	ListNode *p = head;
	for(int i = 0; i < index; i++) 
		p = p->link;
	return p->data;
}

int main(void)
{
	ListNode *head = NULL;
	
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	printf("%d번째의 값= %d \n", 2, get_entry(head, 2));
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	
	return 0;
}
