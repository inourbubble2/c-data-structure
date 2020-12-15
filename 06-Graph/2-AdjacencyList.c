#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
typedef struct Node {
	int vertex;
	Node *link;
} Node;
typedef struct Graph {
	int n;
	Node *adjList[MAX_VERTICES];
} Graph;

void init(Graph *g)
{
	g->n = 0;
	for(int i = 0; i < MAX_VERTICES; i++) 
		g->adjList[i] = NULL;
}

void insertVertex(Graph *g)
{
	if(g->n+1 > MAX_VERTICES)
		fprintf(stderr, "정점 개수 초과");
	g->n++;
}

void insertEdge(Graph *g, int u, int v)
{
	if(u >= g->n || v >= g->n)
		fprintf(stderr, "정점 번호 오류");	
	Node *node = (Node *)malloc(sizeof(Node));
	node->vertex = v;
	node->link = g->adjList[u];
	g->adjList[u] = node;
}

void printGraph(Graph *g)
{
	Node *node;
	for(int r = 0; r < MAX_VERTICES; r++) {
		printf("정점 %d의 인접 리스트 : ", r);
		node = g->adjList[r];
		while(node) {
			printf("%d ", node->vertex);
			node = node->link;
		}
		printf("\n");
	}
}

int main(void)
{
	Graph g;
	init(&g);
	insertVertex(&g);
	insertVertex(&g);
	insertVertex(&g);
	insertVertex(&g);
	insertVertex(&g);
	insertEdge(&g, 0, 1);
	insertEdge(&g, 0, 2);
	insertEdge(&g, 0, 3);
	insertEdge(&g, 0, 4);
	insertEdge(&g, 2, 3);
	insertEdge(&g, 2, 4);
	insertEdge(&g, 3, 4);
	printGraph(&g);
}
