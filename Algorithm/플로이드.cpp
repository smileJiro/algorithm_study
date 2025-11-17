#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;
int N, M;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	// 초기화
	vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));
	for (int i = 1; i <= N; ++i)
		graph[i][i] = 0;

	// 입력
	for (int i = 0; i < M; ++i)
	{
		int s, e, c;
		cin >> s >> e >> c;
		graph[s][e] = min(graph[s][e], c);
	}

	// 플로이드
	for (int k = 1; k <= N; ++k) 
	{
		for (int s = 1; s <= N; ++s)
		{
			for (int e = 1; e <= N; ++e)
				graph[s][e] = min(graph[s][e], graph[s][k] + graph[k][e]);
		}
	}

	// 출력
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (graph[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}