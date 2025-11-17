#include <bits/stdc++.h>

using namespace std;


int N;
int dp[50001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	dp[1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 2; j * j <= i; ++j)
		{
			int remain = i - j * j;
			dp[i] = min(dp[i], dp[remain] + 1);
		}
	}

	cout << dp[N] << '\n';
	return 0;
}