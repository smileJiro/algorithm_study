#include <bits/stdc++.h>

using namespace std;

/* 백트래킹 사용해서 풀거야 */
/* 1방향 직선을 검사하는 함수() */
/* 백트래킹 수행하며 최소값을 갱신하는 함수() */
using CCTV = pair<int, int>;
int n, m;
int field[10][10];
vector<CCTV> cctvs;
int result = 1e9;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
bool OOB(int a, int b)
{
	return a < 0 || a >= n || b < 0 || b >= m;
}
void Watch(const int r, const int c, int dir, const int plus)
{
	dir = dir % 4;
	int x = c + dx[dir];
	int y = r + dy[dir];
	while (!OOB(y, x))
	{
		if (field[y][x] == 6)
			break;
		else if (field[y][x] >= 7)
			field[y][x] += plus;

		x += dx[dir];
		y += dy[dir];
	}
}
void CheckCCTV(const int r, const int c, const int dir, const int plus)
{
	int type = field[r][c];

	if (type == 1)
	{
		Watch(r, c, dir, plus);
	}
	else if (type == 2)
	{
		Watch(r, c, dir, plus);
		Watch(r, c, dir + 2, plus);
	}
	else if (type == 3)
	{
		Watch(r, c, dir, plus);
		Watch(r, c, dir + 1, plus);
	}
	else if (type == 4)
	{
		Watch(r, c, dir, plus);
		Watch(r, c, dir + 1, plus);
		Watch(r, c, dir + 2, plus);
	}
	else if (type == 5)
	{
		Watch(r, c, dir, plus);
		Watch(r, c, dir + 1, plus);
		Watch(r, c, dir + 2, plus);
		Watch(r, c, dir + 3, plus);
	}
}
void Backtracking(int curIdx)
{
	int numCCTVs = cctvs.size();
	if (numCCTVs == curIdx)
	{
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (field[i][j] == 7)
					++count;
			}
		}

		// result 정산
		result = min(result, count);
		return;
	}
	int r = cctvs[curIdx].first;
	int c = cctvs[curIdx].second;
	for (int dir = 0; dir < 4; ++dir)
	{
		CheckCCTV(r, c, dir, 1);
		Backtracking(curIdx + 1);
		CheckCCTV(r, c, dir, -1);
	}

	
	
	/* 1. cctv 리스트를 확인 후 cctv의 4방향에 대한 처리를 수행한다. */
	/* 2. 다음 cctv를 재귀호출한다. */
	/* 3. 재귀 호출이 반환되면 4방향 처리를 초기화한다. */
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	/* 1. 맵을 입력받는다. + cctv 리스트를 만든다.*/
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int value{};
			cin >> value;
			if (value == 0)
				value = 7;
			else if (value <= 5)
				cctvs.emplace_back(i, j);

			field[i][j] = value;
		}
	}
	/* 2. cctv 리스트를 순회하면서 백트래킹을 수행한다.*/
	Backtracking(0);

	/* 3. 결과를 리턴한다. */
	cout << result;
	return 0;
}