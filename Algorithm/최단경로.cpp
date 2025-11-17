#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9;
using P = pair<int, int>; // cost, idx
int V, E, K;

void Dijkstra(const vector<vector<P>>& graph, vector<int>& dist, int start)
{
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.emplace(0, start); // 최소 비용, 인덱스

	while (!pq.empty())
	{
		auto [curDist, curIdx] = pq.top(); pq.pop();
		if (curDist > dist[curIdx]) // 이미 다른 노드에 의해서 최단 경로가 새로 갱신된거임.
			continue; 
		for (auto& [adjCost, adjIdx] : graph[curIdx])
		{
			if (dist[adjIdx] > dist[curIdx] + adjCost)
			{
				// 최단 경로 갱신
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
	cin >> V >> E >> K;

	vector<vector<P>> graph(V + 1);
	vector<int> dist(V + 1, INF); // 시작 노드 기준 해당 노드로 가는 최소값
	dist[K] = 0;
	for (int i = 0; i < E; ++i)
	{
		int s, e, c;
		cin >> s >> e >> c;
		graph[s].emplace_back(c, e);
	}

	Dijkstra(graph, dist, K);

	for (int i = 1; i <= V; ++i)
	{
		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}

	return 0;
}