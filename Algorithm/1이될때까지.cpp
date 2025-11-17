#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int cnt = 0;
	//while (n != 1)
	//{
	//	n% k == 0 ? n /= k : n -= 1;
	//	++cnt;
	//}
	
	//while (true)
	//{
	//	int target = (n / k) * k; // 61, 6 이면 (61 / 6) * 6 -> (10) * 6 -> 60;
	//	cnt += n - target; // -1 횟수만큼 cnt 추가
	//	n = target;
	//	if (n < k)
	//		break;

	//	n /= k;
	//	++cnt;
	//}
	//// 더이상 나눠지지 않으면서 n < k 인 상태지 그러면 이제 1씩 빼줘야함. 남은 숫자 1으로 만들어야하니까
	//cnt += (n - 1);

	while (true)
	{
		int m = n % k; 
		cnt += m; 
		n -= m;
		if (n < k)
			break;

		n /= k;
		++cnt;
	}
	// 더이상 나눠지지 않으면서 n < k 인 상태지 그러면 이제 1씩 빼줘야함. 남은 숫자 1으로 만들어야하니까
	cnt += (n - 1);

	cout << cnt;
	return 0;
}