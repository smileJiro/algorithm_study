#include <bits/stdc++.h>

using namespace std;

#define MAXIDX 8
enum DIR { T, R, D, L, LAST };
int dirX[LAST] = { 0, 1, 0, -1 };
int dirY[LAST] = { -1, 0, 1, 0 };

int field[9][9] = {};
using P = pair<int, int>; // x, y
int minCount = 1e9;
int n, m;
void ray(P cctv, DIR ray, int plus)
{
	int x{ cctv.first }, y{ cctv.second };
	if (0 > x || m <= x || 0 > y || n <= y)
		return;
	while (true)
	{
		x = x + dirX[ray];
		y = y + dirY[ray];
		if (0 > x || m <= x || 0 > y || n <= y)
			break;

		if (field[y][x] == 6)
			return;
		else if (field[y][x] < 6)
		{
			continue;
		}
		else
		{
			field[y][x] += plus;
		}
		
	}
}
void checkCCTV(P cctv, DIR direction, int plus)
{
	int x = cctv.first;
	int y = cctv.second;
	
	if (field[y][x] == 1)
	{
		ray(cctv, direction, plus);
	}
	else if (field[y][x] == 2)
	{
		if (direction == T)
		{
			ray(cctv, T, plus);
			ray(cctv, D, plus);
		}
		else if (direction == R)
		{
			ray(cctv, R, plus);
			ray(cctv, L, plus);
		}
	}
	else if (field[y][x] == 3)
	{
		ray(cctv, direction, plus);
		if(direction + 1 == LAST)
			ray(cctv, T, plus);
		else
			ray(cctv, DIR((int)direction + 1), plus);
		
	}
	else if(field[y][x] == 4)
	{
		if (direction == T)
		{
			ray(cctv, L, plus);
			ray(cctv, T, plus);
			ray(cctv, R, plus);
		}
		else if (direction == R)
		{
			ray(cctv, T, plus);
			ray(cctv, R, plus);
			ray(cctv, D, plus);
		}
		else if (direction == D)
		{
			ray(cctv, R, plus);
			ray(cctv, D, plus);
			ray(cctv, L, plus);
		}
		else if (direction == L)
		{
			ray(cctv, D, plus);
			ray(cctv, L, plus);
			ray(cctv, T, plus);
		}
	}
	else
	{
		ray(cctv, T, plus);
		ray(cctv, R, plus);
		ray(cctv, D, plus);
		ray(cctv, L, plus);
	}
	
}
void computeBlindspotCount(vector<P>& cctvs, int curIdx)
{
	// 재귀 탈출 : 인덱스 벗어난 경우 for문에서
	int numCCTVs = cctvs.size();
	if (numCCTVs == curIdx)
	{
		// CCTV 전부 검사했다. -> minCount 갱신
		int blindSpotCount = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (field[i][j] == 7)
					++blindSpotCount;
			}
		}
		if (blindSpotCount < minCount)
			minCount = blindSpotCount;

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		// cctv 감시 범위를 +1
		checkCCTV(cctvs[curIdx], (DIR)i, 1);
		// 그 후, 다음 cctv에 대해서 재귀 호출
		computeBlindspotCount(cctvs, curIdx + 1);
		// 다시 -1
		checkCCTV(cctvs[curIdx], (DIR)i, -1);
	}
}
int main()
{
	for (int i = 0; i < MAXIDX; ++i)
	{
		for (int j = 0; j < MAXIDX; ++j)
		{
			field[i][j] = 7;
		}
	}

	cin >> n >> m;

	
	vector<P> cctvs;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int k = 0;
			cin >> k;
			if(k != 0)
			{
				field[i][j] = k;
				if(1 <= k && 5 >= k)
					cctvs.emplace_back(j, i);
			}
			
		}
	}
	
	computeBlindspotCount(cctvs, 0);

	cout << minCount << '\n';
	return 0;
}