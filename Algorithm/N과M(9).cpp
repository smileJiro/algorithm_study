#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;


int N, M;
vector<int> numList;
vector<int> used;
int num[10]; // 최대 8개까지 사용
unordered_set<string> result;
void BackTracking(int level)
{
	if (level == M)
	{
		// 수열 개수 충족 했다면 출력
		string str;
		for (int i = 0; i < M; ++i)
		{
			str += to_string(num[i]);
			str += ' ';
		}
		if (result.end() == result.find(str))
		{
			cout << str << '\n';
			result.emplace(str);
		}
		return;
	}

	int size = numList.size();
	for (int i = 0; i < size; ++i)
	{
		if (!used[i])
		{
			used[i] = 1;
			num[level] = numList[i];
			BackTracking(level + 1);
			used[i] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	used.resize(N);
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		numList.push_back(num);
	}

	sort(numList.begin(), numList.end());
	int size = numList.size();

	BackTracking(0);
	return 0;
}