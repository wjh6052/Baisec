// 15_reference_variable.cpp

/*
	L-value : ���߿� �ٽ� ���� ������ ��, �޸𸮸� Ư���� �� �ִ� ��
	R-value : ���� ������ �������� ���ϴ� ��, �޸𸮸� Ư���� �� ���� ��
*/

#include<iostream>

int Test1(int& a) { return a; }
int Test2(int&& a) { return a; }

int main()
{
	int a = 10;

	// a : L
	// 15 : R
	a = 15;

	// & : L-value reference
	// a == l, a�� ���ο� ���� l�� ������
	int& l = a;

	l = 10; // a�� ����Ű�� �޸��� ���� 10���� ����

	// L-balue�� ���� �� �ִ٤�
	// int& l2 = 10;

	// ���������� const Ű���带 ����� ��쿡�� ����
	const int& l2 = 10;


	// && : R-value reference
	int&& r = 10;



	return 0;
}