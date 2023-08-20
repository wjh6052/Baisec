// 18_function_overloading.cpp

/*
	�Լ��� �Ű������� �ٸ��� �Ͽ�
	���� �̸��� �Լ��� �ߺ�(����)�Ͽ� ����ϴ� ��
*/

#include<iostream>

int add(int a, int b) { return a + b; }
int add(int a) { return a + 1; }
int add(int a, int b, int c) { return a + b + c; }
// ���� ���� Ÿ���� �޴� �Լ��� �־ �ȵ�
// int add(int a, int b) { return a + b + 10; }

// ��ȯ������ ������ �ȵ�
// void add(int a, int b) { }

using integer = int;
// �����Ϸ��� ���̰� ���� int���̱� ������ �ȵ�
// integer add(integer a, integer b) { return a + b; }  


float add(float a, float b) { return a + b; }

void output(unsigned int value) {}
void output(float value) {}

int main()
{
	using namespace std;

	auto result1 = add(10, 20);
	auto result2 = add(10.0f, 20.0f);

	cout << result1 << ", " << result2 << endl;


	output(1.1f);
	output(10u);

	// ���ڷ� ���� ���� 2�� �̻��� �Լ��� ��Ī��
	// -> � �Լ��� �����ؾ��� �� �� ���� ��ȣ�� ���� �߻�
	// output(10);

	return 0;
}