#include <bits/stdc++.h>

using namespace std;
using T = tuple<bool, int, int>; // 벽 부순 경로 여부, y, x
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
constexpr int INF = 1e9;

#pragma region note
// 벽을 부순 경로인지 상태 검사 추가 수행
// 벽을 1회까진 부숴도 되니 막힌 길이더라도, 벽을 부순 상태가 아니라면, 최단 경로 갱신
#pragma endregion

int N, M;
bool OOB(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= M;
}
void BFS(vector<vector<int>>& board, vector<vector<vector<int>>>& visited)
{
	int sy{ 0 }, sx{ 0 };
	visited[0][sy][sx] = 0;
	queue<T> q;
	q.emplace(false, sy, sx);

	while (!q.empty())
	{
		const auto [breaked, y, x] = q.front(); q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nbreaked = breaked;
			if (OOB(ny, nx))
				continue;
			if (visited[nbreaked][ny][nx] != INF)
				continue;
			if (board[ny][nx] == 1)
			{
				if (nbreaked)
					continue;
				else
				{
					nbreaked = true;
				}
			}

			visited[nbreaked][ny][nx] = visited[breaked][y][x] + 1;
			q.emplace(nbreaked, ny, nx);
		}

	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M, 0));
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; ++j)
		{
			board[i][j] = str[j] - '0';
		}
	}

	vector<vector<vector<int>>> visited(2, vector<vector<int>>(N, vector<int>(M, INF)));
	BFS(board, visited);

	int answer = INF;
	answer = min(answer, visited[false][N - 1][M - 1]);
	answer = min(answer, visited[true][N - 1][M - 1]);
	 
	if (answer == INF)
		cout << -1 << '\n';
	else
		cout << answer + 1 << '\n';

	return 0;
}