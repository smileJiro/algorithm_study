#include <bits/stdc++.h>

using namespace std;

// 여섯 방향에 대한 힘(가중치)을 계산한다.
// 삼각형이 생성할때에는 여섯 방향 중 가장 힘이 쎈 방향으로 생성된다.
// 방향의 힘이 생성되는 삼각형 수의 크기이다.
// 특정방향으로 삼각형 생성 시 해당 삼각형의 다른 변 두개의 방향에 힘이 추가된다.
// 생성된 방향은 힘을 감소시킨다.
enum DIRECTION { T, RT, RB, D, LB, LT, LAST };
int Test, N;
long long arr[101] = {};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> Test;

	// 기본 삼각형 추가
	long long dirPower[LAST] = { 0, 1, 0, 1, 0, 1 };
	int testCnt = 100;
	arr[1] = 1;
	for (int i = 2; i <= testCnt; ++i)
	{
		int dir = 0;
		long long maxValue = 0;
		for (int i = 0; i < DIRECTION::LAST; ++i) // 삼각형 진행 방향 설정
		{
			if (maxValue < dirPower[i])
			{
				maxValue = dirPower[i];
				dir = i;
			}
		}
		// 방향 정보 업데이트
		arr[i] = maxValue;
		int left = (dir + 1) % (int)DIRECTION::LAST;
		int right = (dir + 5) % (int)DIRECTION::LAST;
		dirPower[left] += dirPower[dir];
		dirPower[right] += dirPower[dir];
		dirPower[dir] = 0;
	}

	while (Test--)
	{
		cin >> N;
		cout << arr[N] << '\n';
	}

	return 0;
}