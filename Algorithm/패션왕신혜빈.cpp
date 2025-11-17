#include <bits/stdc++.h>

using namespace std;

int T, N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	
	
	while (T--)
	{
		unordered_map<string, int> typeCounts;
		cin >> N; // 의상 인풋
		// 핵심은 종류다. 각 의상 종류별 숫자를 카운팅하고, 
		// (종류 수 + 1) : 안입는 경우포함 
		// (모자 수 + 1) * (상의 수 + 1) ..... - 1;
		// 의상 종류는 최대 30개이다. 의상 수 자체가 30개가 제한이니까.
		for (int i = 0; i < N; ++i)
		{
			string tmp, type;
			cin >> tmp >> type;
			++typeCounts[type];
		}

		int answer = 1;
		for (auto& [type, cnt] : typeCounts)
			answer *= cnt + 1;

		cout << answer - 1 << '\n';
	}
	
	

	return 0;
}