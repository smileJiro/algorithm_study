#include <bits/stdc++.h>
using namespace std;
int N;
int board[130][130];
int paperCount[2];
bool CheckBoard(int r, int c, int len, int color)
{
	for (int i = r; i < r + len; ++i)
	{
		for (int j = c; j < c + len; ++j)
		{
			if (board[i][j] != color)
				return false;
		}
	}

	return true;
}

void Divide(int r, int c, int len)
{
	int color = board[r][c];
	if (CheckBoard(r, c, len, color))
	{
		++paperCount[color];
		return;
	}

	int half = len / 2;
	Divide(r, c, half);
	Divide(r, c + half, half);
	Divide(r + half, c, half);
	Divide(r + half, c + half, half);
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

	Divide(0, 0, N);

	cout << paperCount[0] << '\n' << paperCount[1] << '\n';
	return 0;
}