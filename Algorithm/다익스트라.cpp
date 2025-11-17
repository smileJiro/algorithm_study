#include <bits/stdc++.h>

using namespace std;

struct Node
{
public:
	Node() = delete;
	Node(int idx, int cost)
		: idx(idx)
		, cost(cost)
	{
	}
public:
	int idx = 0;
	int cost = 1;
};

void Dijkstra(const vector<vector<Node>>& graph, vector<int>& dist, int start)
{
	// 1. dist 초기화 -> 시작 노드만 0으로 바꿔주면 된다.
	dist[start] = 0;
	// 2. graph의 인접 리스트를 참조하여 dist 테이블을 갱신한다.
	// 3. 우선순위 큐를 사용하여 최단 경로 인덱스부터 탐색
	using P = pair<int, int>;
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.emplace(dist[start], start);
	while (!pq.empty())
	{
		P cur = pq.top(); pq.pop();
		if (cur.first > dist[cur.second])
			continue;

		for (const Node& adj : graph[cur.second])
		{
			// 해당 노드에 대한 최단 경로 테이블 갱신 후 푸쉬
			if(dist[adj.idx] > dist[cur.second] + adj.cost)
			{
				dist[adj.idx] = dist[cur.second] + adj.cost;
				pq.emplace(dist[adj.idx], adj.idx);
			}
			
		}
	}

}


int main()
{
	int n = 4;
	// 1. 그래프 
	vector<vector<Node>> graph(n);
	graph[0].emplace_back(1, 1);
	graph[0].emplace_back(2, 3);
	graph[0].emplace_back(3, 2);
	 
	graph[1].emplace_back(0, 1);
	graph[1].emplace_back(2, 1);
	graph[1].emplace_back(3, 3);

	graph[2].emplace_back(0, 3);
	graph[2].emplace_back(1, 1);
	graph[2].emplace_back(3, 1);

	graph[3].emplace_back(0, 2);
	graph[3].emplace_back(1, 3);
	graph[3].emplace_back(2, 1);

	// 2. 방문 노드 검사 -> INF 로 판단 가능하긴해
	// 3. 최단 경로 테이블
	constexpr int INF = 1e9;
	vector<int> dist(n, INF);

	Dijkstra(graph, dist, 2);


	return 0;
}