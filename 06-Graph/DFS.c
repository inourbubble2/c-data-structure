// 인접 행렬 DFS
void dfsMat(Graph *g, int v) 
{
	visited[v] = 1;
	printf("정점 %d -> ", v);
	for(int w = 0; w < g->n; w++) {
		if(g->adjMat[v][w] && !visited[w]) 
			dfsMat(g, w);
	}
}

// 인접 리스트 DFS
void dfsList(Graph *g, int v)
{
	Node *w;
	visited[v] = 1;
	printf("정점 %d -> ", v);
	for(w = g->adjList[v]; w; w = w->link) {
		if(!visited[w->vertex]) 
			dfsList(g, w->vertex);
	}
}

