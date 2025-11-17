#include <bits/stdc++.h>

using namespace std;

int N;
int cost[1002];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> cost[i];

	sort(cost, cost + N);
	int sum = 0;
	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += cost[i];
		result += sum;
	}

	cout << result;
	return 0;
}