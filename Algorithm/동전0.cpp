#include <bits/stdc++.h>

using namespace std;

// greedy
int N, K;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	vector<int> coins(N, 0);
	for (int i = N - 1; i >= 0; --i)
		cin >> coins[i];

	int answer = 0;
	for (int i = 0; i < N; ++i)
	{
		int devide = K / coins[i];
		K -= coins[i] * devide;
		answer += devide;
		if (K == 0)
			break;
	}

	cout << answer << '\n';
	return 0;
}