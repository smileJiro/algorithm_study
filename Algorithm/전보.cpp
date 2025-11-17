#include <bits/stdc++.h>

using namespace std;
using P = pair<int, int>;
void Dijkstra(const vector<vector<P>>& graph, vector<int>& dist, int start)
{
	dist[start] = 0;
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.emplace(0, start);
	while (!pq.empty())
	{
		P cur = pq.top(); pq.pop();
		int curDist = cur.first;
		int curIdx = cur.second;
		if (curDist > dist[curIdx])
			continue;

		for (P adj : graph[curIdx])
		{
			int adjCost = adj.first;
			int adjIdx = adj.second;
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
	int n, m, c;
	cin >> n >> m >> c;
	
	vector<vector<P>> graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].emplace_back(P(cost, end));
	}
	
	constexpr int INF = 1e9;
	vector<int> dist(n + 1, INF);
	Dijkstra(graph, dist, c);

	int cnt = 0;
	int maxDist = 0;
	for (int i = 0; i < n + 1; ++i)
	{
		if (dist[i] != INF)
		{
			++cnt;
			if (maxDist < dist[i])
				maxDist = dist[i];
		}
	}
	cout << cnt - 1 << ' ' << maxDist << '\n';
	return 0;
}