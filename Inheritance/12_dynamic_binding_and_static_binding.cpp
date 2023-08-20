// 12_dynamic_binding_and_static_binding.cpp

/*
	Binding - ���ε�
		- ���α׷� �ҽ��� ���� ���� ���ο��, �̸�, �ĺ��ڵ鿡 ���� �� �Ǵ� �Ӽ��� Ȯ�����ִ� ����
		- �Լ��� ȣ��� �� �Լ��� �ּҸ� �������ִ� ��

	Static Binding(Early Binding) - ���� ���ε�
		- ������ Ÿ�Ӷ� �̹� �����Ǿ� �ִ�.
		- �ӵ��� ��������, �������� �ʴ�.

	Dynamic Binding(Late Binding) - ���� ���ε�
		- �� Ÿ�Ӷ� ������ ����
		- �������� ������
*/


#include<iostream>
using namespace std;

int add(int x, int y) { return x + y; }
int subract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }

int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0 : add, 1 : subtract, 2 : multiply" << endl;
	cin >> op;

	// ���� ���ε�

	int result;
	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subract(x, y); break;
	case 2: result = multiply(x, y); break;
	default: cout << "Invalid parameter" << endl; break;
	}

	cout << result << endl;


	// ���� ���ε�

	int(*func_ptr)(int, int) = nullptr;
	switch (op)
	{
	case 0: func_ptr = add; break;
	case 1: func_ptr = subract; break;
	case 2: func_ptr = multiply; break;
	default: cout << "Invalid parameter" << endl; break;
	}

	cout << func_ptr(x, y) << endl;

	return 0;
}