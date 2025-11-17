#include <bits/stdc++.h>

using namespace std;

int notebook[42][42];
int sticker[12][12];
int n, m, k;
int r, c;
void Rotation()
{
	int rot[12][12] = {};
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			rot[j][r - 1 - i] = sticker[i][j];

	swap(r, c);
	// 회전한 스티커 복사
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			sticker[i][j] = rot[i][j];

	
}

bool isAttach(int rowPos, int colPos)
{
	/* 입력 : 스티커의 시작 인덱스 */
	/* 노트북 인덱스 = {i + rowPos, j + colPos} */
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (1 == sticker[i][j] && 1 == notebook[i + rowPos][j + colPos])
				return false;

	// 노트북에 붙이자.
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if(sticker[i][j] == 1)
				notebook[i + rowPos][j + colPos] = 1;

	//memset(sticker, 0, sizeof(sticker)); 스티커 모양 디버깅용

	return true;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	/* input */
	cin >> n >> m >> k;
	while (k--)
	{
		cin >> r >> c;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				cin >> sticker[i][j];

		for (int rot = 0; rot < 4; ++rot)					/* 1. 스티커를 노트북에 붙일 수 있는지 확인 */
		{
			bool is_Attach = false;							
			for (int i = 0; i <= n - r; ++i)
			{
				if (is_Attach)
					break;
				for (int j = 0; j <= m - c; ++j)
					if (is_Attach = isAttach(i, j))
						break;
			}
			if (is_Attach)
				break;
			Rotation();									  /* 2. 붙일 위치를 찾지 못했다면, 회전 수행하고 다시 검사 */
		}
	}
	

	/* 결과 정산 */
	int count = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			count += notebook[i][j];

	cout << count;
}
// 흐름대로 구현하자.
// 1. 입력 받은 스티커를 노트북 좌상단부터 붙일 수 있는지 확인한다.
// 2. 붙일 수 있다면 붙인다
// 3. 붙일 수 없다면 90도 회전한다.(스티커 인덱스 범위 잘 변경) -> 2번과정을 다시 반복한다. 회전은 총 3번 검사는 4번 모두 못붙인다면 버린다.

// 모든 스티커를 해당 과정을 반복한다.


// 결과 정산