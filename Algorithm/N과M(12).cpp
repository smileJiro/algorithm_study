#include <bits/stdc++.h>

using namespace std;

// N 중 M개 고르고, 중복 가능하고, 수열 자체가 비내림차순이어야한다.
int N, M;
vector<int> sequence;
vector<int> print;
void printSequence(int level, int prevValue) // 재귀 구현
{
	if (level == M) // M개 골랐다는 의미
	{
		for (int i = 0; i < M; ++i)
			cout << print[i] << ' ';

		cout << '\n';
		return;
	}

	int prev = -1;
	for (int i : sequence)
	{
		if (prev != i)
		{
			if (prevValue <= i)
			{
				print[level] = i;
				printSequence(level + 1, i);
			}
			prev = i;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	sequence.resize(N);
	print.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> sequence[i];

	sort(sequence.begin(), sequence.end());
	printSequence(0, -1);


	return 0;
}