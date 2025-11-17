#include <bits\stdc++.h>
#include "MyVector.h"
using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(15);


	MyVector<int> Myvec;
	Myvec.Push_back(15);
	Myvec.Push_back(12);
	Myvec.Push_back(15);
	Myvec.Push_back(10);
	Myvec.Erase(3);
	for (int i = 0; i < 2000; ++i)
		Myvec.Push_back(i);

	for (int i = 0; i < Myvec.Size(); ++i)
		cout << Myvec[i] << "\n";

	
	//Myvec[0] = 1;
	return 0;
}