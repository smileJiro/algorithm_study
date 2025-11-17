#include <bits/stdc++.h>

using namespace std;

enum TYPE { SLICE, WHITE, BLUE, LAST };
// 1. 현재 범위 사각형의 lt, rb를 전달해서 검사하기 -> white인지 blue인지 x 인지
// 2. 분할 하기 (검사할 LT, RB 배열 4개를 만든다? )
int N;
int paper[130][130];

int counts[LAST];
int whiteCount, blueCount;
TYPE checkPaper(int t, int l, int b, int r)
{
	TYPE type = (TYPE)(paper[t][l] + 1);
	for (int i = t; i < b; ++i)
	{
		for (int j = l; j < r; ++j)
		{
			if (paper[i][j] + 1 != type)
				return SLICE;
		}
	}

	return type;
}
void dfs(int y, int x, int level)
{
	if (level == N / 2) // 더 이상 나눌 수 없다.
	{
		return;
	}

	int devide = 1;
	for (int i = 0; i < level; ++i)
		devide *= 2;

	for (int i = 0; i < 2; ++i)
	{
		int sY = y + (i * N / devide);
		int eY = y + ((i + 1) * N / devide);
		for (int j = 0; j < 2; ++j)
		{
			int sX = x + (j * N / devide);
			int eX = x + ((j + 1) * N / devide);

			TYPE type = checkPaper(sY, sX, eY, eX);
			if (SLICE == type)
				dfs(sY, sX, level + 1);
			else
			{
				counts[type] += 1;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> paper[i][j];
	// 현재 레벨에 맞게 사각형 분할 -> 만약 level이 0이라면,
	TYPE type = checkPaper(0, 0, N, N);
	if (SLICE != type) // 전체 페이지 검사
	{
		counts[type] += 1; // 해당 색종이 카운트 증가
	}
	else // 잘라야 하는 경우
	{
		dfs(0,0,1);
	}


	cout << counts[WHITE] << '\n' << counts[BLUE] << '\n';
	return 0;
}