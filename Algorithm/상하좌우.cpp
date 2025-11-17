#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string str;
	cin.ignore(); // 버퍼 비우는 습관 -> getline() 쓸때만.
	getline(cin, str);
	cin >> str;

	char dirChar[] = { 'R','D', 'L', 'U' };
	int dx[] = { 1, 0, -1, 0 };
	int dy[] = { 0, 1, 0, -1 };
	int x = 1, y = 1;

	for (char c : str)
	{
		for (int d = 0; d < 4; ++d)
		{
			if (c == dirChar[d])
			{
				int targetX = x + dx[d];
				int targetY = y + dy[d];

				if (0 < targetX && n >= targetX &&
					0 < targetY && n >= targetY)
				{
					x = targetX;
					y = targetY;
				}

				break;
			}
		}
	}

	cout << x << ", " << y << '\n';
	return 0;
}

//int main()
//{
//	int n;
//	cin >> n;
//	string str;
//	cin >> str;
//	
//	int dx[DIR_LAST] = {1, 0, -1, 0};
//	int dy[DIR_LAST] = {0, 1, 0, -1};
//	int pos[2] = { 1, 1 };
//	int cnt = 0;
//	char moveDir[DIR_LAST] = {'R', 'D', 'L', 'U'};
//	for (int i = 0; i < str.size(); ++i)
//	{
//		// 1. 계획서를 읽어 이동한다.
//		int targetX = 0;
//		int targetY = 0;
//		switch (str[i])
//		{
//		case 'R':
//			targetX = pos[X] + dx[R];
//			targetY = pos[Y] + dy[R];
//			break;
//		case 'D':
//			targetX = pos[X] + dx[D];
//			targetY = pos[Y] + dy[D];
//		break;
//		case 'L':
//			targetX = pos[X] + dx[L];
//			targetY = pos[Y] + dy[L];
//		break;
//		case 'U':
//			targetX = pos[X] + dx[U];
//			targetY = pos[Y] + dy[U];
//		break;
//		default:
//			break;
//		}
//		
//		if (0 < targetX && n >= targetX &&
//			0 < targetY && n >= targetY)
//		{
//			pos[X] = targetX;
//			pos[Y] = targetY;
//		}
//		// 2. 만약 인덱스 범위를 벗어난다면? 이동하지 않고 패스한다.
//
//	}
//	
//
//
//	cout << pos[X] << ", " << pos[Y] << '\n';
//	return 0;
//}