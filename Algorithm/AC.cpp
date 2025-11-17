
#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int testCount;
	cin >> testCount;
	vector<string> outString(testCount);
	for (int i = 0; i < testCount; ++i)
	{
		string func;
		func.reserve(100000);
		cin >> func;
		int numCount;
		cin >> numCount;
		string textArray;
		cin >> textArray;
		int curIndex = 1;

		deque<int> numDeque;
		string strNumber;
		/* 문자열 해석 후 dequeu에 수 삽입 */
		while (curIndex < textArray.size() && numCount != 0)
		{
			if (textArray[curIndex] == ',' || textArray[curIndex] == ']')
			{
				int total = 0;
				numDeque.push_back(stoi(strNumber));
				strNumber.clear();
			}
			else
			{
				strNumber += textArray[curIndex];
			}

			++curIndex;
		}


		/* 함수 실행 */
		func;
		bool isReverse = false;
		bool isError = false;
		for (auto str : func)
		{
			if (str == 'R')
			{
				isReverse ^= 1;
			}
			else if(str == 'D')
			{
				if (numDeque.empty())
				{
					isError = true;
					break;
				}
				isReverse == 0 ? numDeque.pop_front() : numDeque.pop_back();
			}
		}


		string str = "";
		if (true == isError)
		{
			str = "error";
		}
		else
		{
			/* 문자열 만들기 */

			str = "[";
			if (false == isReverse)
			{
				for (int i = 0; i < numDeque.size(); ++i)
				{
					str += to_string(numDeque[i]);

					if (i != numDeque.size() - 1)
						str += ",";
				}
			}
			else
			{
				for (int i = 0; i < numDeque.size(); ++i)
				{
					int idx = numDeque.size() - 1 - i;
					str += to_string(numDeque[idx]);

					if (i != numDeque.size() - 1)
						str += ",";
				}
			}
			str += "]";
		}
		outString[i] = str;
	}

	for (auto str : outString)
	{
		cout << str << "\n";
	}


	return 0;
}