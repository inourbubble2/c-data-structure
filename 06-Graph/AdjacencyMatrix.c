#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
typedef struct Graph {
	int n;
	int adjMat[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init(Graph *g)
{
	g->n = 0;
	for(int r = 0; r < MAX_VERTICES; r++)
		for(int c = 0; c < MAX_VERTICES; c++)
			g->adjMat[r][c] = 0;
}


void insertVertex(Graph *g)
{
	if(g->n+1 > MAX_VERTICES)
		fprintf(stderr, "정점 개수 초과");
	else 
		g->n++;
}

void insertEdge(Graph *g, int start, int end)
{
	if(start >= g->n || end >= g->n)
		fprintf(stderr, "정점 번호 오류");
	g->adjMat[start][end] = 1;
	g->adjMat[end][start] = 1;
		
}

void printGraph(Graph *g)
{
	for(int r = 0; r < MAX_VERTICES; r++) {
		for(int c = 0; c < MAX_VERTICES; c++) {
			printf("[%d] ", g->adjMat[r][c]);
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
	insertEdge(&g, 1, 3);
	insertEdge(&g, 3, 4);
	printGraph(&g);
	return 0;	
}
