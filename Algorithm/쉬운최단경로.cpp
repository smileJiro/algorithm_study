#include <bits/stdc++.h>

using namespace std;

int N, M;
int board[1002][1002];
int visited[1002][1002];
int dx[] = { 0 ,1, 0, -1 };
int dy[] = { -1 ,0, 1, 0 };
bool OOB(int y, int x)
{
	return 0 > y || 0 > x || N <= y || M <= x;
}
void bfs(int sY, int sX)
{
	queue<pair<int,int>> q;
	q.emplace(sY, sX); // 시작 지점
	board[sY][sX] = 0;
	while (!q.empty())
	{
		auto [y, x] = q.front(); q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!OOB(ny, nx) && board[ny][nx] == -1) // 유효한 범위라면
			{
				board[ny][nx] = board[y][x] + 1; // 값 추가
				q.emplace(ny, nx); // 큐에 추가.
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int sY{}, sX{};
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				board[i][j] = -1; // -1로 초기화 갈수있는 땅중에서도 도달 못하는 곳
			else if (board[i][j] == 2)
			{
				sY = i; sX = j;
			}
		}
	}

	bfs(sY, sX);

	for(int i =0 ; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}