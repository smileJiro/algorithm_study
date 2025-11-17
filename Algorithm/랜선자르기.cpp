#include <bits/stdc++.h>

using namespace std;

using ll = long long;
ll K, N; // 이미 가진 랜선 수, 필요한 랜선 갯수
ll answer; // 랜선 하나당 최대 길이
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> K >> N;

	vector<ll> lanList(K, 0);
	
	for (ll i = 0; i < K; ++i)
		cin >> lanList[i];
	ll maxLen = *max_element(lanList.begin(), lanList.end());
	// 이분탐색 같음 -> 모든 랜선 중 가장 길이가 짧은게 e, 1이상은 되어야 되니까 s = 1;
	// 특정 길이 기준으로 다 잘라보고 N개 이상 나오는지 확인. -> 만들어진다면 -> 더 긴 길이로 가능한지.
	ll s{1}, e{ maxLen };
	while (s <= e)
	{
		ll m = (s + e) >> 1;
		
		ll count = 0;
		for (ll lan : lanList)
			count += lan / m;

		if (count >= N) // 목표 달성했다면 -> 길이 늘려
		{
			answer = m;
			s = m + 1;
		}
		else
			e = m - 1;
	}

	cout << answer << '\n';
	return 0;
}