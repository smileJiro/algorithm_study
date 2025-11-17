#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> coin(n);
	for (int i = 0; i < n; ++i)
		cin >> coin[i];

	vector<int> dp(m + 1, INT_MAX);
	dp[0] = 0;

	// 개선 답안.
	for (int i = 0; i < n; ++i) // 코인 수
	{
		for (int j = coin[i]; j < dp.size(); ++j) // 코인 금액부터 시작 -> 모든 dp 순회 
		{
			if (dp[j - coin[i]] != INT_MAX)
			{
				dp[j] = min(dp[j], dp[j - coin[i]] + 1);
			}
		}
	}
	if (dp[m] == INT_MAX)
		cout << -1 << '\n';
	else
		cout << dp[m] << '\n';




	//// 내 풀이
	//for (int i = 1; i <= m; ++i)
	//{
	//	bool isResult = false;
	//	int minValue = INT_MAX;
	//	for (int c : coin)
	//	{
	//		int minus = i - c;
	//		if (0 <= minus && -1 != dp[minus])
	//		{
	//			isResult = true;
	//			minValue = min(minValue, dp[minus] + 1);
	//		} // min() 비교 이쪽이 문제임 dp[i]랑 비교하는게 아니라 음수가 안나온 coin 비교사례들이랑 비교해야함 07.25
	//	}
	//	if (isResult == true)
	//		dp[i] = -1;
	//	else
	//		dp[i] = minValue;
	//}

	//cout << dp[m] << '\n';
	return 0;
}