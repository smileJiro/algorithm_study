#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int n;
int result;
bool isGroupWord(const string& str)
{
	int len = str.length();
	if (len <= 2)
		return true;

	int cur{};
	bool table[128] = {};
	table[str[cur]] = true;
	while (cur < len - 1)
	{
		if (table[str[cur + 1]])
		{
			if (str[cur] != str[cur + 1])
				return false;
		}
		else
		{
			table[str[cur + 1]] = true;
		}
		++cur;
	}
	return true;
}

bool isGroupWord2(const string& str)
{
	bool used[26] = {};
	char prev = 0;
	for (char c : str)
	{
		if (c != prev)
		{
			if (used[c - 'a'])
				return false;
			else
				used[c - 'a'] = true;
		}
		prev = c;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		if (isGroupWord2(str))
			++result;
	}

	cout << result << '\n';
	return 0;
}