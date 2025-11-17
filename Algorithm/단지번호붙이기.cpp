#include <bits/stdc++.h>

using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int N;
int board[26][26];
bool visited[26][26];
bool OOB(int y, int x)
{
	return 0 > y || 0 > x || N <= y || N <= x;
}
void getNum(int y, int x, int* outCnt)
{
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!OOB(ny,nx)&&!visited[ny][nx] && board[ny][nx] != 0)
		{
			*outCnt += 1;
			visited[ny][nx] = true;
			getNum(ny, nx, outCnt);
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
		string str;
		cin >> str;
		int j = 0;
		for (char c : str)
			board[i][j++] = c - '0';
	}

	vector<int> answer;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!visited[i][j] && board[i][j] != 0)
			{
				int cnt = 1;
				visited[i][j] = true;
				getNum(i, j, &cnt);
				answer.push_back(cnt);
			}
				
		}
	}

	cout << answer.size() << '\n';
	sort(answer.begin(), answer.end());
	for (int n : answer)
		cout << n << '\n';
	return 0;
}