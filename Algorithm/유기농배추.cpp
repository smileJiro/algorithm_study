#include <bits/stdc++.h>
using namespace std;

// 그래프 탐색을 통해서 방문노드를 체크한다. -> dfs에 진입하는 횟수를 구한다.
int board[52][52]; // 0 땅 1 배추 2 방문
int T, N, M, K;

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
bool OOB(int y, int x) // true면 범위 벗어남
{
	return 0 > y || 0 > x || M <= x || N <= y;
}
void dfs(int y, int x)
{
	board[y][x] = 2;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!OOB(ny, nx) && board[ny][nx] == 1)
			dfs(ny, nx);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		int answer = 0;
		memset(board, 0, sizeof(board));
		cin >> M >> N >> K;
		for (int i = 0; i < K; ++i)
		{
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (board[i][j] == 1)
				{
					dfs(i, j);
					++answer;
				}
			}
		}
		
		cout << answer << '\n';
	}
	
	return 0;
}