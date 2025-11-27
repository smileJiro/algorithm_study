#pragma region MyAnswer 552ms
#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>; // y, x
constexpr int BOARD_SIZE = 9;
// 백트래킹 구현을 생각해볼수있다.
// 비어있는 노드를 저장하고,
// 비어있는 노드에 대해서 백트래킹을 수행하며, 조건을 만족하는 답을 찾아야한다.
// 마지막 노드까지 이상 없이 조건을 만족했다면, 성공 

int board[BOARD_SIZE][BOARD_SIZE];

bool ColCheck(int y, int x)
{
	for (int row = 0; row < BOARD_SIZE; ++row)
	{
		if (row == y)
			continue;

		if (board[row][x] == board[y][x])
			return false;
	}
	return true;
}
bool RowCheck(int y, int x)
{
	for (int col = 0; col < BOARD_SIZE; ++col)
	{
		if (col == x)
			continue;

		if (board[y][col] == board[y][x])
			return false;
	}
	return true;
}
bool BoxCheck(int y, int x)
{
	int sx = x / 3 * 3;
	int sy = y / 3 * 3;

	for (int i = sy; i < sy + 3; ++i)
	{
		for (int j = sx; j < sx + 3; ++j)
		{
			if (i == y && j == x)
				continue;

			if (board[i][j] == board[y][x])
				return false;
		}
	}

	return true;
}
bool BackTracking(vector<P>& emptyNodes, int idx)
{
	if (idx == emptyNodes.size())
		return true;

	auto& [y, x] = emptyNodes[idx];
	for (int i = 1; i <= BOARD_SIZE; ++i)
	{
		board[y][x] = i;
		// 조건 검사
		if (!ColCheck(y, x))
			continue;
		if (!RowCheck(y, x))
			continue;
		if (!BoxCheck(y, x))
			continue;

		if (BackTracking(emptyNodes, idx + 1))
			return true;
	}

	board[y][x] = 0;
	return false;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<P> emptyNodes;
	emptyNodes.reserve(BOARD_SIZE * BOARD_SIZE);

	string str = "";
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		cin >> str;
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			board[i][j] = str[j] - '0';

			if (board[i][j] == 0)
				emptyNodes.emplace_back(i, j);
		}
	}

	BackTracking(emptyNodes, 0);

	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}
	return 0;
}
#pragma endregion



#pragma region OtherAnswer(Used배열을 통해서 검사 로직 단순화) 152ms
//#include <bits/stdc++.h>
//using namespace std;
//
//using P = pair<int, int>; // y, x
//constexpr int BOARD_SIZE = 9;
//
//int board[BOARD_SIZE][BOARD_SIZE];
//// rowUsed[r][v] : r행에 숫자 v가 이미 쓰였는가
//// colUsed[c][v] : c열에 숫자 v가 이미 쓰였는가
//// boxUsed[b][v] : b번 박스(0~8)에 숫자 v가 이미 쓰였는가
//bool rowUsed[BOARD_SIZE][10];
//bool colUsed[BOARD_SIZE][10];
//bool boxUsed[BOARD_SIZE][10];
//
//bool BackTracking(vector<P>& emptyNodes, int idx)
//{
//	if (idx == (int)emptyNodes.size())
//		return true;
//
//	auto [y, x] = emptyNodes[idx];
//	int boxIdx = (y / 3) * 3 + (x / 3);
//
//	for (int v = 1; v <= 9; ++v)
//	{
//		if (rowUsed[y][v]) continue;
//		if (colUsed[x][v]) continue;
//		if (boxUsed[boxIdx][v]) continue;
//
//		// 상태 적용
//		board[y][x] = v;
//		rowUsed[y][v] = true;
//		colUsed[x][v] = true;
//		boxUsed[boxIdx][v] = true;
//
//		if (BackTracking(emptyNodes, idx + 1))
//			return true;
//
//		// 롤백
//		board[y][x] = 0;
//		rowUsed[y][v] = false;
//		colUsed[x][v] = false;
//		boxUsed[boxIdx][v] = false;
//	}
//
//	return false;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	vector<P> emptyNodes;
//	emptyNodes.reserve(BOARD_SIZE * BOARD_SIZE);
//
//	string str;
//	for (int i = 0; i < BOARD_SIZE; ++i)
//	{
//		cin >> str;
//		for (int j = 0; j < BOARD_SIZE; ++j)
//		{
//			int v = str[j] - '0';
//			board[i][j] = v;
//
//			if (v == 0)
//			{
//				emptyNodes.emplace_back(i, j);
//			}
//			else
//			{
//				rowUsed[i][v] = true;
//				colUsed[j][v] = true;
//				int boxIdx = (i / 3) * 3 + (j / 3);
//				boxUsed[boxIdx][v] = true;
//			}
//		}
//	}
//
//	BackTracking(emptyNodes, 0);
//
//	for (int i = 0; i < BOARD_SIZE; ++i)
//	{
//		for (int j = 0; j < BOARD_SIZE; ++j)
//			cout << board[i][j];
//		cout << '\n';
//	}
//
//	return 0;
//}

#pragma endregion
