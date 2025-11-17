#include <bits/stdc++.h>

using namespace std;

bool visited[1001] = {};
vector<vector<int>> graph;
void dfs(int idx)
{
	if (visited[idx])
		return;

	visited[idx] = true;

	for (int adj : graph[idx])
		dfs(adj);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	graph.resize(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		if(!visited[i])
		{
			++count;
			dfs(i);
		}
	}

	cout << count << '\n';
	return 0;
}