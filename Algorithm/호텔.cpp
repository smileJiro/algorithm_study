//#pragma region 틀린 풀이 (가성비 계산 그리디 + 이분탐색) -> 반례 있어서 DP풀이가 정석
//#include <bits/stdc++.h>
//using namespace std;
//using P = pair<int, int>; // cost, value
//// 2초 제한 약 1억번
//// 0 <= C < 1000, 0 <= N < 20 
//// 시간복잡도는 널널하다. 
//
//
//int C, N; // 목표 고객 수, 홍보할 수 있는 도시 수
//P arr[22];
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> C >> N;
//	for (int i = 0; i < N; ++i)
//	{
//		int c, v;
//		cin >> c >> v;
//		arr[i].first = c;
//		arr[i].second = v;
//	}
//
//	// 이분탐색 + 그리디
//	sort(arr, arr + N, [&](P& a, P& b)
//		{
//			float valueA = (float)a.second / (float)a.first;
//			float valueB = (float)b.second / (float)b.first;
//
//			return valueA > valueB; // 내림차순
//		});
//
//
//	// m == 투자할 금액
//	int s{ 0 }, e{ C };
//	int m = (s + e) / 2;
//	int answer = 1000;
//	while (s <= e)
//	{
//		m = (s + e) / 2;
//
//		int curCost = m;
//		int valueSum = 0;
//		// 투자 대비 효과 계산
//		for (int i = 0; i < N; ++i)
//		{
//			auto& [cost, value] = arr[i];
//			int mul = curCost / cost;
//			valueSum += curCost / cost * value;
//			curCost -= cost * mul;
//
//			if (curCost == 0)
//				break;
//		}
//
//		// 인덱스 이동
//		if (valueSum < C)
//			s = m + 1;
//		else
//		{
//			answer = min(answer, m);
//			e = m - 1;
//		}
//	}
//
//	cout << answer << '\n';
//	return 0;
//}
//
//#pragma endregion
//
//
