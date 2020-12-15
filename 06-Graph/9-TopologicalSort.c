#include <stdio.h> 
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode; 

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

//그래프 초기화
void init(GraphType* g) 
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

//정점 삽입 연산
void insert_vertex(GraphType* g, int v) 
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "정점 개수 초과");
		return;
	}
	g->n++;
}

//간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "정점 번호 오류");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;	
}

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef struct stack {
	int arr[MAX_STACK_SIZE];
	int top;
} stack;

void init(stack *s) {
	s->top = -1;
}
int is_empty(stack *s) {
	if(s->top == -1) {
		return 1;
	} else {
		return 0;
	}
}

int is_full(stack *s) {
	if(s->top == MAX_STACK_SIZE -1) {
		return 1;
	} else {
		return 0;
	}
}

void push(stack *s, int item) {
	if(is_full(s)) return;
	s->arr[++(s->top)] = item;
}

int pop(stack *s) {
	if(is_empty(s)) return 0;
	return s->arr[(s->top)--];
}

int topoSort(GraphType *g)
{
	int i;
	stack s;
	GraphNode *node;
	
	int *in_degree = (int *)malloc(g->n * sizeof(int));
	for(i = 0; i < g->n; i++) 
		in_degree[i] = 0;
	for(i = 0; i < g->n; i++) {
		GraphNode *node = g->adj_list[i]; //정점 i에서 나오는 간선들
		while(node != NULL)  {
			in_degree[node->vertex]++;
			node = node->link;
		}
	}
	
	init(&s);
	for(i = 0; i < g->n; i++) 
		if(in_degree[i] == 0) push(&s, i);
	
	//위상 순서를 생성
	while(!is_empty(&s)) {
		int w = pop(&s);
		printf("정점 %d -> ", w);	//정점 출력 
		node = g->adj_list[w];		//각 정점의 진입 차수를 변경 
		while(node) {
			int u = node->vertex;
			in_degree[u]--;
			if(in_degree[u] == 0) push(&s, u);
			node = node->link;
		}
	}
	
	free(in_degree);
	printf("\n");
	return (i == g->n);	//반환 값이 1이면 성공, 0이면 실패
}

int main(void)
{
	GraphType g;
	init(&g);
	insert_vertex(&g, 0);
	insert_vertex(&g, 1);
	insert_vertex(&g, 2);
	insert_vertex(&g, 3);
	insert_vertex(&g, 4);
	insert_vertex(&g, 5);
	
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);
	
	insert_edge(&g, 1, 3);
	insert_edge(&g, 1, 4);
	
	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 5);
	
	insert_edge(&g, 3, 5);
	
	insert_edge(&g, 4, 5);
	
	topoSort(&g);
	
	return 0;
}
