#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int result = str[0] - '0';
	for (int i = 1; i < str.size(); ++i)
	{
		int num = str[i] - '0';
		if (str[i] <= 1 || result <= 1)
			result += num;
		else
			result *= num;
	}
	
	cout << result << '\n';
	return 0;
}