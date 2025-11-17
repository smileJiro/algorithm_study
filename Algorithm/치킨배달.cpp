#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

vector<P> chicken;
vector<P> home;
int chickenSize;
int homeSize;
int N, M;

int getDistance(P h, P c)
{
	return abs(h.first - c.first) + abs(h.second - c.second);
}

int getTotalChickenDistance(const vector<int> list)
{
	vector<int> chickenDist(homeSize, 1e9);
	for (int c : list)
	{
		for (int h = 0; h < homeSize; ++h)
		{
			chickenDist[h] = min(chickenDist[h], getDistance(home[h], chicken[c]));
		}
	}
	
	int sum = 0;
	for (int dist : chickenDist)
		sum += dist;
	return sum;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int num;
			cin >> num;
			if (num == 1)
				home.emplace_back(i, j);
			else if (num == 2)
				chicken.emplace_back(i, j);

		}
	}
	chickenSize = chicken.size();
	homeSize = home.size();
	
	vector<int> mask(chickenSize, 0);
	fill(mask.begin(), mask.begin() + M, 1);
	int answer = 1e9;
	vector<int> select(M);
	do
	{
		int selectCnt = 0;
		for (int i = 0; i < chickenSize; ++i)
		{
			if (mask[i] == 1)
				select[selectCnt++] = i;
		}
		answer = min(answer, getTotalChickenDistance(select));
	} while (prev_permutation(mask.begin(), mask.end()));

	cout << answer << '\n';
	return 0;
}