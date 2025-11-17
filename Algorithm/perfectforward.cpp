#include <bits/stdc++.h>

using namespace std;



void Func2(int&& arg)
{
	int a = 0;
}

void Func2(int& arg)
{
	int a = 0;
}

template<typename T>
constexpr T&& FFforward(remove_reference_t<T>& t) noexcept {
    return static_cast<T&&>(t);
}

template<typename T>
constexpr T&& FFforward(remove_reference_t<T>&& t) noexcept {
    static_assert(!is_lvalue_reference<T>::value, "bad forward call");
    return static_cast<T&&>(t);
}
template<typename T>
void Func(T&& arg)
{
	Func2(move(arg));
}
template<typename T>
void Func(T& arg)
{
	Func2();
}
int main()
{
	Func(10); // int&& arg
	int a = 5;
	Func(a); // int& arg

	vector<int> a;
	return 0;
}
