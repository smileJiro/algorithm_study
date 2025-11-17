#include <bits/stdc++.h>

using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(vector<vector<bool>>& graph, int col, int row, int level)
{
	if (0 > col || graph.size() <= col ||
		0 > row || graph[col].size() <= row)
		return;

	if (true == graph[col][row])
		return;

	graph[col][row] = true;

	for (int i = 0; i < 4; ++i)
	{
		int targetCol = col + dy[i];
		int targetRow = row + dx[i];
		dfs(graph, targetCol, targetRow, level + 1);
	}

	return;
}
int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<bool>> graph(n, vector<bool>(m, false));
	cin.ignore();
	for (int i = 0; i < n; ++i)
	{
		string str;
		
		getline(cin, str);
		for (int j = 0; j < str.size(); ++j)
			graph[i][j] = str[j] - '0';
	}

	int cnt = 0;
	for (int i = 0; i < graph.size(); ++i)
	{
		for (int j = 0; j < graph[i].size(); ++j)
		{
			if(false == graph[i][j])
			{
				++cnt;
				dfs(graph, i, j, 0);
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}