#include <bits/stdc++.h>

using namespace std;
#define INF 1e9
using P = pair<int, int>; // y, x
int N, M;
int tomato[1002][1002];  // 토마토 밭
int visited[1002][1002]; // 방문검사
int dx[] = { 0 ,1, 0, -1 };
int dy[] = { -1 ,0, 1, 0 };
bool OOB(int y, int x)
{
	return 0 > y || 0 > x || N <= y || M <= x;
}
void bfs(const vector<P>& starts)
{
	queue<P> q;
	for (auto& [y, x] : starts)
	{
		q.emplace(y, x);
		tomato[y][x] = 0;
		visited[y][x] = 1;
	}

	while (!q.empty())
	{
		auto [y, x] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!OOB(ny, nx) && tomato[ny][nx] != -1 && visited[ny][nx] == 0)
			{
				visited[ny][nx] = 1; // 방문
				tomato[ny][nx] = tomato[y][x] + 1; // 결과 저장
				q.emplace(ny, nx);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;

	vector<P> starts;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int num;
			cin >> tomato[i][j];
			if (tomato[i][j] == 0)
				tomato[i][j] = INF;
			if (tomato[i][j] == 1)
				starts.emplace_back(i, j); // 시작점 기록
		}
	}

	bfs(starts);


	int answer = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (tomato[i][j] == INF)
			{
				cout << -1 << '\n';
				return 0 ;
			}
			else if (tomato[i][j] != -1)
			{
				answer = max(answer, tomato[i][j]);
			}
		}
	}

	cout << answer << '\n';
	return 0;
}