#include "pch.h"
#define STACK_MAX 1000
#define STACK_EMPTY -1
typedef struct tagStack
{
public:
	bool	push(int _i) { 
		if (topIdx < STACK_MAX - 1)
		{
			array[++topIdx] = _i;
			return true;
		}
		return false;
	}
	int		pop() { return empty() ? array[topIdx--] : STACK_EMPTY; } // 스택 데이터 꺼낸 후 삭제

public:
	int		top() { return empty() ? array[topIdx] : STACK_EMPTY; } // 스택 데이터 반환
	bool	empty()	{ return STACK_EMPTY == topIdx; }
	int		size() { return topIdx + 1; }

public:
	int array[STACK_MAX];
	int topIdx = -1;

}STACK;
int main()
{
	STACK s;

	for (int i = 0; i < 100; ++i)
	{
		s.push(i);
	}
	
	for (int i = 0; i < 100; ++i)
	{
		cout << s.pop() << "\n";
	}

	return 0;
}
