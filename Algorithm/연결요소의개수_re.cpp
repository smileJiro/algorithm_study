#include <bits/stdc++.h>

using namespace std;

int N, M;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int idx)
{
	visited[idx] = 1;

	for (int adj : graph[idx])
	{
		if (!visited[adj])
		{
			dfs(graph, visited, adj);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);
	vector<int> visited(N + 1);
	int s, e;
	for (int i = 0; i < M; ++i)
	{
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	int answer = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (!visited[i])
		{
			++answer;
			dfs(graph, visited, i);
		}
	}

	cout << answer << '\n';
	return 0;
}