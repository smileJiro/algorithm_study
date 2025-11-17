#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
using TP = tuple<int, int, int>; // h, y, x;
int M, N, H;
int tomato[102][102][102];
int visited[102][102][102];

int dx[] = { 0, 1, 0, -1, 0, 0 }; // 상단부터 시계방향 , far, near 순
int dy[] = { 0, 0, -0, 0, -1, 1 }; // 상단부터 시계방향 , far, near 순
int dh[] = { 1, 0, -1, 0, 0, 0 }; // 상단부터 시계방향 , far, near 순

bool OOB(int h, int y, int x)
{
	return 0 > h || 0 > y || 0 > x || H <= h || N <= y || M <= x;
}
void bfs(const vector<TP>& starts)
{
	queue<TP> q;
	for (auto& [h, y, x] : starts)
	{
		q.emplace(h,y,x);
		tomato[h][y][x] = 0;
		visited[h][y][x] = 1;
	}

	while (!q.empty())
	{
		auto [h, y, x] = q.front(); q.pop();

		for (int i = 0; i < 6; ++i) // 6 방향
		{
			int nh = h + dh[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!OOB(nh, ny, nx) && tomato[nh][ny][nx] != -1 && visited[nh][ny][nx] == 0)
			{
				visited[nh][ny][nx] = 1;
				tomato[nh][ny][nx] = tomato[h][y][x] + 1;
				q.emplace(nh, ny, nx);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N >> H;

	vector<TP> starts;
	for (int h = 0; h < H; ++h)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> tomato[h][i][j];
				if (tomato[h][i][j] == 0)
					tomato[h][i][j] = INF;
				else if (tomato[h][i][j] == 1)
					starts.emplace_back(h, i, j);
			}
		}
	}

	bfs(starts);

	int answer = 0;
	for(int h = 0; h < H; ++h)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (tomato[h][i][j] == INF)
				{
					cout << -1 << '\n';
					return 0;
				}
				else if (tomato[h][i][j] != -1)
				{
					answer = max(answer, tomato[h][i][j]);
				}
			}
		}
	}

	cout << answer << '\n';

	return 0;
}