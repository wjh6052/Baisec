// 17_object_slicing_and_reference_wrapper.cpp


/*
   Object Slicing - ��ü �����̽�
   - �Ļ� Ŭ������ �ν��Ͻ��� ��� Ŭ������ �ν��Ͻ��� ������ �� �Ͼ��.
   - �Ļ� Ŭ������ ���� ������ �սǵȴ�.
*/

#include<iostream>
#include<vector>
#include<functional> // reference_wrapper

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
	virtual void Print() override { cout << "Derived" << endl; }
public:
	int j = 1;
};

class Derived2 : public Base
{
public:
	virtual void Print() override { cout << "Derived" << endl; }
public:
	int k = 1;
};

void DoSomething(Base b)
{
	b.Print();
}

int main()
{
	//1.
	Derived1 d;
	Base& refl = d; // reference => d�� Base ���·� ������ ��, �޸𸮴� �״�� �����ϸ鼭 ũ�⸸ �۰� ����ϴ� ��
	refl.Print();

	//2. copy
	// d�� Base ������ ���븸 ������ ���ο� �޸𸮸� ����
	// -> d�� ������ �ִ� Derived1�� ��� �����Ͱ� �߸�
	Base base = d; // object slicing
	base.Print();

	// �Ű������� Ÿ���� copy�� reference ���³Ŀ� ���� ����� �޶���
	DoSomething(d);

	//3.
	// �սǾ��� vector�� �ְ� ���� �� 
	Derived1 derived1;
	Derived1 derived2;
	Derived1 derived3;
	Derived1 derived4;
	
	// Ÿ���� copy ���¶� ������ ����
	// -> �����ϴ� ������ �ڷ������� �����ؾ���
	//vector<Base> my_vec;

	 // * ��� 
	vector<Base*> my_vec1;

	my_vec1.push_back(&derived1);
	my_vec1.push_back(&derived2);
	my_vec1.push_back(&derived3);
	my_vec1.push_back(&derived4);

	for (auto& vec : my_vec1)
		vec->Print();

	// &�� ���Ϳ� �ȵ� -> ��������� reference_wrapper�� �����͸� �������
	// reference_wrapper ���

	vector<reference_wrapper<Base>> my_vec2;

	my_vec2.push_back(derived1);
	my_vec2.push_back(derived2);
	my_vec2.push_back(derived3);
	my_vec2.push_back(derived4);

	for (auto& vec : my_vec2)
		vec.get().Print();



	return 0;
}