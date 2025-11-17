#include <bits/stdc++.h>
#include <unordered_set>
//#include <iostream>
//#include <map>
//#include <queue>
//#include <algorithm>

using namespace std;
bool bfs(const vector<vector<int>>& maze, int* outCount)
{
	// 1.  queue를 통해 미로를 탐색한다. 
	int row = maze.size();
	int col = maze.front().size();
	int i = 0, j = 0;
	vector<vector<bool>> visited(row, vector<bool>(col, false));
	vector<vector<int>> dist(row, vector<int>(col, 0));
	queue<pair<int,int>> queue;
	queue.push({ 0, 0 });
	dist[0][0] = 1;
	visited[0][0] = true;
	while (!queue.empty())
	{
		pair<int, int> pop = queue.front();
		queue.pop();
		// 도착 검사
		if (pop.first == row - 1 && pop.second == col - 1)
		{
			*outCount = dist[pop.first][pop.second];
			return true;
		}
		
		// 인접 노드 queue에 추가
		
		// right
		if (pop.second + 1 < col)
		{
			if (1 == maze[pop.first][pop.second + 1] &&
				true != visited[pop.first][pop.second + 1])
			{
				visited[pop.first][pop.second + 1] = true;
				queue.push({ pop.first , pop.second + 1 });
				dist[pop.first][pop.second + 1] = dist[pop.first][pop.second] + 1;
			}
		}
			
		// left
		if (pop.second - 1 >= 0)
			if (1 == maze[pop.first][pop.second - 1] &&
				true != visited[pop.first][pop.second - 1])
			{
				visited[pop.first][pop.second - 1] = true;
				queue.push({ pop.first , pop.second - 1 });
				dist[pop.first][pop.second - 1] = dist[pop.first][pop.second] + 1;
			}
		// down
		if (pop.first + 1 < row)
			if (1 == maze[pop.first + 1][pop.second] &&
				true != visited[pop.first + 1][pop.second])
			{
				visited[pop.first + 1][pop.second] = true;
				queue.push({ pop.first + 1, pop.second });
				dist[pop.first + 1][pop.second] = dist[pop.first][pop.second] + 1;
			}
		// up
		if (pop.first - 1 >= 0)
			if (1 == maze[pop.first - 1][pop.second] &&
				true != visited[pop.first - 1][pop.second])
			{
				visited[pop.first - 1][pop.second] = true;
				queue.push({ pop.first - 1, pop.second });
				dist[pop.first - 1][pop.second] = dist[pop.first][pop.second] + 1;
			}

	}
	// 3. 도착에 성공하면 true 반환 + outCount를 리턴한다.


	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> maze(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
	{
		string line;
		cin >> line;
		for (int j = 0; j < M; ++j)
		{
			maze[i][j] = line[j] - '0';
		}
	}

	int out = 0;

	bfs(maze, &out);

	cout << out;
	return 0;
}
