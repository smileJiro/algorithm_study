#include <bits/stdc++.h>

using namespace std;
// 방향 그래프 -> 유니온파인드 x 
// 인접 행렬로 간선 연결 받고, 일일히 각 노드 백트래킹 돌리면서 결과 탐색
constexpr int INF = 1e9;
int N;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	vector<vector<int>> graph(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cin >> graph[i][j];
	}

	for (int k = 0; k < N; ++k) // 거쳐가는
	{
		for (int s = 0; s < N; ++s) // 시작점
		{
			for (int e = 0; e < N; ++e) // 도착점
			{
				if (graph[s][k])
				{
					graph[s][e] |= graph[k][e];
				}
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}