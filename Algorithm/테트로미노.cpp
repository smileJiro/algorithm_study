#include <bits/stdc++.h>

using namespace std;

int N, M;
int board[502][502];
int Rot[502][502]; // 회전용
void Rotation()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			Rot[j][N - 1 - i] = board[i][j]; // 직사각형 회전 -> 시계방향
	}

	
	memcpy(board, Rot, sizeof(board));
	swap(N, M);
}
int getMax(const vector<vector<int>>& tet)
{
	int rowSize = tet.size();
	int colSize = tet[0].size();
	
	int answer = 0;
	for (int rot = 0; rot < 4; ++rot)
	{
		// 1. 검사 수행
		for (int i = 0; i <= N - rowSize; ++i)
		{
			for (int j = 0; j <= M - colSize; ++j)
			{
				int sum = 0;
				for (int tetR = 0; tetR < rowSize; ++tetR)
				{
					for (int tetC = 0; tetC < colSize; ++tetC)
					{
						if (tet[tetR][tetC] == 1)
						{
							int ny = tetR + i;
							int nx = tetC + j;
							sum += board[ny][nx];
						}
					}
				}
				// 1개 검사 끝 tet 검사
				answer = max(answer, sum);
			}
		}

		// 2. 회전
		Rotation();
	}
	return answer;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}

	vector<vector<int>> tet1 = { {1,1,1,1} };
	vector<vector<int>> tet2 = { {1,1} ,
								 {1,1} };
	vector<vector<int>> tet3 = { {1,1,1} ,
								 {1,0,0} };
	vector<vector<int>> tet4 = { {0,1,1} ,
								 {1,1,0} };
	vector<vector<int>> tet5 = { {1,1,1},
								 {0,1,0} };
	vector<vector<int>> tet6 = { {1,1,1} ,
								 {0,0,1} };
	vector<vector<int>> tet7 = { {1,1,0} ,
								 {0,1,1} };
	// 1. board에 해당 모형으로 1칸씩 이동하면서 최대 값을 구한다.
	// 2. board를 시계방향으로 회전 시킨 후 다시 검사한다. // 검사 4번 + 4번 회전
	int answer = 0;
	answer = max(answer, getMax(tet1));
	answer = max(answer, getMax(tet2));
	answer = max(answer, getMax(tet3));
	answer = max(answer, getMax(tet4));
	answer = max(answer, getMax(tet5));
	answer = max(answer, getMax(tet6));
	answer = max(answer, getMax(tet7));

	cout << answer << '\n';
	return 0;
}