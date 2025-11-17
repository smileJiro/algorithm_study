#include<bits/stdc++.h>
using namespace std;

int main()
{
	int testCnt;
	cin >> testCnt;
	while (testCnt--)
	{
		int n, m;
		cin >> n >> m;

		vector<vector<int>> dp(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> dp[i][j];
			}
		}

		for (int col = 1; col < m; ++col)
		{
			for (int row = 0; row < n; ++row)
			{
				int cur = dp[row][col];
				int prevCol = col - 1;
				int leftUp, left, leftDown;
				if (0 == row) // 대각 위
					leftUp = 0;
				else
					leftUp = dp[row - 1][prevCol];

				if (n - 1 == row) // 대각 아래
					leftDown = 0;
				else
					leftDown = dp[row + 1][prevCol];

				left = dp[row][prevCol];

				dp[row][col] = dp[row][col] + max(leftUp, max(left, leftDown));
			}
		}

		// 마지막 열의 최대 값이 정답.
		int result = 0;
		for (int i = 0; i < n; ++i)
			result = max(result, dp[i][m - 1]);

		cout << result << '\n';
	}


	
	return 0;
}