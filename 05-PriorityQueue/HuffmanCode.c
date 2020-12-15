#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200
typedef struct Node{
	int weight;
	char ch;
	struct Node *left;
	struct Node *right;
} Node;
typedef struct {
	Node *ptree;
	char ch;
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heapSize;
} Heap;

//생성 함수 
Heap* create() 
{
	return (Heap *) malloc(sizeof(Heap));
}

//초기화 함수 
void init(Heap *h) 
{
	h->heapSize = 0;
}
//최소 힙 삽입 함수 
void insertMinHeap(Heap *h, element item) 
{
	int i;
	i = ++(h->heapSize);
	
	//트리를 거슬러 올라가면서 부모 노드와 비교
	while((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i/2];	
		i /= 2;	
	}
	h->heap[i] = item;	//삽입 
}

//최대 힙 삭제 함수 
element deleteMinHeap(Heap *h) 
{
	int parent, child;
	element item, temp;
	item = h->heap[1];					//루트 노드 저장 
	temp = h->heap[(h->heapSize)--];	//마지막 노드 저장 
	parent = 1;
	child = 2;
	while(child <= h->heapSize) {
		//현재 노드의 자식노드 left, right 중 더 작은 자식노드를 찾는다. 
		if((child < h->heapSize) && (h->heap[child].key) > (h->heap[child + 1].key))
			child++;
		if(temp.key < h->heap[child].key) //마지막 노드가 자식 노드보다 더작으면 
			break;
		//한 단계 아래로 이동
		h->heap[parent] = h->heap[child]; //노드 교체 
		parent = child;	
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

//이진 트리 생성 함수 
Node *makeTree(Node *left, Node *right)  
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->left = left;
	node->right = right;
	return node;
}

//이진 트리 제거 함수
void destroyTree(Node *root) 
{
	if(root == NULL) return;
	destroyTree(root->left);
	destroyTree(root->right);
	free(root);
}
 
//단말 노드 검사 함수 
int isLeaf(Node *root) 
{
	return !(root->left) && !(root->right);
}

//배열 출력 함수 
void printArray(int codes[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%d", codes[i]);
	printf("\n");
}

//코드 출력 함수
void printCodes(Node *root, int codes[], int top) 
{
	if(root->left) {
		codes[top] = 1;
		printCodes(root->left, codes, top + 1);
	}
	if(root->right) {
		codes[top] = 0;
		printCodes(root->right, codes, top + 1);		
	}
	if(isLeaf(root)) {
		printf("%c: ", root->ch);
		printArray(codes, top);
	}
}

void huffmanTree(int freq[], char chList[], int n)
{
	int i;
	Node *node, *x;
	Heap *heap;
	element e, e1, e2;
	int codes[100];
	int top = 0;
	heap = create();
	init(heap);
	
	for(i = 0; i < n; i++) {
		node = makeTree(NULL, NULL);
		e.ch = node->ch = chList[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		insertMinHeap(heap, e);
	}
	for(i = 1; i < n; i++) {
		e1 = deleteMinHeap(heap);
		e2 = deleteMinHeap(heap);
		x = makeTree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		printf("%d+%d=%d \n", e1.key, e2.key, e.key);
		insertMinHeap(heap, e);
	}
	e = deleteMinHeap(heap);		//최종 트리  
	printCodes(e.ptree, codes, top);
	destroyTree(e.ptree);
	free(heap);
}

int main(void) 
{
	char chList[] = {'a', 'b', 'c', 'd', 'e'};
	int freq[] = {4, 6, 8, 12, 15};
	huffmanTree(freq, chList, 5);
	return 0;
}
