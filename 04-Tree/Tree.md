# Tree
> Q. 트리에 대해서 정의하시오.
> > A. 트리는 계층적인 자료를 표현하는데 적합한 비선형 자료구조입니다.

> Q. 트리의 용어인 루트노드, 단말노드, 비단말노드, 간선, 차수, 레벨, 높이, 포레스트를 정의하시오.
> > A. 루트노드는 트리에서 최상위에 있는 노드입니다. 단말노드는, 트리의 가장 마지막에 있는 노드이며 자식이 없습니다. 비단말노드는 단말노드의 반대로서 자식이 있는 노드들입니다. 간선이란 노드와 노드사이를 연결하는 선을 의미합니다. 차수는 각 노드의 자식 수를 의미합니다. 레벨은 트리의 각층에 번호를 매기는 것입니다. 높이는 트리가 가지고 있는 최대 레벨을 의미합니다. 그리고 포레스트는 트리의 집합을 의미합니다.

## Binary Tree
> Q. 이진트리의 성질을 나열하시오.
> > 1. n개의 노드를 가진 이진트리는 n-1개의 간선을 가집니다. 왜냐하면 이진트리에서 루트를 제외하면 하나의 부모노드를 가지기 때문에, n-1개만의 간선을 가집니다. 
> > 2. 높이가 h인 이진트리는 최소 h개의 노드를 가지며 최대 2^h -1 개의 노드를 가집니다. 
> > 3. n개의 노드를 가지는 이진트리의 높이는 최대 n이거나 최소 log^2(n+1)이 됩니다. 왜냐하면 레벨 당 최소 하나의 노드가 있어야 하기 때문입니다. 결론적으로 이진트리의 최대 노드 수는 n<=2^k-1인데 이 식의 양변에 log를 취하면 h >= log^2(n+1)이 됩니다. 

> Q. 포화이진트리와 완전이진트리의 차이점은?
> > A. 포화이진트리는 트리의 각 레벨에 노드가 꽉 차있는 이진트리로, 2^h-1개의 노드를 가집니다. 반면 완전이진트리는 레벨 1부터 레벨 h-1까지는 노드가 완전히 채워져있지만 마지막 레벨에서는 노드가 꽉 차있지 않아도 됩니다. 다만 왼쪽에서 오른쪽으로 빈곳이 없어야만 합니다. 고로 완전이진트리 안에 포화이진트리가 속해있다고 할 수 있습니다.

> Q. 트리를 배열로 표현할 때와 포인터로 표현할 때의 장단점을 나열하시오. 
> > A. 배열을 사용하는 편이 연산이 더 간단하지만, 노드가 비어있는 곳도 메모리를 할당해야하기 때문에 기억공간의 낭비가 심해집니다. 반면 포인터를 통해 표현할 시에는 연산은 더 복잡하지만 기억공간이 효율적으로 사용되고 루트 노드만 있으면 해당 트리의 모든 노드에 접근할 수 있다는 장점이 있습니다.

### Struct for Binary Tree Node
<pre><code> typedef struct Node {
	int data;
	struct Node *left, *right;
} Node;
</code></pre>

## Order of Binary Tree
https://github.com/inourbubble2/c-data-structure/blob/main/04-Tree/1-BinaryTreeOrder.c

## Iteration Order of Binary Tree
https://github.com/inourbubble2/c-data-structure/blob/main/04-Tree/2-BinaryTreeIterOrder.cpp
> Q. 이진트리를 반복적 순회할 수 있습니까?
> > A. 가능합니다. 다만 명시적인 스택이 필요합니다.

## Level Order of Binary Tree
https://github.com/inourbubble2/c-data-structure/blob/main/04-Tree/3-BinaryTreeLevelOrder.cpp
> Q. 레벨적 순회를 할 때는 무슨 자료구조가 필요합니까?
> > A. 일반적인 순회에서는 스택을 사용하거나 재귀 호출로 시스템 스택을 이용하지만 레벨적 순회를 할 때는 큐가 필요합니다.


## Other Operation for Binary Tree
### 이진 트리에서 노드의 개수를 구하는 연산
<pre><code>int getNodeCount(Node *node) {
	int count = 0;
	if (node != NULL) 
		count = 1 + getNodeCount(node->left) + getNodeCount(node->right);
		
	return count;
}</code></pre>

### 이진 트리에서 단말 노드의 개수를 구하는 연산
<pre><code>int getLeafCount(Node *node) {
	int count = 0;
	if(node != NULL) {
		if(node->left == NULL && node->right == NULL) 
			return 1;
		else 
			count = getLeafCount(node->left) + getLeafCount(node->right);
	}
	
	return count;
}</pre></code>

## Thread Binary Tree
https://github.com/inourbubble2/c-data-structure/blob/main/04-Tree/4-ThreadBinaryTree.c
> Q. 스레드 이진 트리의 정의와 장단점은 무엇입니까?
> > A. 이진 트리는 노드에 많은 NULL링크를 가지고 있습니다. 스레드 이진트리는 이들 NULL 링크에 선행자나 후속자를 저장시켜 놓은 트리가 스레드 이진 트리입니다. 스레드 이진 트리는 스택과 재귀 순회 없이 중위 순회를 빠르게 할 수 있는 장점이 있으나, 스레드를 설정하기 위해 삽입이나 삭제 연산을 구현하는 게 더 오래 걸립니다.

## Binary Search Tree
https://github.com/inourbubble2/c-data-structure/blob/main/04-Tree/5-BinarySearchTree.c
> Q. 이진탐색트리에서의 삽입, 삭제 연산 방법을 설명하시오.
> > 1. 이진탐색트리에서 새로운 데이터를 삽입하기 위해서는 그 데이터가 있는지 먼저 탐색을 합니다. 데이터가 중복되지 않으면 탐색을 실패하게 되는데 그 위치에 데이터를 삽입합니다. 
> > 2. 이진탐색트리에서 삭제 연산을 하기 위해서는 3가지 경우를 고려해야 합니다. 먼저 삭제하려는 노드가 단말노드인 경우, 하나의 서브트리만 가지고 있는 경우, 두 개의 서브트리를 모두 가지고 있는 경우를 살펴보아야합니다. 단말노드를 삭제할 때는 부모 노드를 찾아서 부모 노드의 링크 필드를 NULL로 만들어서 연결을 끊어주면 됩니다. 그리고 메모리 반납을 합니다. 삭제하려는 노드가 하나의 서브트리를 가지고 있는 경우도 간단한데 메모리 반납을 한 뒤에 삭제하려는 노드의 부모 노드의 링크가 자식 노드를 가르키게끔 수정하면 됩니다. 두 개의 서브 트리를 가지고 있는 경우, 삭제하려는 노드의 왼쪽 서브트리에서 가장 오른쪽의 값(가장 큰 값)이나 오른쪽 서브트리에 있는 값 중 가장 작은 값을 가지고 있는 노드와 키값을 교환하고, 아래의 노드를 삭제하면 됩니다.
