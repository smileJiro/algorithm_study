#include <bits/stdc++.h>

using namespace std;

int N, M;
int mask[10] = {};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	fill(mask, mask + M, 1);
	do
	{
		for (int i = 0; i < N; ++i)
		{
			if (mask[i] == 1)
				cout << i + 1 << ' ';
		}
		cout << '\n';
	} while (prev_permutation(mask, mask + N));
	return 0;
}