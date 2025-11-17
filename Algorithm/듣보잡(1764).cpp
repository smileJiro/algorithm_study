#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;


int N, M;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	unordered_set<string> listenList;
	for (int i = 0; i < N; ++i)
	{
		string name;
		cin >> name;
		listenList.emplace(name);
	}

	vector<string> answer;
	for (int i = 0; i < M; ++i)
	{
		string name;
		cin >> name;
		if (listenList.end() != listenList.find(name))
		{
			// 존재한다면 듣보잡임
			answer.emplace_back(name);
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (auto& name : answer)
		cout << name << '\n';
	return 0;
}