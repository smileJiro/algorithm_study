// 32비트 가정
// 문제 : func2()이 호출된 시점에 sp의 값과 fp의 값을 작성해주세요.
void func2()
{
	int d = 5;
	int e = 6;
}
void func1()
{
	int c = 4;

	func2();
}

int main()
{
	int a = 1;
	int b = 2;
	int c = 3;

	func1();

	return 0;
}


