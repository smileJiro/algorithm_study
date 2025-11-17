#include <bits/stdc++.h>

using namespace std;

int X;
int dp[1000002];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> X;
	
	for (int i = 2; i <= X; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if(i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[X] << '\n';
	return 0;
}