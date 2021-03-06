# Graph
> Q. 그래프에 대해서 정의하시오.
> > A. 그래프는 객체 사이의 연결 관계에 대해서 정의하는 자료구조입니다. 그리고 정점(vertex)와 간선(edge) 사이의 유한한 집합이라고도 정의할 수 있습니다.


## Adjacency Matrix
https://github.com/inourbubble2/c-data-structure/blob/main/06-Graph/1-AdjacencyMatrix.c

## Adjacency List
https://github.com/inourbubble2/c-data-structure/blob/main/06-Graph/2-AdjacencyList.c
> Q. 인접행렬로 그래프를 정의할 때와 인접리스트로 그래프를 정의할 때의 차이점을 설명하시오.
> > A. 우선 인접행렬은 그래프에 간선이 많이 존재하는 밀집 그래프를 표현할 때 적합합니다. 또한 두 정점을 연결하는 간선의 존재 여부를 O(1) 시간만에 알 수 있다는 장점이 있으나, 희소 그래프를 표현할 때는 메모리의 낭비가 심하다는 단점이 있습니다. 인접 리스트는 희소 그래프를 표현할 때 유리합니다. 왜냐하면 인접리스트로 무방향 그래프를 표현할 때 정점의 수 만큼 연결리스트와 헤더 노드가 필요하고, 2*간선의수 만큼의 노드가 필요하기 때문입니다. 


## DFS
https://github.com/inourbubble2/c-data-structure/blob/main/06-Graph/3-DFS.c
> Q. DFS란 무엇인지 정의하시오.
> > A. DFS는 Depth First Search의 약자로, 한 노드에 인접한 모든 노드를 방문한 뒤에 다른 노드를 방문하는 알고리즘입니다. DFS는 순환 호출을 이용하거나 명시적인 스택을 사용합니다. DFS는 그래프가 인접 리스트로 표현되어 있을 시 전체 수행 시간이 O(n + e)이며, 인접 행렬로 표현되어 있을 시 O(n^2)의 시간이 걸립니다.

> Q. DFS에 구현 방법에 대해서 설명하시오.
> > A. DFS는 명시적인 스택을 사용하거나 재귀 호출을 이용해서 구현할 수 있습니다. 먼저 시작 정점 v에서 출발하여 시작 정점을 방문 표시하고, 시작 정점에 인접한 정점들 중 아직 방문하지 않은 정점 u를 선택합니다. u가 있다면 u를 시작정점으로 하여 깊이 우선 탐색을 다시 시작합니다. 이 과정을 반복하고 만약 방문하지 않은 정점이 없다면 탐색을 종료합니다.


## BFS 
https://github.com/inourbubble2/c-data-structure/blob/main/06-Graph/4-BFS.c
> Q. BFS란 무엇인지 정의하시오.
> > A. BFS는 Breadth First Search의 약자로, 깊이 우선 탐색입니다. BFS는 시작 정점으로부터 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 순회 방법이며, 큐를 사용합니다. BFS의 시간 복잡도도 DFS와 같이 희소 그래프를 사용할 경우 인접리스트를 사용하는 것이 효율적입니다.

> Q. BFS의 구현 방법에 대해서 설명하시오.
> > A. BFS는 가까운 거리에 있는 정점을 차례로 저장한 후 꺼낼 수 있는 자료형인 큐를 사용합니다. 먼저 시작 정점을 큐에 넣은 뒤 반복문을 실행하여 큐에서 정점을 꺼내 정점을 방문하고 인접한 정점들을 큐에 추가합니다. 그리고 이 과정을 큐가 소진될 때까지 반복합니다.


# MST (최소 비용 신장 트리)
> Q. 최소비용신장트리에 대해서 설명하시오.
> > A. 최소비용신장트리는 신장 트리 중에서 사용된 간선들의 가중치 합이 최소인 신장 트리를 말합니다. 신장 트리는 깊이 우선이나 너비 우선 탐색 도중에 사용된 간선만 모으면 만들 수 있습니다. 신장 트리는 통신 네트워크 구축에 많이 사용됩니다. MST를 구하는 방법으로는 크루스칼과 프림의 알고리즘이 대표적인데 위 두 알고리즘은 최소비용신장트리가 간선의 가중치 합이 최소이고, 반드시 n-1개의 간선만 사용해야 하고, 사이클이 포함돼서는 안 된다는 조건들을 적절히 이용합니다.


