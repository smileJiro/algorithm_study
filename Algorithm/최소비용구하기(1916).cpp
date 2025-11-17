#include <bits/stdc++.h>

using namespace std;
#define INF 1e9
int N, M;

using P = pair<int, int>; // cost, idx -> 우선순위 큐 정렬때문에 이게 편해
vector<P> graph[1001]; // 인접 리스트 풀이 + 우선순위 큐 사용 
int dist[1001];

int Dijkstra(int s, int e)
{
	priority_queue<P, vector<P>, greater<P>> q;
	q.emplace(0, s); // 시작 노드 추가.
	fill(dist, dist + 1001, INF);
	dist[s] = 0; // 시작 노드만 0
	while (!q.empty())
	{
		auto [cost, idx] = q.top(); q.pop();
		if (cost > dist[idx])
			continue;

		for (auto& [adjCost, adjIdx] : graph[idx])
		{
			if (dist[idx] + adjCost < dist[adjIdx])
			{
				dist[adjIdx] = dist[idx] + adjCost;
				q.emplace(dist[adjIdx], adjIdx);
			}

		}
	}

	return dist[e];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < M; ++i)
	{
		int s, e, c;
		cin >> s >> e >> c;
		graph[s].emplace_back(c, e);
	}

	int s, e;
	cin >> s >> e;
	cout << Dijkstra(s, e);
	return 0;
}