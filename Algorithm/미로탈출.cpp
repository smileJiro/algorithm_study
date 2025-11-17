#include <bits/stdc++.h>

using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct pos
{
public:
	pos() = delete;
	pos(int row, int col)
		: row(row)
		, col(col)
	{}
public:
	int row = 0;
	int col = 0;
};
int maze(vector<vector<int>>& graph, vector<vector<bool>>& visited, pos start, pos target)
{
	int n = graph.size();
	int m = graph[0].size();
	queue<pos> queue;
	queue.push(pos(start.row, start.col));
	visited[start.row][start.col] = true;
	while (!queue.empty())
	{
		pos cur = queue.front();
		queue.pop();
		for (int i = 0; i < 4; ++i)
		{
			int targetRow = cur.row + dy[i];
			int targetCol = cur.col + dx[i];

			if (0 > targetRow || n <= targetRow ||
				0 > targetCol || m <= targetCol) // 인덱스 유효성 검사
				continue;

			if (0 == graph[targetRow][targetCol]) // 0 검사
				continue;

			if (true == visited[targetRow][targetCol]) // 방문 검사
				continue;

			graph[targetRow][targetCol] = graph[cur.row][cur.col] + 1;
			queue.push(pos(targetRow, targetCol));
			visited[targetRow][targetCol] = true;

			if (target.row == targetRow && target.col == targetCol)
				return graph[target.row][target.col];
		}
	}

	return -1;
}
int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	cin.ignore();
	for (int i = 0; i < n; ++i)
	{
		string str;
		getline(cin, str);
		for (int j = 0; j < str.size(); ++j)
			graph[i][j] = str[j] - '0';
	}

	int result = maze(graph, visited, pos(0,0), pos(n - 1, m - 1));

	cout << result << '\n';

	return 0;
}