## Kruskal's MST
https://github.com/inourbubble2/c-data-structure/blob/main/06-Graph/5-KruskalMST.c
> Q. 크루스칼의 MST 알고리즘에 대해 설명하시오.
> > A. 크루스칼의 알고리즘은 그리드 알고리즘 중 하나입니다. 최소비용신장트리가 최소 비용으로 구성됨과 동시에 사이클을 포함하지 않는다는 조건에 근거하여, 각 단계에서 사이클을 이루지 않는 최소 비용 간선을 선택합니다. 이러한 과정으로 모든 정점을 최소 비용으로 연결하는 최적 해답을 구할 수 있습니다.

> Q. 크루스칼 MST 알고리즘의 시간 복잡도는 어떻게 됩니까?
> > A. union-find 알고리즘을 사용하면 시간 복잡도는 간선들을 정렬하는 시간에 좌우됩니다. 따라서 효율적인 정렬 알고리즘을 사용 시, 복잡도는 (|e|log^2|e|)입니다.

> Q. 크루스칼 알고리즘의 구현 방법에 대해서 설명하시오.
> > A. 먼저 간선들을 오름차순으로 정렬합니다. 가장 가중치가 낮은 간선을 먼저 선택하고, 그 다음에도 가중치가 낮은 간선이면서 사이클을 생성하지 않는 간선들을 선택합니다. 그렇게 선택된 간선이 n-1개가 될 때 알고리즘을 수행합니다. 선택할 간선이 사이클이 있는지 없는지를 판단하기 위해서 union-find 알고리즘을 사용합니다. union-find 알고리즘은 추가하고자 하는 간선의 양끝 정점이 같은 집합에 속해있는지를 검사하는 알고리즘입니다. union-find 알고리즘에서 union(x, y) 연산은 x와 y가 속해있는 집합을 입력받아 2개의 집합을 합집합으로 만드는 연산이고, find(x) 연산은 x가 속해있는 집합을 찾는 연산입니다.

> Q. Prim의 알고리즘과 비교하시오.
> > A. Kruskal의 알고리즘은 그래프 내 적은 숫자의 간선을 가지는 희소그래프에 사용될 때 적합하고, Prim은 밀집 그래프를 표현할 때 적합합니다. 그리고 Kruskal의 알고리즘은 간선을 기반으로 하는 알고리즘이고 Prim의 알고리즘은 정점을 기반으로 하는 알고리즘입니다. 또한 Kruskal의 알고리즘은 이전 단계에서 만들어진 신장 트리와 관계 없이 무조건 최저 간선만을 선택하는데, Prim은 이전 단계에서 만들어진 신장 트리를 확장하는 방법입니다.


## Prim's MST
https://github.com/inourbubble2/c-data-structure/blob/main/06-Graph/6-PrimMST.c
> Q. 프림의 MST 알고리즘에 대해서 설명하시오.
> > A. 프림의 알고리즘은 시작 정점에서부터 인접한 정점 중 가중치가 가장 작은 간선을 선택하여 최소비용신장트리를 만드는 알고리즘입니다.

> Q. 프림의 MST 알고리즘의 구현에 대해서 설명하시오.
> > A. 먼저 신장 트리 정점 집합에서 각 정점까지의 거리를 가지고 있는 배열 distance가 필요합니다. 처음엔 시작 노드만 값이 0이고, 나머지 노드는 전부 무한대의 값을 가집니다. 그리고 정점들이 트리 집합에 추가되면서 distance의 값이 변경됩니다. 이제 우선 순위 큐가 필요합니다. 우선순위큐에 모든 정점을 삽입하고 while 루프로 가장 작은 distance 값을 가지는 정점을 끄집어냅니다. 이 정점이 트리 집합에 추가됩니다. 이 다음 새로운 정점 u에 인접한 정점 v들의 distance 값을 변경시켜주는데, 기존 distance[v]의 값보다 간선(u, v)의 값이 더 적으면 간선(u, v) 값으로 변경시켜줍니다. 

> Q. 프림의 MST 알고리즘의 시간복잡도에 대해서 설명하시오.
> > A. 프림의 알고리즘은 주 반복문이 n번, 내부 반복문이 n번 반복되므로 O(n^2)의 시간복잡도를 가지고 있습니다.


## Dijikstra's Shortest Path Algorithm
https://github.com/inourbubble2/c-data-structure/blob/main/06-Graph/7-DijikstraShortestPath.c
> Q. Dijikstra의 최단 경로 알고리즘에 대해 설명하시오.
> > A. 해당 최단경로 알고리즘은 한 정점에서부터 다른 정점들로 가는 최단경로를 구하는 알고리즘입니다. 주 반복문을 n번 반복하고, 내부 반복문을 2n번 반복하기에 O(n^2)의 복잡도를 가집니다.

