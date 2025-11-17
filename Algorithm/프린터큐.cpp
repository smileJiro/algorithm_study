#include <bits/stdc++.h>

using namespace std;

using P = pair<int, int>;
int test, n, m;

int main()
{
	cin >> test;
	// 큐 채우기

	for (int i = 0; i < test; ++i)
	{
		cin >> n >> m;
		queue<P> printerQ;
		int priority[10] = {};
		int result = {};
		for (int j = 0; j < n; ++j)
		{
			int k;
			cin >> k;
			printerQ.emplace(j, k);
			priority[k] += 1;
		}

		// 큐에서 하나씩 빼면서 검사
		int priorityIdx = 9;
		while (!printerQ.empty())
		{
			while (0 == priority[priorityIdx]) // 우선순위 확인
				--priorityIdx;

			P cur = printerQ.front(); printerQ.pop();
			if (cur.second == priorityIdx) // 출력한다.
			{
				++result;
				priority[priorityIdx] -= 1;
				if (cur.first == m)
					break;
			}
			else
			{
				printerQ.push(cur);
			}
		}

		cout << result << '\n';
	}
	

	return 0;
}