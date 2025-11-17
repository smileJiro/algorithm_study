#include<bits/stdc++.h>
#include<queue>

using namespace std;

typedef unsigned int _uint;

struct StudentInfo
{
public:
	string name;
	_uint korean = 0;
	_uint english = 0;
	_uint math = 0;
};
struct GradePriority
{
	bool operator()(const StudentInfo& top, const StudentInfo& cmp) const
	{
		if(top.korean != cmp.korean)
			return top.korean < cmp.korean;

		if (top.english != cmp.english)
			return top.english > cmp.english;

		if(top.math != cmp.math)
			return top.math < cmp.math;

		if(top.name != cmp.name)
			return top.name > cmp.name;

		return false;
	}

};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	priority_queue<StudentInfo, vector<StudentInfo>, GradePriority> pq;
	for (int i = 0; i < n; ++i)
	{
		StudentInfo student{};
		cin >> student.name >> student.korean >> student.english >> student.math;
		pq.push(student);
	}

	while (false == pq.empty())
	{
		cout << pq.top().name << "\n";
		pq.pop();
	}

	return 0;
}