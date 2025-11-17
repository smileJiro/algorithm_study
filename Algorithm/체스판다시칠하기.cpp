#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[52][52];
int result = 1e9;

int getMin(int y, int x)
{
	int even = 0;
	int odd = 1;
	int minCount = 1e9;
	for (int i = 0; i < 2; ++i) // w시작, b 시작 한번 씩 검사
	{
		int count = 0;
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				int ny = i + y;
				int nx = j + x;
				if ((i + j) % 2) // 홀수라면
				{
					if (odd != board[ny][nx])
						++count;
				}
				else
				{
					if (even != board[ny][nx])
						++count;
				}
			}
		}

		minCount = min(minCount, count);
		swap(even, odd);
	}
	
	return minCount;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char c; cin >> c;
			if (c == 'W')
				board[i][j] = 0;
			else
				board[i][j] = 1;
		}
	}
		

	// 2. 체스판 인덱스 범위 안에서 시작 지점 설정하고 반복문 수행 -> 블랙이냐 화이트냐에 따라 인덱스 확인 방식 차이 있음
	for (int i = 0; i <= n - 8; ++i)
	{
		for (int j = 0; j <= m - 8; ++j)
		{
			result = min(result, getMin(i, j));
		}
	}
		
	cout << result << '\n';
	return 0;
}