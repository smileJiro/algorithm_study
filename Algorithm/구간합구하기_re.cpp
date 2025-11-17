#include <bits/stdc++.h>

using namespace std;

int N, M;
int dp[100002];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;


	int input;
	for (int i = 1; i <= N; ++i)
	{
		cin >> input;
		dp[i] = dp[i - 1] + input;
	}

	int i, j;
	while (M--)
	{
		cin >> i >> j;
		cout << dp[j] - dp[i - 1] << '\n';
	}
	return 0;
}