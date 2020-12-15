#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
#define INF 1000

int parent[MAX_VERTICES];

void set_init(int n)
{
	for (int i = 0; i<n; i++)
		parent[i] = -1;
}

int set_find(int curr)
{
	if(parent[curr] == -1)
		return curr;
	while(parent[curr] != -1) curr = parent[curr];
	return curr;
}

void set_union(int a, int b)
{
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2) 
		parent[root1] = root2;
}

struct Edge {
	int start, end, weight;
};

typedef struct Graph {
	int n;
	struct Edge edges[2 * MAX_VERTICES];
} Graph;

void graph_init(Graph *g)
{
	g->n = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

void insertEdge(Graph *g, int start, int end, int w)
{
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}

int compare(const void *a, const void *b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}

void kruskal(Graph *g)
{
	int acceptedEdge = 0;	//현재까지 선택된 간선의 수 
	int uset, vset;			//정점 u와 정점 v의 집합 번호
	struct Edge e;
	
	set_init(g->n);
	qsort(g->edges, g->n, sizeof(struct Edge), compare);
	
	printf("Kruskal's Minimum Spanning Tree Algorithm\n");
	int i = 0;
	while(acceptedEdge < (g->n -1)) { //간선의 수 < n - 1 
		e = g->edges[i];
		uset = set_find(e.start);	//정점 u의 집합 번호  
		vset = set_find(e.end);		//정점 v의 집합 번호 
		if (uset != vset) {			//합집합이 아닐 시 
			printf("간선(%d, %d) %d 선택\n", e.start, e.end, e.weight);
			acceptedEdge++;
			set_union(uset, vset);
		}
		i++;
	}
}

int main(void)
{
	Graph *g = (Graph *) malloc(sizeof(Graph));
	graph_init(g);
	insertEdge(g, 0, 1, 29);
	insertEdge(g, 1, 2, 16);
	insertEdge(g, 2, 3, 12);
	insertEdge(g, 3, 4, 22);
	insertEdge(g, 4, 5, 27);
	insertEdge(g, 5, 0, 10);
	insertEdge(g, 6, 1, 15);
	insertEdge(g, 6, 3, 18);
	insertEdge(g, 6, 4, 25);
	kruskal(g);
	free(g);
	return 0;
}
