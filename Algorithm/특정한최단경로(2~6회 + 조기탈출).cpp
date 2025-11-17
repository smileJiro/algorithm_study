#include <bits/stdc++.h>

using namespace std;
// 양방향 그래프가 주어진다.
// 다익스트라 2 ~ 6번 사용, 대신 중간 탈출하는 방식으로 최적화
constexpr int INF = 1e9;
using P = pair<int, int>; // cost, idx
int N, E;
int stop1, stop2;
int Dijkstra(vector<vector<P>>& graph, int s, int e)
{
	vector<int> dist(N + 1, INF);
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.emplace(0, s);
	dist[s] = 0;
	while (!pq.empty())
	{
		auto [cost, idx] = pq.top(); pq.pop();
		if (dist[idx] < cost)
			continue;

		if (idx == e)
			return cost;

		for (auto& [adjCost, adjIdx] : graph[idx])
		{
			if (dist[adjIdx] > dist[idx] + adjCost)
			{
				dist[adjIdx] = dist[idx] + adjCost;
				pq.emplace(dist[adjIdx], adjIdx);
			}
		}
	}

	return -1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> E;
	vector<vector<P>> graph(N + 1);
	for (int i = 0; i < E; ++i)
	{
		int s, e, c;
		cin >> s >> e >> c;
		graph[s].emplace_back(c, e);
		graph[e].emplace_back(c, s);
	}
	cin >> stop1 >> stop2;

	int minDist = INF;
	int value1, value2, value3;
	value1 = Dijkstra(graph, 1, stop1);
	if (value1 != -1)
	{
		value2 = Dijkstra(graph, stop1, stop2);
		if (value2 != -1)
		{
			value3 = Dijkstra(graph, stop2, N);
			if (value3 != -1)
			{
				minDist = min(minDist, value1 + value2 + value3);
			}
		}
	}

	value1 = Dijkstra(graph, 1, stop2);
	if (value1 != -1)
	{
		value2 = Dijkstra(graph, stop2, stop1);
		if (value2 != -1)
		{
			value3 = Dijkstra(graph, stop1, N);
			if (value3 != -1)
			{
				minDist = min(minDist, value1 + value2 + value3);
			}
		}
	}

	if (minDist == INF)
		cout << -1 << '\n';
	else
		cout << minDist << '\n';

	return 0;
}