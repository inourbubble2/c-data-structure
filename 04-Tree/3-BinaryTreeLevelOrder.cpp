#include <iostream>
#include <queue>

using namespace std; 

typedef int element;
typedef struct Node {
	int data;
	Node *left, *right;
}Node;

void levelOrder(Node *ptr) {
	Node *node;
	queue<Node *> q;
	q.push(ptr);
	while(!q.empty()) {
		node = q.front();
		q.pop();
		cout << "[" << node->data << "] ";
		if(node->left)
			q.push(node->left);
		if(node->right) 
			q.push(node->right);
	}
	
}

int main() {
	Node n4 = {5, NULL, NULL};
	Node n3 = {4, NULL, NULL};
	Node n2 = {3, NULL, NULL};
	Node n1 = {2, &n3, &n4};
	Node root = {1, &n1, &n2};
	
	cout << "레벨적 순회: " << endl;
	levelOrder(&root);
	return 0;
}
