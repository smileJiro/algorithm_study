#include <bits/stdc++.h>

using namespace std;
using P = pair<int, int>; // y, x
using T = tuple<int, int, int, int, int>; // ry, rx, by, bx, dist
constexpr int INF = 1e9;

char board[12][12];
bool visited[12][12][12][12];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int N, M;
bool OOB(int y, int x)
{
	return 0 > y || N <= y || 0 > x || M <= x;
}
P Move(int y, int x, int dir, int* outMoveCount)
{
	P finalPos = {y, x};

	int ny = y + dy[dir];
	int nx = x + dx[dir];
	while (!OOB(ny, nx) && board[ny][nx] != '#')
	{
		if(board[ny][nx] == 'O')
			return { ny, nx };
		else
		{
			*outMoveCount += 1;
			ny += dy[dir];
			nx += dx[dir];
		}
	}
	
	return { ny - dy[dir], nx - dx[dir] };
}
void bfs(int start_ry, int start_rx, int start_by, int start_bx)
{
	memset(visited, 0, sizeof(visited));
	queue<T> q;
	q.emplace(start_ry, start_rx, start_by, start_bx, 0);
	visited[start_ry][start_rx][start_by][start_bx] = true;

	while (!q.empty())
	{
		auto [ry, rx, by, bx, dist] = q.front(); q.pop();
		if (dist == 10) // 실패
		{
			cout << -1 << '\n';
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int moveCountR{ 0 }, moveCountB{ 0 };
			auto [new_ry, new_rx] = Move(ry, rx, i, &moveCountR); // red
			auto [new_by, new_bx] = Move(by, bx, i, &moveCountB); // blue

			// Blue가 도착지점에 도달한 경우 예외처리
			if (board[new_by][new_bx] == 'O')
				continue;

			// 겹친 경우 예외 처리
			if ((new_ry == new_by) && (new_rx == new_bx)) 
			{
				if (moveCountR > moveCountB) // red가 더 많이갔다면
				{
					new_ry -= dy[i];
					new_rx -= dx[i];
				}
				else
				{
					new_by -= dy[i];
					new_bx -= dx[i];
				}
			}

			// 도착 처리
			if (board[new_ry][new_rx] == 'O')
			{
				cout << dist + 1 << '\n';
				return;
			}

			if (visited[new_ry][new_rx][new_by][new_bx] == false)
			{
				visited[new_ry][new_rx][new_by][new_bx] = true;
				q.emplace(new_ry, new_rx, new_by, new_bx, dist + 1);
			}
			
		}
		
	}

	cout << -1 << '\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	string str = "";
	int start_ry{}, start_rx{}, start_by{}, start_bx{};
	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		for (int j = 0; j < M; ++j)
		{
			board[i][j] = str[j];
			if (str[j] == 'R')
			{
				start_ry = i; start_rx = j;
			}
			else if (str[j] == 'B')
			{
				start_by = i; start_bx = j;
			}
		}
	}

	bfs(start_ry, start_rx, start_by, start_bx);
	return 0;
}