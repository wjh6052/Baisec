// 20_function_pointer.cpp

#include<iostream>
#include<functional>


bool func(const int& x)
{
	return x > 0;
}

// �Լ��� �̸� �κ��� ������ �ȴ�.
typedef bool (*event1)(const int&);

using event2 = bool (*)(const int&);

int main()
{
	using namespace std;


	bool (*pf)(const int&) = func;

	event1 f1 = func;

	event2 f2 = func;

	std::function<bool(const int&)> f3 = func;

	return 0;
}