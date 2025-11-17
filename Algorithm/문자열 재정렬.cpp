#include <bits/stdc++.h>

using namespace std;

int main()
{
	string a;
	int n = 0;

	string str;
	cin >> str;

	for (char c : str)
	{
		if (isdigit(c))
			n += c - '0';
		else
			a += c;
	}

	sort(a.begin(), a.end());

	cout << a << n << '\n';
	return 0;
}