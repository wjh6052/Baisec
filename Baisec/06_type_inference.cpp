// 06_type_inference.cpp
// Ÿ�� �߷�


/*
   auto
   - �ʱ�ȭ�ϴ� ���� ���� ������Ÿ���� �ڵ����� �������ִ� Ű����
*/

#include<iostream>

// �Ű������� auto Ű���� x
//int add(auto x, auto y);

auto add(int x, int y)
{
	return x + y;
}

using namespace std;

int main()
{
	int a = 10;
	float f = 3.14f;
	double d = 45.0;

	auto result = d + f;

	return 0;
}