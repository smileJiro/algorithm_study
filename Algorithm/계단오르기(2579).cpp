#include <bits/stdc++.h>

using namespace std;

int32_t n;
void computeMaxScore(const vector<int32_t>& stairs, vector<int32_t>& dp)
{
	dp[0] = stairs[0];
	dp[1] = stairs[0] + stairs[1];
	dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (int32_t i = 3; i < n; ++i)
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	vector<int32_t> stairs(n);
	for (int32_t i = 0; i < n; ++i)
		cin >> stairs[i];

	vector<int32_t> dp(n, 0);
	if (1 == n)
		cout << stairs[0] << '\n';
	else if (2 == n)
		cout << stairs[0] + stairs[1] << '\n';
	else if (3 == n)
		cout << max(stairs[0] + stairs[2], stairs[1] + stairs[2]) << '\n';
	else
	{
		computeMaxScore(stairs, dp);
		cout << dp[n - 1] << '\n';
	}
	

	return 0;
}