#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9;
int N, M;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	vector<vector<int>> graph(N+1, vector<int>(N+1, INF));
	for (int i = 1; i <= N; ++i)
		graph[i][i] = 0;

	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		graph[s][e] = 1;
		graph[e][s] = 1;
	}

	for (int k = 1; k <= N; ++k)
	{
		for (int s = 1; s <= N; ++s)
		{
			for (int e = 1; e <= N; ++e)
			{
				graph[s][e] = min(graph[s][e], graph[s][k] + graph[k][e]);
			}
		}
	}

	int answer = -1;
	int minValue = INF;
	for (int i = 1; i <= N; ++i)
	{
		int sum = 0;
		for (int j = 1; j <= N; ++j)
			sum += graph[i][j];

		if (sum < minValue)
		{
			answer = i;
			minValue = sum;
		}
	}

	cout << answer << '\n';
	return 0;
}