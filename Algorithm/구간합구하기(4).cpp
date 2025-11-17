#include <bits/stdc++.h>

using namespace std;

int N, M;
int dp[100001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int num;
	for (int i = 1; i <= N; ++i)
	{
		cin >> num;
		dp[i] = dp[i - 1] + num;
	}

	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		cout << dp[e] - dp[s - 1] << '\n';
	}
	return 0;
}