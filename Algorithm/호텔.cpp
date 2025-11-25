#include <bits/stdc++.h>

using namespace std;
using P = pair<int, int>; // cost, value
int C, N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> C >> N;
	vector<P> cities(N);
	// 도시 정보 입력
	int max_cost = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> cities[i].first >> cities[i].second;
		max_cost = max(max_cost, cities[i].first);
	}
		
	int limit = max_cost * C;
	vector<int> dp(limit + 1, 0);
	dp[0] = 0;
	for (int i = 1; i <= limit; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			auto& [cost, value] = cities[j];
			if(i >= cost)
				dp[i] = max(dp[i], dp[i - cost] + value);
		}
		
		if (dp[i] >= C)
		{
			cout << i << '\n';
			return 0;
		}
	}

	return 0;
}