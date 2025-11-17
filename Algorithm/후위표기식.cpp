#include <bits/stdc++.h>
using namespace std;

// 후위 표기식 규칙
// 피연산자 -> 바로 출력
// 연산자는 우선순위에 따라 stack에 push, pop
// (는 예외 있어
// 연산자 우선 순위 + - >> * / >> ( )

// 연산자는 자기 자신이 stack의 top이 자기보다 우선순위가 낮아야해 -> 나보다 높은놈이면 먼저 가세요
// ( 는 현재 연산자가 ) 일때만 pop 그 외에는 절대 pop X
bool IsAlphabet(char c)
{
	int isAlphabet = c - 'A';
	return (0 <= isAlphabet) && (isAlphabet < 26);
}
int prec(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;

	return 0;
}
void Postfix(string& str)
{
	string answer;
	stack<char> operators;

	for (char c : str)
	{
		if (IsAlphabet(c))
			answer += c;
		else if (c == '(')
		{
			operators.push(c);
		}
		else if (c == ')')
		{
			while (!operators.empty() && operators.top() != '(')
			{
				answer += operators.top();
				operators.pop();
			}

			if (!operators.empty() && operators.top() == '(')
				operators.pop();
		}
		else
		{
			while (!operators.empty() && operators.top() != '(' && prec(operators.top()) >= prec(c))
			{
				answer += operators.top();
				operators.pop();
			}
			operators.push(c);
		}
	}

	while (!operators.empty())
	{
		if(operators.top() != '(')
			answer += operators.top(); 

		operators.pop();
	}

	cout << answer << '\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	Postfix(str);
	return 0;
}