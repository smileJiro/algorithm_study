#include<bits/stdc++.h>

using namespace std;
int Factorial_Recursive(int _number)
{
	if (0 == _number)
		return 1;

	return _number * Factorial_Recursive(_number - 1);
}
int main()
{
	int n;
	cin >> n;
	int result = Factorial_Recursive(n);

	cout << result;
	return 0;
}