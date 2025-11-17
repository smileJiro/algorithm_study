#include<bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<int>>& _graph, int start = 0)
{
	vector<bool> visited(_graph.size(), false);
	stack<int> stack;
	stack.push(start);

	while (!stack.empty())
	{
		int pop = stack.top();
		stack.pop();
		if (!visited[pop])
		{
			visited[pop] = true;
			cout << "¹æ¹® : " << pop << '\n';
			for (int i = 0; i < _graph[pop].size(); ++i)
				stack.push(_graph[pop][i]);
		}
	}

}

void dfs_recursive(const vector<vector<int>> _graph, vector<bool>& _visited, int _idx)
{
	_visited[_idx] = true;
	cout << _idx << ' ';
	
	for (int i = 0; i < _graph[_idx].size(); ++i)
	{
		int nextIdx = _graph[_idx][i];
		if (!_visited[_idx])
			dfs_recursive(_graph, _visited, nextIdx);
	}
	
}
int main()
{
	vector<bool> visited(8);
	
	vector<vector<int>> graph(8, vector<int>(0));
	graph[0] = { 1,2,7 };

	graph[1] = { 0,6 };

	graph[2] = { 0,3,4 };
;
	graph[3] = { 2,4 };

	graph[4] = { 2,3 };

	graph[5] = { 6 };

	graph[6] = { 1,5,7 };

	graph[7] = { 0,6 };

	for (auto& adj : graph)
		sort(adj.begin(), adj.end(), greater());
	dfs(graph, 6);

	return 0;
}