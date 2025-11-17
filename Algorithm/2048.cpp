#include <bits/stdc++.h>

using namespace std;
int board[22][22];
int n;
int result;
bool OOB(int y, int x)
{
	return 0 > y || 0 > x || n <= y || n <= x;
}
void Rotation()
{
	int temp[22][22];
	memcpy(temp, board, sizeof(board));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			board[i][j] = temp[n - 1 - j][i];
		}
	}
	
}
void CombineLine(int row)
{
	int temp[22] = {};
	int idx = 0;
	for (int i = 0; i < n; ++i)
	{
		if (board[row][i] == 0)
			continue;
		else
		{
			if (temp[idx] == 0)
				temp[idx] = board[row][i];
			else if (temp[idx] == board[row][i])
				temp[idx++] *= 2;
			else
				temp[++idx] = board[row][i];
		}
	}
	memcpy(board[row], temp, sizeof(temp));

}

void Action(int dir)
{
	for (int i = 0; i < n; ++i)
	{
		CombineLine(i);
	}
	
}
void BackTracking(int level)
{
	if (level == 5)
	{
		// 최대 인덱스 탐색
		int maxValue = 0;
		for(int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				maxValue = max(maxValue, board[i][j]);
			}
		}
		result = max(result, maxValue);
		return;
	}
	// 1. 상하좌우 4가지 경우의 수

	for (int i = 0; i < 4; ++i)
	{
		int temp[22][22] = {};
		memcpy(temp, board, sizeof(board)); // 저장
		for (int j = 0; j < i; ++j)
			Rotation();
		Action(i); // 실행
		for (int j = 0; j < 4 - i; ++j)
			Rotation();
		BackTracking(level + 1); // 다음 행동
		memcpy(board, temp, sizeof(board)); // 복원
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	}
	// 백트래킹을 통해 모든 경우의 수 중 원소의 값이 가장 큰 것을 반환.
	BackTracking(0);

	cout << result;
	return 0;
}