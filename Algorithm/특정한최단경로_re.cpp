#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>; // cost, idx
constexpr int INF = 1e9;
#pragma region note
// 1. 무방향 그래프
// 2. 1초, N <= 800 -> 플로이드 아님
// 3. 갔던 길 다시 갈 수있음 + 임의의 두 정점을 반드시 통과해야한다. -> 다익스트라 두번 수행
#pragma endregion

int N, E;
void Dijkstra(const vector<vector<P>>& graph, vector<int>& dist, int start)
{
	dist[start] = 0;

	priority_queue<P, vector<P>, greater<P>> pq;
	pq.emplace(dist[start], start);

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
	cin >> N >> E;
	constexpr int start = 1;
	const int end = N;

	vector<vector<P>> graph(N + 1);
	
	int s, e, c;
	for (int i = 0; i < E; ++i)
	{
		cin >> s >> e >> c;
		graph[s].emplace_back(c, e);
		graph[e].emplace_back(c, s);
	}

	int T1, T2;
	cin >> T1 >> T2;

	vector<int> dist1(N + 1, INF);
	vector<int> dist2(N + 1, INF);
	Dijkstra(graph, dist1, T1);
	Dijkstra(graph, dist2, T2);
	int answer = INF;

	// start -> T1 -> T2 -> end
	if (dist1[start] != INF && dist1[T2] != INF && dist2[end] != INF)
	{
		answer = min(answer, dist1[start] + dist1[T2] + dist2[end]);
	}

	// start -> T2 -> T1 -> end
	if (dist2[start] != INF && dist2[T1] != INF && dist1[end] != INF)
	{
		answer = min(answer, dist2[start] + dist2[T1] + dist1[end]);
	}

	// result
	if (answer == INF)
		cout << -1 << '\n';
	else
		cout << answer << '\n';

	return 0;
}