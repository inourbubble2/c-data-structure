#include <stdio.h>

typedef char element;
typedef struct Node {
	element data;
	struct Node *left, *right;
	int isThread;
} Node;

Node *findSuccessor(Node *p) {
	Node* q = p->right;
	
	//만약 오른쪽 포인터가 NULL이거나, p가 스레드면 오른쪽 포인터를 반환한다. 
	if(q == NULL || p->isThread == 1) 
		return q;
	
	//만약 오른쪽 자식이라면 가장 왼쪽 노드로 이동한다. 
	while(q->left != NULL) 
		q = q->left;
	return q;
}

void threadOrder(Node *t)  {
	Node *q;
	q = t;
	
	while(q->left) 
		q = q->left;				//가장 왼쪽 노드로 이동한다.
		
	do {
		printf("%c -> ", q->data);	//데이터 출력 
		q = findSuccessor(q);		//후속자 찾기 
	} while(q);						//NULL이 아닌 동안 
}

int main(void) {
	Node n1 = {'A', NULL, NULL, 1};
	Node n2 = {'B', NULL, NULL, 1};
	Node n3 = {'C', &n1, &n2, 0};
	Node n4 = {'D', NULL, NULL, 1};
	Node n5 = {'E', NULL, NULL, 0};
	Node n6 = {'F', &n4, &n5, 0};
	Node n7 = {'G', &n3, &n6, 0};
	Node *exp = &n7;
	
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;
	
	threadOrder(exp);
	return 0;
}
