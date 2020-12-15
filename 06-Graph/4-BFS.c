// 인접 행렬 BFS
void bfsMat(Graph *g, int v)
{
	Queue q;
	init(&q);
	visited[v] = 1;
	printf("정점 %d ->", v);
	enqueue(&q, v);
	while(!isEmpty(&q)) {
		v = dequeue(&q);
		for(int w = 0; w<g->n; w++) 
			if(g->adjMat[v][w] && !visited[w]) {
				visited[w] = 1;
				printf("정점 %d ->", w);
				enqueue(&q, w);
			}			
	}
}

// 인접 리스트 BFS
void bfsList(Graph *g, int v)
{
	Queue q;
	init(&q);
	visited[v] = 1;
	printf("%d 방문 ->", v);
	enqueue(&q, v);
	while(!isEmpty(&q)) {
		v = dequeue(&q);
		for (Node *w = g->adjList[v]; w; w = w->link) 
			if(!visited[w->vertex]) {
				visited[w->vertex] = 1;
				printf("%d 방문 -> ", w->vertex);
				enqueue(&q, w->vertex);
			}
	}
}
