#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node *left, *right;
} Node;

//중위 순회
void inorder(Node *root) {
	if (root !=  NULL) {
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

//전위 순회
void preorder(Node *root)  {
	if (root != NULL) {
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

// 후위 순회
void postorder(Node *root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

int main(void) {
	Node n4 = {5, NULL, NULL};
	Node n3 = {4, NULL, NULL};
	Node n2 = {3, NULL, NULL};
	Node n1 = {2, &n3, &n4};
	Node root = {1, &n1, &n2};
		
	printf("중위 순회 = ");
	inorder(&root);
	printf("\n");
	printf("전위 순회 = ");
	preorder(&root);
	printf("\n");
	printf("후위 순회 = ");
	postorder(&root);
	printf("\n");
	return 0;
}
