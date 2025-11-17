#include <bits/stdc++.h>
using namespace  std;
constexpr int INF = 1e9;
enum DIR { GOPARTY, GOHOME, LAST };
using P = pair<int, int>; // cost, idx
vector<P> graph[LAST][1001]; // 간선을 역방향으로 저장한 그래프도 하나 만들자.
int dist[LAST][1001]; // 그러면 x에서 다른 노드로 가는 최단경로, 다른 노드에서 x로 오는 최단경로를 각각 구할 수있다.
int N, M, X;
void Dijkstra(vector<P> graph[1001], int dist[1001], int start)
{
	fill(dist, dist + 1001, INF);
	dist[start] = 0;
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.emplace(0, X);

	while (!pq.empty())
	{
		auto [curDist, curIdx] = pq.top(); pq.pop();
		if (curDist > dist[curIdx])
			continue;

		for (auto& [adjCost, adjIdx] : graph[curIdx])
		{
			if (dist[adjIdx] > dist[curIdx] + adjCost)
			{
				dist[adjIdx] = dist[curIdx] + adjCost;
				pq.emplace(dist[adjIdx], adjIdx);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> X;

	for (int i = 0; i < M; ++i)
	{
		int s, e, c;
		cin >> s >> e >> c;
		graph[GOHOME][s].emplace_back(c, e); 
		graph[GOPARTY][e].emplace_back(c, s); 
	}

	Dijkstra(graph[GOHOME],dist[GOHOME], X); // X -> Home 
	Dijkstra(graph[GOPARTY], dist[GOPARTY], X); // Home -> X

	int answer = 0;
	for (int i = 1; i <= N; ++i)
		answer = max(answer, dist[GOHOME][i] + dist[GOPARTY][i]);

	cout << answer << '\n';
	return 0;
}