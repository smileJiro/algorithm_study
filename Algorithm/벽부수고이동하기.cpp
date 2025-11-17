#include <bits/stdc++.h>

using namespace std;
using T = tuple<int, int, bool>; // y, x, 벽 부순적 있나

constexpr int INF = 1e9;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int N, M;
int board[1002][1002];
int dist[1002][1002][2];
bool OOB(int y, int x)
{
	return 0 > y || N <= y || 0 > x || M <= x;
}
void bfs()
{
	queue<T> q;
	q.emplace(0, 0, false);
	dist[0][0][0] = 0;

	while (!q.empty())
	{
		auto [y, x, breaking] = q.front(); q.pop();
		if (y == N - 1 && x == M - 1)
			return;

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (OOB(ny, nx))
				continue;

			if (board[ny][nx] == 0 && dist[ny][nx][breaking] == INF)
			{
				dist[ny][nx][breaking] = dist[y][x][breaking] + 1;
				q.emplace(ny, nx, breaking);
			}
			else if (board[ny][nx] == 1 && dist[ny][nx][true] == INF && breaking == false)
			{
				dist[ny][nx][true] = dist[y][x][breaking] + 1;
				q.emplace(ny, nx, true);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; ++j)
		{
			board[i][j] = int(str[j] - '0');
			dist[i][j][0] = dist[i][j][1] = INF;
		}
		
	}
	bfs();

	if (N <= 0 || M <= 0) return 0;

	int v1 = dist[N - 1][M - 1][0];
	int v2 = dist[N - 1][M - 1][1];
	if (v1 == INF && v2 == INF)
		cout << -1 << '\n';
	else
		cout << min(v1, v2) + 1 << '\n';

	return 0;
}