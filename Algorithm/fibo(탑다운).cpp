#include <bits/stdc++.h>

using namespace std;


unsigned long long fibo(int i)
{
	if (i == 1 || i == 2)
		return  1;

	return fibo(i - 1) + fibo(i - 2);
}

unsigned long long fibo_dp(int i, vector<unsigned long long>& dp)
{
	if (i == 1 || i == 2)
		return 1;

	if (0 != dp[i])
		return dp[i];

	dp[i] = fibo_dp(i - 1, dp) + fibo_dp(i - 2, dp);

	return dp[i];
}
int main()
{
	//unsigned long long i = fibo(20);

	int n = 50;
	vector<unsigned long long> dp(n + 1);
	unsigned long long i2 = fibo_dp(n, dp);
	return 0;
}