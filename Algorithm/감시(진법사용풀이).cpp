#include<bits/stdc++.h>
using namespace std;

// 가능한 방향의 종류가 4개이니 4진법 사용한다.
// 1번 카메라가 3개일 때, 0부터 63까지의 수를 4진법으로 나타내면 각 자리수마다 카메라 1대의 방향정보가 결정된다.
// 카메라 인덱스가 등장하면, 해당 카메라 타입의 4방향 감시 범위에 대한 테이블을 만든다.
// 그 후 모든 경우의 수를 결정할때, 각 자리수에 해당하는 카메라 인덱스에 따라서 테이블 참조 후 기존 맵에 다 더한다.

using Camera = pair<int, int>;
#define MAXIDX 8
int field[MAXIDX][MAXIDX]{};
int n{}, m{};

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
bool isWatch[5][4] = { {1,0,0,0}, {1, 0, 1, 0}, {1, 1, 0, 0}, { 1, 1, 0, 1 }, {1, 1, 1, 1} };
void getAreaList(vector<vector<vector<int>>>& areaList, Camera cameraIdx)
{
	// 1. 카메라 타입 확인
	Camera curCamera = cameraIdx;
	int cameraType = field[curCamera.first][curCamera.second] - 1;
	// 2. 4방향에 대한 감시 영역 체크
	for (int i = 0; i < 4; ++i)
	{
		vector<vector<int>> watchArea(MAXIDX, vector<int>(MAXIDX, 0));
		for (int d = 0; d < 4; ++d) // 다른 카메라 타입에 따라 봐야할 곳 
		{
			curCamera = cameraIdx;
			if (isWatch[cameraType][d])
			{
				// 감시 해야한다.
				int watchDir = (i + d) % 4;
				curCamera.first += dy[watchDir];
				curCamera.second += dx[watchDir];
				
				while (0 <= curCamera.first && n > curCamera.first && 0 <= curCamera.second && m > curCamera.second)
				{
					// 유효한 인덱스라면 해당 워치 인덱스를 1로 변경
					if (6 == field[curCamera.first][curCamera.second])
						break;
					else if (7 <= field[curCamera.first][curCamera.second])
						watchArea[curCamera.first][curCamera.second] = 1;

					curCamera.first += dy[watchDir];
					curCamera.second += dx[watchDir];
				}
			}
		}
		areaList[i] = watchArea;
	}

}
int main()
{
	cin >> n >> m;

	vector<Camera> cameras;
	/* 1. 필드 구성 + 카메라 목록 저장*/
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int k{};
			cin >> k;
			if (0 == k)
				field[i][j] = 7;
			else 
			{
				if (5 >= k)
					cameras.emplace_back(i, j); // (y,x);

				field[i][j] = k;
			}
		}
	}

	vector<vector<vector<vector<int>>>> watchTable; // 카메라 인덱스(자리수), 2차원 배열 상태
	int numCameras = cameras.size();
	for (auto& camera : cameras)
	{
		vector<vector<vector<int>>> watchAreaList(4, vector<vector<int>>(MAXIDX, vector<int>(MAXIDX, 0))); // 카메라당 4방향 정보 저장
		getAreaList(watchAreaList, camera);
		watchTable.push_back(watchAreaList);
		// watchTable[자릿수][방향인덱스] = 결과 필드;
	}

	// 경우의 수 계산 4방향이니 일단 4진법, 카메라 개수만큼 제곱
	int caseCount = 1;
	for (int i = 0; i < numCameras; ++i)
		caseCount *= 4;
	
	// 4진법 분해하며 결과 테이블 모두 합산 후 0 갯수 세기
	int minResult = 1e9;
	for (int i = 0; i < caseCount; ++i)
	{
		vector<vector<int>> resultFiled(MAXIDX, vector<int>(MAXIDX, 0));
		int num = i;
		int devide{}, mod{};
		for (int j = 0; j < numCameras; ++j)
		{
			devide = num / 4; // 나눈 값 저장.
			mod = num % 4;
			num = devide;

			for (int row = 0; row < MAXIDX; ++row)
			{
				for (int col = 0; col < MAXIDX; ++col)
				{
					resultFiled[row][col] += watchTable[j][mod][row][col];
				}
			}
		}
		
		int curCount = 0;
		for (int row = 0; row < n; ++row)
		{
			for (int col = 0; col < m; ++col)
			{
				if (0 == resultFiled[row][col] && field[row][col] == 7)
				{
					++curCount;
				}
			}
		}
		minResult = min(minResult, curCount);
	}

	cout << minResult;
	return 0;
}