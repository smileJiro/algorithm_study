#include <bits/stdc++.h>

using namespace std;

int N, R, C;
int answer;
void Divide(int y, int x, int len)
{
	if (len == 1)
		return;
	int half = len / 2;
	int ny{y}, nx{x};
	int sector{0};
	if (R < y + half && C < x + half)
	{
		// 1 사분면
		sector = 1;
		ny = y; nx = x;
	}
	else if (R < y + half && C >= x + half)
	{
		// 2 사분면
		sector = 2;
		ny = y; nx = x + half;
	}
	else if (R >= y + half && C < x + half)
	{
		// 3 사분면
		sector = 3;
		ny = y+ half; nx = x;
	}
	else if (R >= y + half && C >= x + half)
	{
		// 4 사분면
		sector = 4;
		ny = y + half; nx = x + half;
	}
	answer += half * half * (sector - 1);
	Divide(ny, nx, half);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> R >> C;

	int len = 1;
	for (int i = 0; i < N; ++i)
		len *= 2;

	Divide(0, 0, len);

	cout << answer << '\n';
	return 0;
}