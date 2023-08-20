// 17_object_slicing_and_reference_wrapper.cpp


/*
   Object Slicing - 객체 슬라이싱
   - 파생 클래스의 인스턴스를 기반 클래스의 인스턴스로 복사할 때 일어난다.
   - 파생 클래스가 가진 정보가 손실된다.
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
	Base& refl = d; // reference => d를 Base 형태로 참조함 것, 메모리는 그대로 유지하면서 크기만 작게 사용하는 것
	refl.Print();

	//2. copy
	// d의 Base 까지의 내용만 복사해 새로운 메모리를 만듬
	// -> d가 가지고 있던 Derived1의 멤버 데이터가 잘림
	Base base = d; // object slicing
	base.Print();

	// 매개변수의 타입이 copy냐 reference 형태냐에 따라 결과가 달라짐
	DoSomething(d);

	//3.
	// 손실없이 vector에 넣고 싶을 때 
	Derived1 derived1;
	Derived1 derived2;
	Derived1 derived3;
	Derived1 derived4;
	
	// 타입이 copy 형태라 문제가 생김
	// -> 참조하는 형태의 자료형으로 수정해야함
	//vector<Base> my_vec;

	 // * 사용 
	vector<Base*> my_vec1;

	my_vec1.push_back(&derived1);
	my_vec1.push_back(&derived2);
	my_vec1.push_back(&derived3);
	my_vec1.push_back(&derived4);

	for (auto& vec : my_vec1)
		vec->Print();

	// &는 백터에 안들어감 -> 쓰고싶으면 reference_wrapper나 포인터를 사용하자
	// reference_wrapper 사용

	vector<reference_wrapper<Base>> my_vec2;

	my_vec2.push_back(derived1);
	my_vec2.push_back(derived2);
	my_vec2.push_back(derived3);
	my_vec2.push_back(derived4);

	for (auto& vec : my_vec2)
		vec.get().Print();



	return 0;
}