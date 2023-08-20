// 06_destruction_order_of_derived_class.cpp

#include<iostream>
using namespace std;

class A
{
public:
	A() { cout << "A constructor" << endl; }
	~A() { cout << "A destructor" << endl; }

private:
	int a;
};

class B : public A
{
public:
	B() { cout << "B constructor" << endl; }
	~B() { cout << "B destructor" << endl; }

private:
	double b;
};

int main()
{
	// �Ҹ��ڴ� �������� �������� ȣ��ȴ�
	// ���� ������ ��ü�� �ٸ� ��ü�� �� ���� ���踦 �ΰ����� Ȯ���� ���� ������
	// ������ �������� ��ü�� �����ϴ°� �� ������
	B b;

	/*
		�е�
		- Ŭ������ ����ü�� �е� ����Ʈ�� �߰��Ͽ� CPU�� �����ϱ� �����ϰ� ���ִ� ���
		- CPU�� �����͸� ���� �� �ڷ����� �߷� ���� �����Ϳ� �ι� �����ϴ� ���� ����
		- �Ϲ������� ���� ū ��� ���� ũ�⿡ ���� �е� ����Ʈ�� �߰��Ѵ�
	*/

	sizeof(A);
	sizeof(B);

	class P1
	{
		char c1;
		short s1;
		short s2;
	};

	// c �� s1 s1 s2 s2
	sizeof(P1);

	class P2
	{
		char c1;
		double d;
		char c2;

	};
	
	// c1 �� �� �� �� �� �� �� d d d d d d d d c2 �� �� �� �� �� �� ��
	sizeof(P2); // douvle���� ���� �е� ����Ʈ �߰�

	return 0;
}