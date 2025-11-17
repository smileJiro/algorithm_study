#include <bits/stdc++.h>

using namespace std;


string A, B;
int sizeA, sizeB;
int main()
{
	cin >> A >> B;
	sizeA = A.size();
	sizeB = B.size();
	vector<vector<int>> dp(sizeB + 1, vector<int>(sizeA + 1, 0));

	for (int i = 1; i <= sizeB; ++i)
	{
		for (int j = 1; j <= sizeA; ++j)
		{
			if (A[j - 1] == B[i - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[sizeB][sizeA] << '\n';
	return 0;
}