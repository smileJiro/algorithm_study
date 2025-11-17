#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int N;
struct MyVector
{
	MyVector(int _x, int _y)
		: x(_x)
		, y(_y)
	{

	}
	MyVector operator+(const MyVector& other) {
		return MyVector(x + other.x, y + other.y);
	}
	MyVector operator-(const MyVector& other) {
		return MyVector(x - other.x, y - other.y);
	}
	double x{}, y{};
};
vector<MyVector> points;

double computeTriExtent(int start, int second)
{
	int third = second - 1;
	MyVector vec1 = points[second] - points[start];
	MyVector vec2 = points[third] - points[start];
	// 두 벡터를 외적하고 -> 결과 벡터 길이 / 2;
	double z = vec1.x * vec2.y - vec1.y * vec2.x;
	return z * 0.5;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		points.emplace_back(x, y);
	}
	
	double sum = 0;
	for (int i = 2; i < N; ++i)
		sum += computeTriExtent(0, i);

	cout << fixed << setprecision(1) << fabs(sum) << '\n';
	return 0;
}