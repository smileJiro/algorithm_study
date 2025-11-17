#include <bits/stdc++.h>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int N, M;
int answer = 0;
char board[602][602];
bool visited[602][602];
bool OOB(int y, int x)
{
	return 0 > y || 0 > x || N <= y || M <= x;
}
void DFS(int y, int x)
{
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!OOB(ny, nx) && board[ny][nx] != 'X' && !visited[ny][nx])
		{
			visited[ny][nx] = 1;
			if (board[ny][nx] == 'P')
				answer += 1;
			DFS(ny, nx);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	int sy{}, sx{};
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 'I')
			{
				sy = i;
				sx = j;
			}
		}	
			
	}

	DFS(sy,sx);
	if (answer)
		cout << answer << '\n';
	else
		cout << "TT" << '\n';
	return 0;
}