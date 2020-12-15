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
 
//히프 정렬 알고리즘  
void heapSort(element a[], int n) 
{
	int i;
	Heap *h = create();
	init(h);
	for(i = 0; i < n; i++)
		insertMaxHeap(h, a[i]);
	for(i = (n-1); i >=0; i--) 
		a[i] = deleteMaxHeap(h);
	free(h);
}

#define SIZE 10
int main(void)
{
	element list[SIZE] = {4, 5, 1, 2, 3, 4, 99, 45, 13, 19};
	for(int i = 0; i < SIZE; i++) 
		printf("%d ", list[i].key);
	printf("\n");
	heapSort(list, SIZE);
	for(int i = 0; i < SIZE; i++) 
		printf("%d ", list[i].key);
	printf("\n");
	return 0;
}
