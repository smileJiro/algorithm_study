#include <vector>
#include <string>

using namespace std;


bool CheckBracketPair(vector<char>& bracketStack, const string& expression)
{
	for (int i = 0; i < expression.size(); ++i)
	{
		char symbol = expression[i];
		
		switch (symbol)
		{
		case '[':
			bracketStack.push_back(']');
			break;
		case '{':
			bracketStack.push_back('}');
			break;
		case '(':
			bracketStack.push_back(')');
			break;
		case ']':
		case '}':
		case ')':
			if (symbol == bracketStack.back())
				bracketStack.pop_back();
			break;
		default:
			break;
		}
	}


	return bracketStack.empty() ? true : false;
}

int main()
{
	vector<char> bracketStack;
	string expression = "[{(A+C)*(B*C)}]+{A+B*(C+D)+(E+F}";

	bool result = CheckBracketPair(bracketStack, expression);

	// 문제 -> result 값과 현재 bracketStack의 메모리 상태를 설명하세요.
	return 0;
}

// result == false; 
//  0 : }, 1: )