// 01_function_template.cpp

/*
	Tempate
	- 프로그래머가 원하는 타입을 넣어주면 알맞게 코드를 찍어내주는 툴
	- int나 double같은 구체적인 자료형을 포괄할 수 있는 일반형(generic type)으로 정의한다
	- 어떤 데이터형을 템플릿에 매개변수로 전달하면 컴파일러가 그 데이터형에 맞는 코드를 생성한다
	- 구체적인 데이터형 대신 일반형을 사용하여 프로그래밍을 하게 되는데 이것을
	일반화 프로그래밍이라고 부른다
	- 다양한 자료형에 동일한 알고리즘을 적용할 때 템플릿을 사용하는게 유리하다
*/

#include<iostream>
using namespace std;

// 오버로딩으로 각 타입에 맞게 처리할 수 있지만 
// 새로운 타입의 형태가 필요하면 추가해 줘야함 
// -> 번거롭고 알고리즘 자체의 변경점이 생기면 모두 수정해야함, 유지보수가 힘들다.
//int GetMax(int x, int y) { return (x > y) ? x : y; }
//double GetMax(double x, double y) { return (x > y) ? x : y; }
//short GetMax(short x, short y) { return (x > y) ? x : y; }
//char GetMax(char x, char y) { return (x > y) ? x : y; }
//long long GetMax(long long x, long long y) { return (x > y) ? x : y; }

template<typename T> // 템플릿 매개변수 T 선언, 코드를 작성할때 사용할 자료형이다
//template<class T> // class 라고 선언할 수 있지만 차이는 없다
T GetMax(T x, T y) // T를 하나의 자료형처럼 생각하여 사용
{

	return (x > y) ? x : y;
}


class Won
{
public:
	Won(int value = 0) : value(value) {}

	bool operator > (const Won& rhs)
	{
		return value > rhs.value;
	}

	friend ostream& operator << (ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}

private:
	int value = 0;
};



int main()
{
	// <>에 템플릿 인자를 넘겨 원하는 형태의 함수를 작성하도록 유도할 수 있음
	//cout << GetMax<int>(1, 2) << endl;
	//cout << GetMax<float>(1.0f, 2.0f) << endl;

	// 인자 타입을 일치 시켜주면 <>로 타입을 명시적으로 지정해주지 않아도 가능
	cout << GetMax(1, 2) << endl;
	cout << GetMax(1.0f, 2.0f) << endl;

	// 인자 타입이 일치하지 않아 error
	//cout << GetMax(1, 2u) << endl;

	// 사용자가 정의한 자료형도 사용 가능
	cout << GetMax(Won(6), Won(2)) << endl;



	return 0;
}