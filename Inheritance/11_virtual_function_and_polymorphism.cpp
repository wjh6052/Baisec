// 11_virtual_function_and_polymorphism.cpp

#include<iostream>
using namespace std;


class A
{
public:
	void Print() { cout << "A" << endl; }
	virtual void Print1() { cout << "A1" << endl; }
	virtual void Print2() { cout << "A2" << endl; }
	virtual void Print3() { cout << "A3" << endl; }
	virtual void Print4() { cout << "A4" << endl; }
};

class B : public A
{
public:
	void Print() { cout << "B" << endl; }
	virtual void Print1() { cout << "B1" << endl; }
	virtual void Print2() { cout << "B2" << endl; }
	virtual void Print3() { cout << "B3" << endl; }
};

class C: public B
{
public:
	void Print() { cout << "C" << endl; }
	virtual void Print1() { cout << "C1" << endl; }
	virtual void Print2() { cout << "C2" << endl; }
};



class D : public C
{
public:
	void Print() { cout << "D" << endl; }
	virtual void Print1() { cout << "D1" << endl; }
	virtual void Print4() { cout << "D4" << endl; }
};


int main()
{
	// �� Ŭ������ �´� �޼��� ����Ѵ�. 
	A a;
	a.Print1();

	B b;
	b.Print1();

	C c;
	c.Print1();

	D d;
	d.Print1();

	/*
		�� ĳ���ý� �������̵��� �Ļ� Ŭ������ �ż��尡 ������ ����� ����� ���� �ʴ´�
		-> ���� Ŭ������ �������̵��� �ż��忡 virtual Ű���带 �ٿ� �ذ��� �����ϴ�
		virtual Ű����� ��ü�� ���� �Լ� ���̺��� �����Ͽ� �� ��ü�� ���� �ڷ����� �´�
		�޼��带 ȣ�� �����ش�.

		virtual funtion tavle - ���� �Լ� ���̺�
		- virtual Ű���尡 ���� �޼���� ���� �Լ��� �Ǿ� ���� �Լ� ���̺� �߰��ǰ�
		���� �Լ� ���̺��� ���� ȣ���� �ȴ�.
		
		- �Ļ� Ŭ�������� ��� Ŭ������ ���� �Լ��� �������̵��� �ϸ� ���� ������ ���̺��� ����Ű��
		���� �Լ� �ּҸ� �Ļ� Ŭ������ �������̵��� �Լ��� ��ü�Ѵ�.
		
		- Ŭ�������� 1���� �����Ѵ� -> ���� ��ü�� �־ �ϳ��� ���� �Լ� ���̺��� ����Ų��

		// ���� : virtual Ű����� ���� �Լ� ���̺� ����
	*/

	A& ref_b = b;
	A& ref_c = c;
	A& ref_d = d;

	cout << "########## A" << endl;
	a.Print();
	a.Print1();
	a.Print2();
	a.Print3();
	a.Print4();

	cout << endl << "########## B" << endl;
	ref_b.Print();
	ref_b.Print1();
	ref_b.Print2();
	ref_b.Print3();
	ref_b.Print4();

	cout << endl << "########## C" << endl;
	ref_c.Print();
	ref_c.Print1();
	ref_c.Print2();
	ref_c.Print3();
	ref_c.Print4();

	cout << endl << "########## D" << endl;
	ref_d.Print();
	ref_d.Print1();
	ref_d.Print2();
	ref_d.Print3();
	ref_d.Print4();

	cout << endl << "############" << endl;
}