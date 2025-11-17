#include <bits/stdc++.h>

using namespace std;

int N, M;

void dfs(vector<vector<int>>& graph, vector<int>& virus, vector<int>& visited, int n)
{
	virus.push_back(n);
	visited[n] = 1;
	for (int adj : graph[n])
	{
		if (!visited[adj])
			dfs(graph, virus, visited, adj);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);
	int s, e;
	for (int i = 0; i < M; ++i)
	{
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	vector<int> virus;
	vector<int> visited(N+1, 0);
	dfs(graph, virus, visited, 1);

	cout << virus.size() - 1 << '\n';
	return 0;
}