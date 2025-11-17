#include <bits/stdc++.h>

using namespace std;

string strMathExp = "";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> strMathExp;
	int answer = 0;
	
	int sign = 1;
	string number = "";
	for (char c : strMathExp)
	{
		if (isdigit(c))
			number += c;
		else
		{
			answer += stoi(number) * sign;
			number.clear();
			if (c == '-') sign = -1;
		}
	}
	answer += stoi(number) * sign;
	number.clear();

	cout << answer << '\n';
	return 0;
}