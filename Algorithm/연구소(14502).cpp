#pragma region MyAnswer
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>; // y, x

// 1. 벽을 세운다. (3중  for문) -> 64C3
// 2. 바이러스를 퍼트린다. (dfs or bfs) -> O(N * M)
// 3. 안전 영역을 검사한다. O(N)

int N, M;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int board[10][10];

bool OOB(int y, int x)
{
	return 0 > y || N <= y || 0 > x || M <= x;
}
int bfs(vector<P>& virus, vector<P>& wall)
{
	int visited[10][10] = {0, };
	queue<P> q;
	for (auto& [y, x] : virus)
	{
		q.emplace(y, x);
		visited[y][x] = 1;
	}

	while (!q.empty())
	{
		auto[y, x] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!OOB(ny, nx))
			{
				if(visited[ny][nx] == 0 && board[ny][nx] == 0)
				{
					visited[ny][nx] = 1;
					q.emplace(ny,nx);
				}
			}
		}
	}


	// 영역 검사
	int ret = 0;
	//cout << "--------------------------------" << '\n';
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			//cout << visited[i][j] << ' ';
			if (visited[i][j] == 0 && board[i][j] != 1)
				++ret;
		}
		//cout << '\n';
	}
	//cout << "안전영역 수 : " << ret << '\n';
	return ret;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;

	vector<P> wall;
	vector<P> virus;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
				wall.emplace_back(i, j);
			else if (board[i][j] == 2)
				virus.emplace_back(i, j);
		}
	}

	// 벽을 세우는 경우의 수 -> 3개 이하니까 -> 만약 경우가 더 많다면 combi 구현
	int l = wall.size();
	int safeCount = 0;
	for (int i = 0; i < l; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			for (int k = 0; k < j; ++k)
			{
				// 벽을 세운다.
				board[wall[i].first][wall[i].second] = 1;
				board[wall[j].first][wall[j].second] = 1;
				board[wall[k].first][wall[k].second] = 1;
				// 바이러스를 퍼트린다. -> 안전지대 반환
				safeCount = max(bfs(virus, wall), safeCount);
				// 벽을 철거한다.
				board[wall[i].first][wall[i].second] = 0;
				board[wall[j].first][wall[j].second] = 0;
				board[wall[k].first][wall[k].second] = 0;
			}
		}
	}

	cout << safeCount << '\n';

	return 0;
}
#pragma endregion