> Q. Dijikstra 알고리즘의 구현 방법에 대해서 설명하시오.
> > A. Dijkstra 알고리즘에서 최단 경로는 경로의 길이 순으로 구해집니다. 먼저 집합 S를 시작 정점 v로부터의 최단 경로가 이미 발견된 정점들의 집합이라고 가정합니다. 그리고 시작 정점에서 집합 S에 있는 정점만을 거쳐서 다른 정점으로 가는 최단거리를 기록하는 배열 distance가  있어야 합니다. 알고리즘의 각 단계에서 S안에 있지 않은 정점 중 가장 distance 값이 작은 정점을 S에 추가합니다. 그리고 새로운 정점 u가 S에 추가되면, S에 있지 않은 다른 정점들의 distance값을 수정합니다. 새로 추가된 정점 u를 거쳐서 가는 거리와 기존의 거리를 비교하여 더 작은 거리로 distance를 갱신합니다. 즉 distance[w] = min(distance[w], distance[u]+weight[u][w])와 같은 수식을 사용합니다.

> Q. Dijikstra의 알고리즘의 효율을 개선하는 방법에 대해서 말하시오.
> > A. 효율성을 높이기 위해서는 최소값을 선택해서 그 위치를 반환하는 choose 함수를 우선순위 큐로 대치하여 속도를 높이는 방법이 있습니다. 우선순위 큐를 쓰면 단지 pop으로 최소값을 빼내면 되는 것이므로, choose 함수 내의 for문이 필요가 없어지기 때문이다. 그만큼 속도 향상을 기대할 수 있습니다.


## Floyd's Shortest Path Algorithm
https://github.com/inourbubble2/c-data-structure/blob/main/06-Graph/8-FloydShortestPath.c
> Q. Floyd의 최단 경로 알고리즘에 대해서 설명하시오.
> > A. 그래프에 있는 모든 정점 사이의 최단 경로를 구하려면 Dijkstra의 알고리즘을 반복 실행해도 되지만, 모든 정점 사이의 최단 거리를 구하려면 Floyd의 알고리즘이 더 간단하고 좋습니다. Floyd 알고리즘은 그래프에 존재하는 모든 정점 사이의 최단 경로를 구하는 알고리즘입니다. Floyd 최단 경로 알고리즘은 2차원 배열 A를 이용하여 3중 반복을 하는 루프로 아주 간단합니다. Floyd의 알고리즘은 O(n^3)의 복잡도를 가지고 있습니다.

> Q. Floyd 최단 경로 알고리즘의 구현 방법에 대해서 설명하시오.
> > A. Floyd 알고리즘은 2차원 배열 A를 이용하여 3중 반복을 하는 루프로 구성되어 있습니다. A[i][j]에 정점 i, j 사이 간선의 가중치가 기록이 되어있을 때, A[i][j]와 A[i][k] + A[k][j] 중 더 적은 값이 A[i][j]가 됩니다. 이 말은 정점 k를 경유하는 것이 보다 좋은 경로이면 A[i][j]의 값이 변경되고, 그렇지 않으면 이전 값을 유지한다는 의미입니다. 


## Topological Sortion
https://github.com/inourbubble2/c-data-structure/blob/main/06-Graph/9-TopologicalSort.c
> Q. 위상 정렬이란 무엇입니까?
> > A. 위상 정렬은 어떤 일을 하는 순서를 찾는 알고리즘입니다. 즉, 방향 그래프에 존재하는 정점들을 순서를 위배하지 않는 한에서 나열하는 것입니다. 먼저 집입 차수가 0인 정점을 선택하고, 선택된 정점과 여기에 부착된 모든 간선을 삭제합니다. 그리고 이와 같은 진입 차수 0의 정점의 선택과 삭제 과정을 반복하여 모든 정점이 선택*삭제되면 알고리즘이 종료됩니다. 이 과정에서 선택되는 정점의 순서를 위상 순서라고 합니다. 

> Q. 위상 정렬 구현 방법에 대해서 설명하시오.
> > A. 먼저 in_degree라는 1차원 배열을 만들고 이 배열에 각 정점의 진입 차수를 기록합니다. 그리고 in_degree에서 진입 차수가 0인 정점을 그래프에서 제거합니다. 제거한 후 그 정점에 인접한 정점의 in_degree[i]를 1만큼 감소시킵니다. 여기서 삭제할 후보 정점들을 저장해야하는데 스택이나 큐를 사용할 수 있습니다. 주 반복문을 돌기 전 스택에 진입차수가 0인 정점들을 넣습니다. 주 반복문에서는 스택에서 정점을 꺼내고(선택) 그 정점과 인접한 정점들의 진입차수를 감소(삭제)시킵니다. 이러면서 만약 인접한 정점의 진입차수가 0이 된다면 이 정점 또한 스택에 넣습니다. 이러한 과정을 반복하고 선택된 정점들을 나열합니다.
