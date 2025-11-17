#include <bits/stdc++.h>

using namespace std;

enum TYPE { WHITE, BLUE, LAST };
// 1. 현재 범위 사각형의 lt, rb를 전달해서 검사하기 -> white인지 blue인지 x 인지
// 2. 분할 하기 (검사할 LT, RB 배열 4개를 만든다? )
int N;
int paper[130][130];

int counts[LAST];
int whiteCount, blueCount;
bool checkPaper(int y, int x, int size)
{
	int color = paper[y][x];
	for (int i = y; i < y + size; ++i)
	{
		for (int j = x; j < x + size; ++j)
		{
			if (paper[i][j] != color)
				return false;
		}
	}

	return true;
}
void dfs(int y, int x, int size)
{
	if (checkPaper(y, x, size))
	{
		paper[y][x] == 0 ? ++counts[WHITE] : ++counts[BLUE];
		return;
	}
	
	int half = size / 2;
	dfs(y,x,half);				// lt
	dfs(y,x + half,half);		// rt
	dfs(y+half,x,half);			// lb
	dfs(y+half,x+half,half);	// rb
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> paper[i][j];
	
	dfs(0, 0, N);

	cout << counts[WHITE] << '\n' << counts[BLUE] << '\n';
	return 0;
}