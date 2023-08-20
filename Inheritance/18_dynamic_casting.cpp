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
		// static_cast : 컴파일 타임에 자료형이 캐스팅이 가능한 형태인 확인함
		// Base* -< Derived2* 로 캐스팅이 가능한 형태이므로 허용
		// 컴파일 타임 때 캐스팅 가능 여부를 판단하므로 빠르나 실제 데이터가 뭔지는 확인하지 못해 안전성이 떨어짐

		//Derived2* base_to_d2 = static_cast<Derived2*>(b);

		//base_to_d2->k = 888;
	}
	
	{
		// dynamic_cast : 런타임에 자료형이 가릐키고 있는 데이터가 실제 캐스팅 가능한 객체인지 확인함
		// 이번 경우에는 실제 타입이 Derived1 이므로 캐스팅을 허용하지 않는다. -> 실패시 nullptr를 반환
		// 런타임 때 캐스팅 가능 여부를 판단하기 위해 실제 메모리를 확인하므로 안전하지만 static_cast보다 느려서 잘 사용하지 않음
		// static_cast를 사용하는 대신에 실제 타입을 구분할 수 있는 id값을 부여하여 검사하여 사용한다
		Derived2* base_to_d2 = dynamic_cast<Derived2*>(b);

		base_to_d2->k = 888;
	}
}


int main()
{
	// 업캐스팅
	Derived1 d1;
	Base* base = &d1;

	// 다운 캐스팅은 명시적 형변환을 해줘야한다.
	Derived1* base_to_d1 = static_cast<Derived1*>(base);
	base_to_d1->Print();

	DoSomething(&d1);

	cout << d1.j << endl;

	return 0;
}
