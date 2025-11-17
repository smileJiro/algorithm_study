#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int N, K;
int visited[100001];
int main()
{
	cin >> N >> K;

	if (N >= K) // 동생이 더 앞에 있는 경우는 -1 이동만 가능
	{
		cout << N - K << '\n';
		return 0;
	}

	// bfs 사용 -> 간선의 가중치는 동일 다만 연산의 방식에 차이가 있음.
	queue<pair<int, int>> q;
	q.emplace(N, 0);
	while (!q.empty())
	{
		auto [curvalue, curlevel] = q.front(); q.pop();
		if (curvalue == K)
		{
			cout << curlevel << '\n';
			return 0;
		}

		curlevel += 1;
		for (int i = 0; i < 3; ++i)
		{
			int newValue = curvalue;
			if (i == 0)
				newValue += 1;
			else if (i == 1)
				newValue -= 1;
			else
				newValue *= 2;

			if (0 <= newValue && 100001 > newValue && visited[newValue] == 0)
			{
				visited[newValue] = 1;
				q.emplace(newValue, curlevel);
			}
		}
	}
	return 0;
}