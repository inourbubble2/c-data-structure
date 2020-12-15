#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int key;
	struct Node *left, *right;
} Node;

//탐색 연산을 수행한다. 
Node *search(Node *node, int key) {
	while(node != NULL) {
		if(key == node->key) return node;
		else if (key < node->key) node = node->left;
		else node = node->right;
	}
	return NULL;
}

//새로운 노드를 만든다. 
Node *newNode(int key) {
	Node *node = (Node *)malloc(sizeof(node));
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

//주어진 노드 아래에서 최소 키값을 가지는 노드를 반환한다. 
Node *minValueNode(Node *node) {
	Node *current = node;
	while(current->left != NULL) {
		current = current->left;
	}
	return current;
}

//노드를 삽입한다. 
Node *insertNode(Node *node, int key) {
	if(node == NULL) return newNode(key);
	
	if(key < node->key)
		node->left = insertNode(node->left, key);
	else if(key > node->key)
		node->right = insertNode(node->right, key);
		
	return node;
}

//노드를 삭제한다. 
Node *deleteNode(Node *root, int key) {
	if(root == NULL) return root;
	if(key < root->key) root->left = deleteNode(root->left, key);
	else if(key > root->key) root->right = deleteNode(root->right, key);
	else { //key == root->key
		//If a node that will be deleted has 0 or 1 sub tree
		if(root->left == NULL) {
			Node *temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			Node *temp = root->left;
			free(root);
			return temp;
		} 
		//If a node that will be deleted has both sub tree
		Node *temp = minValueNode(root->right); //오른쪽 서브트리에서 가장 작은 값을 가진 노드 찾기
		root->key = temp->key;	//후계 노드를 복사 후  
		root->right = deleteNode(root->right, temp->key);	//후계 노드를 삭제한다 
	}
	return root;
}

//중위 순회
void inorder(Node *root) {
	if (root !=  NULL) {
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

int main(void) {
	Node *root = NULL;
	root = insertNode(root, 30);
	root = insertNode(root, 20);
	root = insertNode(root, 10);
	root = insertNode(root, 50);
	root = insertNode(root, 40);
	root = insertNode(root, 60);
	
	printf("이진 탐색 트리 중위 순회 : ");
	inorder(root);
	printf("\n");
	
	deleteNode(root, 30);
	printf("30 삭제 후 ");
	printf("이진 탐색 트리 중위 순회 : ");
	inorder(root);
	printf("\n");
	
	if(search(root, 30) != NULL) 
		printf("Founded 30 in binary search tree\n");
	else 
		printf("Coudn't find 30 in binary search tree\n");
	
}
