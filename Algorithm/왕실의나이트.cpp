#include<bits/stdc++.h>

using namespace std;

enum DIR { LU,LD, UL,UR, RU, RD, DL,DR, LAST };
int dx[LAST] = { -2, -2, -1, 1, 2, 2, -1, 1 };
int dy[LAST] = { -1, 1, -2, -2, -1, 1, 2, 2 };
int checkCount(string curPos)
{
	int col = curPos[0] - 'a';
	int row = curPos[1] - '1';
	int targetX{}, targetY{};
	int cnt = 0;
	for (int i = 0; i < LAST; ++i)
	{
		targetX = col + dx[i];
		targetY = row + dy[i];
		if (0 > targetX || 8 <= targetX ||
			0 > targetY || 8 <= targetY)
			continue;

		++cnt;
	}

	return cnt;
}
int main()
{
	string str;
	cin >> str;

	cout << checkCount(str) << '\n';
	return 0;
}