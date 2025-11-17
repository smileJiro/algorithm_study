#include<bits/stdc++.h>

using namespace std;
int n = 1;
int result = 0;
constexpr int limit = 14;
int possible[limit][limit] = {}; // 0일때 배치 가능
int dirX[] { -1, 0, 1 };
int dirY[] { 1, 1, 1 };

void CheckQueenAttackArea(int y, int x, int count)
{
	int dx = x;
	int dy = y;
	possible[y][x] += count;
	for (int i = 0; i < 3; ++i)
	{
		dx = x + dirX[i];
		dy = y + dirY[i];
		while (0 <= dx && dx < n && 0 <= dy && dy < n)
		{
			possible[dy][dx] += count;
			dx = dx + dirX[i];
			dy = dy + dirY[i];
			
		}
	}
}

void Backtracking(int depth)
{
	// 1. 성공 조건 : depth == n (depth는 행의 깊이를 말한다.)
	if (depth == n)
	{
		++result;
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (0 == possible[depth][i])
		{
			/* 재귀 조건 : 배치 가능한 곳이 남아 있다면, 해당 구간에 배치를 가정하고 퀸의 공격 범위를 체크 */
			// 퀸 공격 범위 1증가 처리
			CheckQueenAttackArea(depth, i, 1);
			// depth 증가 후 재귀 호출 수행
			Backtracking(depth + 1);
			// 퀸 공격 범위 1감소 처리
			CheckQueenAttackArea(depth, i, -1);
		}
	}
}

int main()
{
	cin >> n;
	Backtracking(0);

	cout << result;
	return 0;
}