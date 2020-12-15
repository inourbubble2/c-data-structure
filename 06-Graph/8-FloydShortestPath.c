#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 10000000

typedef struct Graph {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
} Graph;

int A[MAX_VERTICES][MAX_VERTICES];

void printStatus(Graph *g)
{
	printf("================================\n");
	for(int i = 0; i < g->n; i++) {
		for(int j = 0; j < g->n; j++) {
			if(A[i][j] == INF)
				printf(" * ");
			else 
				printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("================================\n");
}

void floyd(Graph *g)
{
	for(int i = 0; i < g->n; i++) 
		for(int j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];
	printStatus(g);
	for(int k = 0; k < g->n; k++) {
		for(int i = 0; i < g->n; i++) 
			for(int j = 0; j < g->n; j++)
				if(A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
		printStatus(g);
	}
}

int main(void)
{
	Graph g = {
	7, 
	{{0, 29, INF, INF, INF, 10, INF},
	 {29, 0, 16, INF, INF, INF, 15},
	 {INF, 16, 0, 12, INF, INF, INF},
	 {INF, INF, 12, 0, 22, INF, 18},
	 {INF, INF, INF, 22, 0, 27, 25},
	 {10, INF, INF, INF, 27, 0, INF},
	 {INF, 15, INF, 18, 25, INF, 9}}
	};
	floyd(&g);
	return 0;
}
