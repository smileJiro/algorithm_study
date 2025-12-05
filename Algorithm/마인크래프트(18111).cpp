#include <bits/stdc++.h>
using namespace std;


int N, M, B;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> B;
	vector<vector<int>> board(N, vector<int>(M, 0));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];
	}

	int answer = 1e9;
	int height = 0;
	for (int h = 0; h <= 256; ++h)
	{
		int add{ 0 };
		int del{ 0 };
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				int diff = h - board[i][j];
				if (0 > diff)				// 1. 깎을 블록 개수 연산 (기준보다 높은 블록 개수)
					del -= diff;
				else						// 2. 채울 블록 개수 연산 (기준보다 낮은 블록 개수)
					add += diff;
			}
		}
		
		if (add > del + B)				 // 3. 채울 블록 > 깍을 블록 인 경우 중단.
			break;
		else								 // 3. 아닌 경우 -> 시간 계산
		{
			int addTime = add;
			int delTime = del * 2;
			if (answer >= addTime + delTime)
			{
				answer = addTime + delTime;
				height = max(height, h);
			}
		}
	}

	cout << answer << ' ' << height << '\n';

	return 0;
}