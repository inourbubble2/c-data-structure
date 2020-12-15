#include <stdio.h>
#include <stack>

typedef int element;
typedef struct Node {
	element data;
	struct Node *left, *right;
} Node;

using namespace std;

stack<Node*> s;
	
void iterInorder(Node *root) {
	while(1) {
		for(; root; root = root->left) 
			s.push(root);
		root = s.top();
		s.pop();
		if(root == NULL) break;
		printf("[%d] ", root->data);		
		root = root->right;
	}
}

int main(void) {
	Node n4 = {5, NULL, NULL};
	Node n3 = {4, NULL, NULL};
	Node n2 = {3, NULL, NULL};
	Node n1 = {2, &n3, &n4};
	Node root = {1, &n1, &n2};
		
	printf("반복적 중위 순회 = ");
	iterInorder(&root);
	printf("\n");	
}
