#include <bits/stdc++.h>

using namespace std;

int N;
char RGB[102][102];
char RB[102][102];
bool visited[102][102];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

bool OOB(int y, int x)
{
	return 0 > y || 0 > x || N <= y || N <= x;
}
void dfs(char b[][102], int y, int x)
{
	if (visited[y][x])
		return;
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!OOB(ny, nx) && b[y][x] == b[ny][nx])
			dfs(b, ny, nx);
	}	
}
int getCountArea(char bd[][102])
{
	memset(visited, 0, sizeof(visited));
	int answer = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!visited[i][j])
			{
				++answer;
				dfs(bd, i, j);
			}
		}
	}

	return answer;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> RGB[i][j];
			if (RGB[i][j] == 'G')
				RB[i][j] = 'R';
			else
				RB[i][j] = RGB[i][j];
		}
	}

	cout << getCountArea(RGB) << ' ' << getCountArea(RB) << '\n';
	return 0;
}