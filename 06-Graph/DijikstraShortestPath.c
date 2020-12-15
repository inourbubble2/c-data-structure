#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF 10000000 //무한대, 연결이 없는 경우

typedef struct Graph {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
};

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
	int min, minpos;
	min = INF;
	minpos = -1;
	for(int i = 0; i < n; i++) 
		if(distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void printStatus(Graph *g)
{
	static int step = 1;
	printf("STEP %d = ", step++);
	printf("distance : ");
	for(int i = 0; i < g->n; i++) {
		if(distance[i] == INF)
			printf(" * ");
		else 
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf(" found: ");
	for(int i = 0; i < g->n; i++) 
		printf("%2d ", found[i]);
	printf("\n\n");
}

void shortestPath(Graph *g, int start)
{
	for(int i = 0; i < g->n; i++) {
		distance[i] = g->weight[start][i];
		found[i] = false;
	}
	found[start] = true;
	distance[start] = 0;
	for(int i = 0; i < g->n-1; i++) {
		printStatus(g);
		int u = choose(distance, g->n, found);
		found[u] = true;
		for(int w = 0; w < g->n; w++) 
			if(!found[w])
				if(distance[u] + g->weight[u][w] < distance[w])
					distance[w] = distance[u] + g->weight[u][w];
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
	shortestPath(&g, 0);
	return 0;
}
