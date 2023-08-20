// 01_arithmatic_operator.cpp


//#define Case1
#define Case2

#ifdef Case1
#include<iostream>

using namespace std;

class Won
{
public:
	Won(int value) : value(value) {}

	int GetValue() const
	{
		return value;
	}

private:
	int value;

	friend int operator+(const Won& lhs, const Won& rhs);

	friend Won operator-(const Won& lhs, const Won& rhs)
	{
		// 반환 값에 적절한 생서자가 있을시 가능
		return lhs.value - rhs.value;
	}
};

/*
	과제 : 재귀 함수
		- 조사하고 정리
		- 재귀 함수를 사용해 피보나치 수열 구현
		- (필수x)재귀 함수를 사용해 하노이 탑 구현
*/

int operator + (const Won& lhs, const Won& rhs)
{
	return lhs.value + rhs.value;
}

int main()
{
	Won l(10), r(20);

	int rl = l + r;

	cout << rl << endl;

	cout << (l - r).GetValue() << endl;

	return 0;
}
#endif


#ifdef Case2
#include<iostream>

using namespace std;

class Won
{
public:
	Won(int value) : value(value) {}

	int GetValue() const
	{
		return value;
	}

	int operator+(const Won& rhs)
	{
		return value + rhs.value;
	}
	Won operator-(const Won& rhs)
	{
		return value - rhs.value;
	}

private:
	int value;

};



int main()
{
	Won l(10), r(20);

	int rl = l + r;

	cout << rl << endl;

	cout << (l - r).GetValue() << endl;

	return 0;
}
#endif

/*
	과제
	- Won class에 연산자 오버로딩 추가하기
	- 곱하기, 나누지, 나머지
	- += -= *= /= %=
*/
