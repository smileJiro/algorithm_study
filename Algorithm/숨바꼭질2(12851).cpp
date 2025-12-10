#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>; // num, level;

int N, K; // 수빈, 동생
int minTime; 
int cnt; 
// bfs
// 세 갈래로 계속 퍼트리면서 레벨 순회 수행한다.
// target을 찾았다면, 해당 레벨에 존재하는 모든 결과를 뒤진 후, 방법의 수도 기록

void BFS()
{
	queue<P> q;
	vector<int> levels(100001, 1e9);
	levels[N] = 0;
	q.emplace(N, 0);

	while (!q.empty())
	{
		auto [num, level] = q.front(); q.pop();

		if (num == K) 
		{
			// 결과 정산 로직
			minTime = level;
			cnt += 1;
			while (!q.empty())
			{
				auto [n, l] = q.front(); q.pop();
				if (l > minTime)
					break;
				if (n == K)
					cnt += 1;
			}
			break;
		}
		
		for (int i = 0; i < 3; ++i)
		{
			// 탐색 로직
			int next = num;
			if (i == 0)
				next += 1;
			else if (i == 1)
				next -= 1;
			else
				next *= 2;

			if (next < 0 || next > 100000)
				continue;

			if (levels[next] >= level + 1)
			{
				levels[next] = level + 1;
				q.emplace(next, level + 1);
			}
		}
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	if (N >= K) 
	{
		// 수빈이가 더 앞에 있는 경우
		cout << N - K << '\n' << 1 << '\n';
		return 0;
	}

	BFS();
	cout << minTime << '\n' << cnt << '\n';
	return 0;
}