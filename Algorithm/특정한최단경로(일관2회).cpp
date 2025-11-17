#include <bits/stdc++.h>

using namespace std;
// 양방향 그래프가 주어진다.
// 다익스트라 3번 사용 
// 3 * O((V + E) log V
constexpr int INF = 1e9;
using P = pair<int, int>; // cost, idx
int N, E;
int stop1, stop2;
void Dijkstra(vector<vector<P>>& graph, vector<int>& dist, int s)
{
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.emplace(0, s);
	dist[s] = 0;
	while (!pq.empty())
	{
		auto [cost, idx] = pq.top(); pq.pop();
		if (dist[idx] < cost)
			continue;

		//if (idx == e)
		//	return cost;

		for (auto& [adjCost, adjIdx] : graph[idx])
		{
			if (dist[adjIdx] > dist[idx] + adjCost)
			{
				dist[adjIdx] = dist[idx] + adjCost;
				pq.emplace(dist[adjIdx], adjIdx);
			}
		}
	}

	//return -1;
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

	// 1을 시작으로 2까지의 최단경로 구하는 다익스트라 1회 수행(최적화 타겟 숫자 최단 거리 정해지면 탈출)
	
	vector<int> dist1(N + 1, INF);
	vector<int> dist2(N + 1, INF);
	
	Dijkstra(graph, dist1, stop1);
	Dijkstra(graph, dist2, stop2);
	int minDist = INF;
	if (INF > dist1[1] && INF > dist1[stop2] && INF > dist2[N])
		minDist = min(minDist, dist1[1] + dist1[stop2] + dist2[N]);
	if (INF > dist2[1] && INF > dist2[stop1] && INF > dist1[N])
		minDist = min(minDist, dist2[1] + dist2[stop1] + dist1[N]);

	if (minDist == INF)
		cout << -1 << '\n';
	else
		cout << minDist << '\n';

	return 0;
}