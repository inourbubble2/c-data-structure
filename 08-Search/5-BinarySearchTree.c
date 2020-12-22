Node *search(Node *node, int key) {
	while(node != NULL) {
		if(key == node->key) return node;
		else if (key < node->key) node = node->left;
		else node = node->right;
	}
	return NULL;
}
