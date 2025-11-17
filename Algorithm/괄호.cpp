#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string strInput;
		cin >> strInput;
		stack<char> stack;
		int j = 0;
		for (j; j < strInput.length(); ++j)
		{
			if ('(' == strInput[j])
				stack.push(strInput[j]);
			else if (')' == strInput[j])
			{
				if (true == stack.empty())
				{
					break;
				}
				stack.pop();
			}
		}

		if (false == stack.empty() || (true == stack.empty() && j < strInput.length()))
			cout << "NO" << "\n";
		else if(true == stack.empty())
			cout << "YES" << "\n";
	}


	return 0;
}