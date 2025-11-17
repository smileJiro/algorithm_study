#include <bits/stdc++.h>
using namespace std;

enum STATE { HORIZON, DIAGONAL, VERTICAL, LAST };
int ds[] = { -1, 0, 1 };
int dx[] = { 1, 1, 0 };
int dy[] = { 0, 1, 1 };
int board[18][18];
int N;
int answer = 0;
bool OOB(int y, int x) 
{
	return 0 > y || 0 > x || N <= x || N <= y;
}
bool OOB_State(int eState)
{
	return 0 > eState || LAST <= eState;
}
void dfs(int y, int x, STATE eState)
{
	// 1. 현재 상태에서 검사 수행.
	switch (eState)
	{
	case HORIZON:
		if (OOB(y, x + 1) || board[y][x + 1] == 1)
			return;
		break;
	case DIAGONAL:
	{
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				if (OOB(y + i, x + j) || board[y + i][x + j] == 1)
					return;
			}
		}
	}
		break;
	case VERTICAL:
		if (OOB(y + 1, x) || board[y + 1][x] == 1)
			return;
		break;
	}

	int ny = y + dy[eState];
	int nx = x + dx[eState];
	if (ny == N - 1 && nx == N - 1)
	{
		answer += 1;
		return;
	}
	// 2. 다음 상태 결정 후 재귀 호출
	for (int i = 0; i < 3; ++i)
	{
		int newState = (int)eState + ds[i];
		if (!OOB_State(newState)) 
		{
			dfs(ny, nx, (STATE)newState);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];
	}

	dfs(0, 0, HORIZON);
	cout << answer << '\n';
	return 0;
}