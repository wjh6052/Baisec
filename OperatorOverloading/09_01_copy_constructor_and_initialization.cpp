// 09_01_copy_constructor_and_initialization.cpp

#include<iostream>
#include<cassert>
using namespace std;

class Fraction
{
public:
	Fraction(int num = 0, int den = 0)
		: numerator(num)
		, denominator(den)
	{
		cout << "constructor!!" << endl;
	}

	Fraction(const Fraction& fraction) // copy constructor 
	{
		cout << "copy constructor!!" << endl;
		//TODO:
	}

	Fraction& operator = (const Fraction& rhs)
	{
		cout << "copy assignment operator" << endl;
		//TODO: 
		return *this;
	}

private:
	int numerator;
	int denominator;
};

Fraction CreateFraction()
{
	Fraction temp(5, 2); // constructor

	return temp; // copy constructor
}

int main()
{
	Fraction f1;

	Fraction f2(f1); // 복사 생성자

	f1 = f2; // 복사 대입 연산자 

	// 생성 시점이기 때문에 f2(f1)과 같다.
	Fraction f3 = f1; // 복사 생성자

	cout << "###################" << endl;
	CreateFraction(); // debug 모드에서 이름있는 객체를 사본 형태로 반환할때 복사가 일어난다. -> RVO, NRVO 최적화랑 연관이 있음

	return 0;
}