#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using P = pair<int, int>;
int N;
struct Compare
{
	bool operator()(P a, P b)
	{
		if (a.second == b.second)
			return a.first > b.first;

		return a.second > b.second;
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	priority_queue <P, vector<P>, Compare> pq;
	for (int i = 0; i < N; ++i)
	{
		int s, e, time;
		cin >> s >> e;
		pq.emplace(s, e);
	}


	int answer = 0;
	int curEnd = 0; // 현재 기준 마지막 회의 종료시간.
	while (!pq.empty())
	{
		auto [s, e] = pq.top(); pq.pop();
		
		if (s >= curEnd)
		{
			++answer;
			curEnd = e;
		}
	}
		
	cout << answer << '\n';
	return 0;
}