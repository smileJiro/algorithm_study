#include <bits/stdc++.h>

using namespace std;

void computeMinCount(vector<int>& dp, const vector<int>& div)
{
	int n = dp.size();
	for (int i = 2; i < n; ++i)
	{
		dp[i] = dp[i - 1];
		for (int d : div)
		{
			if (!(i % d))
				dp[i] = min(dp[i], dp[i / d]) + 1;
		}
	}
}


int main()
{
	int n;
	cin >> n;

	vector<int> dp(n + 1, 0);
	const vector<int> div = { 2,3,5 };

	computeMinCount(dp, div);

	cout << "result : " << dp[n] << '\n';
	
	return 0;
}