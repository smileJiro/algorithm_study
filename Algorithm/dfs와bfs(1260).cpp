#include <bits/stdc++.h>
// 코드 구림 -> 우선순위 큐 말고 배열로만 쓰고 오름차순 정렬하는식으로하자.
using namespace std;
vector<priority_queue<int, vector<int>, greater<int>>> graph;
vector<priority_queue<int, vector<int>, greater<int>>> graph2;
vector<int> visited;
void dfs(int idx)
{
	if (visited[idx])
		return;

	visited[idx] = true;
	cout << idx << ' ';

	while (!graph[idx].empty())
	{
		int next = graph[idx].top();
		graph[idx].pop();
		dfs(next);
	}
}
void bfs(int idx)
{
	queue<int> q;
	q.push(idx);
	visited[idx] = true;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		cout << cur << ' ';
		while (!graph2[cur].empty())
		{
			int next = graph2[cur].top(); graph2[cur].pop();
			if(false == visited[next])
			{
				q.push(next);
				visited[next] = true;
			}
		}
		
		
	}
}
int main()
{
	int n, m, v;
	cin >> n >> m >> v;

	graph.resize(n + 1);
	visited.resize(n + 1, false);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push(v);
		graph[v].push(u);
	}
	graph2 = graph;
	dfs(v);
	
	fill(visited.begin(), visited.end(), false);
	cout << '\n';
	bfs(v);
	return 0;
}