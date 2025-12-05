#include<bits/stdc++.h>

using namespace std;

int v, e;
vector<int> indegree;
vector<vector<int>>graph;

void topologySort()
{
	vector<int> result;
	queue<int> q;

	// 시작 노드 삽입 
	for (int i = 1; i < indegree.size(); ++i)
		if (indegree[i] == 0)
		{
			q.push(i);
			result.push_back(i);
		}

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int adj = graph[cur][i];
			indegree[adj] -= 1;
			if (0 == indegree[adj])
			{
				q.push(adj);
				result.push_back(adj);
			}
			
		}
	}

	if (result.size() == graph.size() - 1)
		for (int i = 0; i < result.size(); ++i)
			cout << result[i] << ' ';
	else
		cout << "Failed : is Not DAG" << '\n';

}
int main()
{
	cin >> v >> e;
	indegree.resize(v + 1, 0);
	graph.resize(v + 1);

	for (int i = 0; i < e; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		indegree[v] += 1;
	}

	topologySort();

	return 0;
}