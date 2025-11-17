#include<bits/stdc++.h>

using namespace std;
int ComputeButtonCount(int _buttonTime, int _inRest, int* _outRest)
{
	int buttonCount = _inRest / _buttonTime;
	*_outRest = _inRest % _buttonTime;

	return buttonCount;
}

int main()
{
	//const int buttonA{ 300 }, buttonB{ 60 }, buttonC{ 10 };
	//int buttonCountA{}, buttonCountB{}, buttonCountC{};
	//int restTime;
	//cin >> restTime;
	//buttonCountA = ComputeButtonCount(buttonA, restTime, &restTime);
	//buttonCountB = ComputeButtonCount(buttonB, restTime, &restTime);
	//buttonCountC = ComputeButtonCount(buttonC, restTime, &restTime);
	//
	//0 < restTime ? cout << -1 : cout << buttonCountA << " " << buttonCountB << " " << buttonCountC;

	//int i;
	//cin >> i;
	//0 < i % buttonC ? cout << -1 : cout << i / buttonA << " " << i % buttonA / buttonB << " " << i % buttonB / buttonC;




	// 정확한 풀이는 아니고 문제 안보고 그냥 그리디로 푼거임
	//int buttonType[3] = {300, 60, 10};
	//int buttonCount[3] = {};
	//int n;
	//int cnt = 0;
	//cin >> n;
	//for (int i = 0; i < 3; ++i)
	//{
	//	buttonCount[i] = n / buttonType[i];
	//	cnt += n / buttonType[i];
	//	n %= buttonType[i];

	//	if (i == 2 && n > 0)
	//		++buttonCount[i];
	//	cout << buttonCount[i] << '\n';
	//}
	//cout << cnt;
	//
	//int a = 0;
	return 0;
}

