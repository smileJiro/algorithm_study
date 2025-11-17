#include <bits/stdc++.h>

using namespace std;

int A, B;
int answer = 1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B;

	while (A < B)
	{
		if (B % 10 == 1)
			B /= 10; // 1»©±â
		else if (B % 2 == 0)
			B /= 2;
		else
		{
			answer = -1;
			break;
		}
		++answer;
	}
	if (A != B)
		answer = -1;
	cout << answer << '\n';
	return 0;
}