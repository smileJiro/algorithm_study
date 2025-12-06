#include<bits/stdc++.h>
using namespace std;

int N, M;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	string  S;
	cin >> S;
	int answer = 0;
	int cnt = 0;

	// IOI 자체가 하나의 패턴이야 -> 해당 패턴의 연속 등장 횟수를 카운팅하고
	// 카운트가 내가 목표로하는 N보다 크다면, answer를 증가시킨다.
	for (int i = 1; i < M - 1; )
	{
		if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I')
		{
			++cnt;

			if (cnt >= N)
				++answer;

			i += 2;
		}
		else
		{
			cnt = 0;
			i += 1;
		}
	}

	cout << answer << '\n';
	return 0;
}