#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
	int length;
} ListNode;

void print_list(ListNode* head)
{
	ListNode* p;
	
	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p -> link;
	} while (p != head);
	printf("%d->\n", p->data); //Last node
} 

ListNode* insert_first(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
		head->length = 1;
	}
	else {
		node->link = head->link;
		head->link = node;
		head->length ++;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
		head->length = 1;
		//printf("insert_last, head==NULL %d\n", head->length);	
	}
	else {
		node->link = head->link;
		head->link = node;
		node->length = head->length;
		head = node;
		head->length ++;
		//printf("inser_last, head!=NULL %d\n", head->length);	
	}
	return head;
}

void get_length(ListNode* head)
{
	printf("\n%d\n", head->length);	
}

ListNode *search(ListNode *head, element data)
{
	ListNode* p;
	
	if (head == NULL) return NULL;
	p = head->link;
	do {
		if(p->data == data) 
			return p;
		p = p->link;
	} while (p != head);
	if(p->data == data) 
		return p;
	printf("found NULL");
	return NULL;
}

int main(void)
{
	ListNode *head = NULL;
	
	head = insert_last(head, 20);
	head = insert_first(head, 30);
	head = insert_last(head, 10);
	head = insert_first(head, 40);
	head = insert_first(head, 50);
	
	print_list(head);
	//get_length(head);
	
	printf("found %d", search(head, 22)->data);
	
	return 0;
}
