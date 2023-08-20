// 18_dynamic_casting.cpp


#include<iostream>
using namespace std;

class Base
{
public:
	virtual void Print() { cout << "Base" << endl; }
public:
	int i = 0;
};

class Derived1 : public Base
{
public:
	virtual void Print() override { cout << "Derived1" << endl; }
public:
	int j = 1;
};

class Derived2 : public Base
{
public:
	virtual void Print() override { cout << "Derived2" << endl; }
public:
	int k = 2;
};

void DoSomething(Base* b)
{
	{
		// static_cast : ������ Ÿ�ӿ� �ڷ����� ĳ������ ������ ������ Ȯ����
		// Base* -< Derived2* �� ĳ������ ������ �����̹Ƿ� ���
		// ������ Ÿ�� �� ĳ���� ���� ���θ� �Ǵ��ϹǷ� ������ ���� �����Ͱ� ������ Ȯ������ ���� �������� ������

		//Derived2* base_to_d2 = static_cast<Derived2*>(b);

		//base_to_d2->k = 888;
	}
	
	{
		// dynamic_cast : ��Ÿ�ӿ� �ڷ����� ���lŰ�� �ִ� �����Ͱ� ���� ĳ���� ������ ��ü���� Ȯ����
		// �̹� ��쿡�� ���� Ÿ���� Derived1 �̹Ƿ� ĳ������ ������� �ʴ´�. -> ���н� nullptr�� ��ȯ
		// ��Ÿ�� �� ĳ���� ���� ���θ� �Ǵ��ϱ� ���� ���� �޸𸮸� Ȯ���ϹǷ� ���������� static_cast���� ������ �� ������� ����
		// static_cast�� ����ϴ� ��ſ� ���� Ÿ���� ������ �� �ִ� id���� �ο��Ͽ� �˻��Ͽ� ����Ѵ�
		Derived2* base_to_d2 = dynamic_cast<Derived2*>(b);

		base_to_d2->k = 888;
	}
}


int main()
{
	// ��ĳ����
	Derived1 d1;
	Base* base = &d1;

	// �ٿ� ĳ������ ����� ����ȯ�� ������Ѵ�.
	Derived1* base_to_d1 = static_cast<Derived1*>(base);
	base_to_d1->Print();

	DoSomething(&d1);

	cout << d1.j << endl;

	return 0;
}
