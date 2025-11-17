#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main_two_pointer2()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		int SK{}, SY{};
		cin >> SK >> SY;
		if (0 == SK && 0 == SY)
			break;

		vector<int> vecSK(SK);

		for (int i = 0; i < SK; ++i)
			cin >> vecSK[i];

		int idx{}, value{}, countCD{};
		for (int i = 0; i < SY; ++i)
		{
			cin >> value;
			while (idx < SK && vecSK[idx] < value)
			{
				++idx;
			}
			if (value == vecSK[idx])
				++countCD;
		}
		cout << countCD << '\n';
	}
}

/* two-pointer */
int main_two_pointer()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		int SK{}, SY{};
		cin >> SK >> SY;
		if (0 == SK && 0 == SY)
			break;

		vector<int> vecSK(SK);
		vector<int> vecSY(SY);

		for (int i = 0; i < SK; ++i)
			cin >> vecSK[i];
		for (int i = 0; i < SY; ++i)
			cin >> vecSY[i];


		int i{}, j{}, countCD{};
		while (i < SK && j < SY)
		{
			if (vecSK[i] == vecSY[j])
			{
				++i; ++j; ++countCD;
			}
			else if (vecSK[i] < vecSY[j])
			{
				++i;
			}
			else
			{
				++j;
			}
		}

		cout << countCD << '\n';
	}
}

/* unordered_set */
int main_unordered_set()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		unordered_set<int> uset_SK;
		uset_SK.reserve(1000000);
		int numSK, numSY;
		cin >> numSK >> numSY;
		if (numSK == 0 && numSY == 0)
			break;

		static int numInsert;
		for (int i = 0; i < numSK; ++i)
		{
			cin >> numInsert;
			uset_SK.insert(numInsert);
		}

		int sellCount = 0;
		for (int i = 0; i < numSY; ++i)
		{
			cin >> numInsert;
			if (uset_SK.find(numInsert) != uset_SK.end())
				++sellCount;
		}

		cout << sellCount << "\n";
	}

	return 0;
}