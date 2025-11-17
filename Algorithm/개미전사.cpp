#include<bits/stdc++.h>
using namespace std;
#define ISEMPTY -1
int maxStolen_td(const vector<int>& arr, vector<int>& dp, int i) // 탑다운
{
	if (i == 0)
		return arr[0];
	else if (i == 1)
		return arr[0] > arr[1] ? arr[0] : arr[1];

	if (ISEMPTY != dp[i])
		return dp[i];

	dp[i] = max(maxStolen_td(arr, dp, i - 1), maxStolen_td(arr, dp, i - 2) + arr[i]);

	return dp[i];
}

int maxStolen_bu(const vector<int>& arr, vector<int>& dp, int _i) // 바텀업
{
	dp[0] = arr[0];
	dp[1] = max(arr[0], arr[1]);

	for (int i = 2; i < dp.size(); ++i)
		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);

	return dp[_i];
}
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> dp(n, ISEMPTY);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	//cout << "topdown : " << maxStolen_td(arr, dp, n - 1) << '\n';

	cout << "bottomup : " << maxStolen_bu(arr, dp, n - 1);
	return 0;
}