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
	// 소멸자는 생성자의 역순으로 호출된다
	// 먼저 생선된 객체는 다른 객체와 더 많은 관계를 맺고있을 확률이 높기 때문에
	// 생성의 역순으로 객체를 해제하는게 더 안전함
	B b;

	/*
		패딩
		- 클래스나 구조체의 패딩 바이트를 추가하여 CPU가 접근하기 용이하게 해주는 기법
		- CPU가 데이터를 읽을 때 자료형이 잘려 같은 데이터에 두번 접근하는 것을 방지
		- 일반적으로 가장 큰 멤버 변수 크기에 맞춰 패딩 바이트를 추가한다
	*/

	sizeof(A);
	sizeof(B);

	class P1
	{
		char c1;
		short s1;
		short s2;
	};

	// c ㅁ s1 s1 s2 s2
	sizeof(P1);

	class P2
	{
		char c1;
		double d;
		char c2;

	};
	
	// c1 ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ d d d d d d d d c2 ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ
	sizeof(P2); // douvle형에 맞춰 패딩 파이트 추가

	return 0;
}