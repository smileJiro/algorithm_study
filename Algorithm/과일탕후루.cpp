#include <bits/stdc++.h>

using namespace std;

int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	// 투포인터 풀이
	vector<int> tanghulu(N);
	for (int i = 0; i < N; ++i)
		cin >> tanghulu[i];

	vector<int> counts(10, 0);
	int numTypes = 0;
	int answer = 0;
	int l{0};
	for (int r = 0; r < N; ++r)
	{
		if (0 == counts[tanghulu[r]]++) // 만약 처음 들어온 과일이라면,
			++numTypes;

		while (2 < numTypes) // 과일 종류가 2개가 넘는다면,
		{
			if (0 == --counts[tanghulu[l]])
				--numTypes;
			++l;
		}

		answer = max(answer, r - l + 1);
	}

	/*queue<int> tanghulu;
	vector<int> counts(10);
	int numTypes = 0;
	int answer = 0;
	for (int i = 0; i < N; ++i)
	{
		int fruit = 0;
		cin >> fruit;
		tanghulu.push(fruit);
		if (0 == counts[fruit]++)
			numTypes += 1;
		
		while (2 < numTypes)
		{
			int popfruit = tanghulu.front(); tanghulu.pop();
			if (--counts[popfruit] == 0)
				numTypes -= 1;
		}
		answer = max(answer, (int)tanghulu.size());
	}*/
		
	cout << answer << '\n';

	return 0;
}