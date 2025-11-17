#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>; // y, x

int N, M;
int board[1002][1002];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

bool OOB(int y, int x)
{
	return 0 > y || N <= y || 0 > x || M <= x;
}
void bfs(int sY, int sX)
{
	queue<P> q;
	q.emplace(sY, sX);
	board[sY][sX] = 0;

	while (!q.empty())
	{
		auto [y, x] = q.front(); q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (OOB(ny, nx))
				continue;

			if (board[ny][nx] == -1)
			{
				q.emplace(ny, nx);
				board[ny][nx] = board[y][x] + 1;
			}
		}
	}
	

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			cout << board[i][j] << ' ';

		cout << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	int sX{0}, sY{0};
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if(board[i][j] == 1)
				board[i][j] = -1;
			else if (board[i][j] == 2)
			{
				sY = i, sX = j;
			}
		}
	}

	bfs(sY, sX);

	return 0;
}