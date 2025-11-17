#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	n += 1;
	constexpr int INF = 1e9;
	vector<vector<int>> dist(n, vector<int>(n, INF));
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	int x, k;
	cin >> x >> k;


	for (int k = 1; k < n; ++k) // °æÀ¯
	{
		for (int s = 1; s < n; ++s)
		{
			for (int e = 1; e < n; ++e)
			{
				if(dist[s][k] != INF && dist[k][e] != INF)
				dist[s][e] = min(dist[s][e], dist[s][k] + dist[k][e]);
			}
		}
	}

	if (dist[1][k] == INF || dist[k][x] == INF)
		cout << -1 << '\n';
	else
		cout << dist[1][k] + dist[k][x] << '\n';

	return 0;
}