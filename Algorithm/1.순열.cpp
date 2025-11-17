#include<bits/stdc++.h>

using namespace std;
bool My_next_permutation(vector<int>& a)
{

	/* 1. 마지막수부터 다음 수가 나보다 작은 지 비교한다 */
	/* 작다면 그 수를 교체 대상 수로 선정한다. */
	int i = a.size() - 2; /* 교체 대상 >>> pivot i == pivot으로 직관적인 코드 작성 */
	while (0 <= i && a[i] >= a[i + 1])
	{
		--i;
	}
	if (i < 0)
		return false;

	/* 교체 대상 수보다 큰 수를 배열의 마지막 부터 탐색한다. 순열이라면 분명 뒤부터 찾은 나보다 큰수가 반드시 다음 수이다.*/
	int j = a.size() - 1; /* 동일한 방식으로 교체 대상 == j */
	while (a[j] <= a[i])
	{
		--j;
	}

	/* 교체 대상 수보다 큰수를 탐색했다면 스왑 진행 후, 그 다음 인덱스부터 오름차순 정렬 */
	swap(a[i], a[j]);
	reverse(a.begin() + i + 1, a.end());

	return true;
}


int main()
{
	vector<int> a = { 3,2,1,4 };
	sort(a.begin(), a.end());
	//int a[] = { 1,2,3 };

	do 
	{
		for (int i : a)
		{
			cout << i << " ";
		}
		cout << '\n';
	} 
	while (My_next_permutation(a));
	//while (next_permutation(a.begin(), a.end()));




	return 0;
}

/* 0. 경우의 수 문제는 두종류 뿐이다. 순열 or 조합 */
/* 1. 순서에 상관이 있다면 >>> 이건 순열이다. */
/* 2. 순서를 재배치 하여~~, ~한 경우 max값을 ~ */

/* next_permutation(first, last) >> > 보통(begin, end) */ 
// 입력 순열은 반드시 오름 차순으로 정렬되어야함
// 내림 차순이라면 이미 가장 큰 순열이라 바로 return false;
// 내림 차순인 경우 prev_permutation() 사용하면 되지만 굳이
// return true : 다음 순열이 존재해서 순열이 변경되었음
// return false : 다음 순열이 없음 (즉, 현재 순열이 마지막 순열)

/* 순열의 순서 기준 */
// 사전 순(lexicographical order) 기준
// 우리가 단어를 사전에서 찾을 때의 정렬 순서를 의미한다.
// 숫자 기준 가장 작은 순서 부터 큰순서로 정렬되듯
//{
//	1 2 3  ← 제일 작음
//	1 3 2
//	2 1 3
//	2 3 1
//	3 1 2
//	3 2 1  ← 제일 큼
//
//}

// next_permutation()은 지금보다 바로 다음 순열을 만들어주고, 
// prev_permutation()은 지금보다 바로 전 순열을 만들어준다.

// 이는 문자열 std:string에도 동일하게 적용 가능하다.