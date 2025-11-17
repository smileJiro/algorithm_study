#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
int N{}, D{};
vector<pair<int, int>> adj[10001]; // adj[u] = {v, cost};
int dist[10002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> D;
	for (int i = 0; i < N; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		if (v > D)
			continue;

		adj[u].emplace_back(v, w); // u -> v 지름길 모든 경로에 대해서 지름길 추가
	}

	// 최단 거리 테이블 초기화
	for (int i = 0; i <= D; ++i)
		dist[i] = INF;
	dist[0] = 0;

	for (int i = 0; i <= D; ++i) // dp
	{
		// 1. 직선 경로에 따른 업데이트
		if(i > 0)
			dist[i] = min(dist[i], dist[i - 1] + 1); 

		// 2. 지름길 확인
		for (auto& [next, w] : adj[i]) // i에서 갈 수 있는 지름길 리스트 업데이트
		{
			dist[next] = min(dist[next], dist[i] + w);
		}
	}


	cout << dist[D];
	return 0;
}