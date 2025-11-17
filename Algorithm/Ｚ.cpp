#include <bits/stdc++.h>

using namespace std;

int N, tR, tC;

int answer = 0;

void dfs(int y, int x, int size)
{
	if (tR == y && tC == x) // 타겟을 만났다.
	{
		cout << answer; // 지금까지 더한 모든 값이 tR, tC의 순서
		return;
	}
	else if (tR >= y && tC >= x && tR < y + size && tC < x + size)
	{
		int nSize = size / 2;
		dfs(y, x, nSize);
		dfs(y, x + nSize, nSize);
		dfs(y + nSize, x, nSize);
		dfs(y + nSize, x + nSize, nSize);
	}
	else
	{
		// 현재 사분면에 없다면, 넓이 추가.
		answer += size * size;
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> tR >> tC;

	int n = 2;
	for (int i = 1; i < N; ++i)
		n *= 2;

	// 0. 현재 인덱스가 tR, tC 면 탈출
	// 1. tR, tC가 범위 안에 속하는지 검사한다. 
	//   속한다면 -> 현재 사각형을 4개의 사분면으로 나눈다. 
	//   속하지 않는다면 answer에 넓이를 더한다. 해당 넓이 이상의 값을 가지니까.
	dfs(0, 0, n);
	

	return 0;
}