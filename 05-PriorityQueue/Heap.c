#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200
typedef struct {
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
b 
//초기화 함수 
void init(Heap *h) 
{
	h->heapSize = 0;
}

//삽입 함수 
void insertMaxHeap(Heap *h, element item) 
{
	int i;
	i = ++(h->heapSize);
	
	//트리를 거슬러 올라가면서 부모 노드와 비교
	while((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i/2];	
		i /= 2;	
	}
	h->heap[i] = item;	//삽입 
}

//삭제 함수 
element deleteMaxHeap(Heap *h) 
{
	int parent, child;
	element item, temp;
	item = h->heap[1];					//루트 노드 저장 
	temp = h->heap[(h->heapSize)--];	//마지막 노드 저장 
	parent = 1;
	child = 2;
	while(child <= h->heapSize) {
		//현재 노드의 자식노드 left, right 중 더 큰 자식노드를 찾는다. 
		if((child < h->heapSize) && (h->heap[child].key) < (h->heap[child + 1].key))
			child++;
		if(temp.key >= h->heap[child].key) //마지막 노드가 자식 노드보다 더 크다면 
			break;
		//한 단계 아래로 이동
		h->heap[parent] = h->heap[child]; //노드 교체 
		parent = child;	
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
 
int main(void) 
{
	element e1 = {14};
	element e2 = {20};
	element e3 = {6};
	element e4 = {40};
	element e5 = {80};
	Heap* heap = create();
	init(heap);
	insertMaxHeap(heap, e1);
	insertMaxHeap(heap, e2);
	insertMaxHeap(heap, e3);
	insertMaxHeap(heap, e4);
	insertMaxHeap(heap, e5);
	printf("%d ", deleteMaxHeap(heap).key);
	printf("%d ", deleteMaxHeap(heap).key);
	printf("%d ", deleteMaxHeap(heap).key);
	printf("%d ", deleteMaxHeap(heap).key);
	printf("%d ", deleteMaxHeap(heap).key);
	return 0;
}
