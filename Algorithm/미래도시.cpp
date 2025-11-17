#include <bits/stdc++.h>

using namespace std;

// 풀이 후 피드백 : 해당 문제는 bfs 두번으로 푸는 것이 성능적으론 좋음, 하지만 노드 개수가 100개 이하였으니,
// 플로이드 워셜 알고리즘으로 간단하게 풀이하는 것도 방법임. 다익스트라로 풀 이유가 없다고 생각은 했는데
// 그냥 다익스트라 공부중이라 그걸로 풀어버림. 

bool Dijkstra(const vector<vector<int>>& graph, int start, int target, int* outCost)
{
	constexpr int INF = 1e9;
	vector<int> dist(graph.size(), INF);
	dist[start] = 0;

	using P = pair<int, int>;
	priority_queue<P, vector<P>, greater<P>> pq;

	pq.emplace(0, start);
	while (!pq.empty())
	{
		P cur = pq.top(); pq.pop();
		int curDist = cur.first;
		int curIdx = cur.second;
		if (curDist > dist[curIdx])
			continue;

		if (target == curIdx)
		{
			*outCost += dist[curIdx];
			return true;
		}
		for (auto& adj : graph[curIdx])
		{
			if (dist[adj] > dist[curIdx] + 1)
			{
				dist[adj] = dist[curIdx] + 1;
				pq.emplace(dist[adj], adj);
			}
		}
	}

	return false;
}

int main()
{
	int n, m; // 노드수, 간선수
	cin >> n >> m;
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int x, k; // x회사, 소개팅
	cin >> x >> k;
	int cost = 0;
	if (!Dijkstra(graph, 1, k, &cost))
	{
		cout << -1 << '\n';
		return 0;
	}
	if (!Dijkstra(graph, k, x, &cost))
	{
		cout << -1 << '\n';
		return 0;
	}

	cout << cost << '\n';
	return 0;
}