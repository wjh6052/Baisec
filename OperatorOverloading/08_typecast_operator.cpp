// 08_typecast_operator.cpp

#include<iostream>
using namespace std;

class Won
{
public:
	Won(int value = 0) : value(value) {}

	operator int()
	{
		return value;
	}

private:
	int value = 0;
};

void Print(int val)
{
	cout << val << endl;
}

class Point
{
public:
	Point(float x, float y, float z)
		: x(x), y(y), z(z)
	{

	}

	// 배열은 매개변수로 넘길때 포인터로 받음 
	// -> 캐스팅을 포인터로 처리해야함
	operator float* ()
	{
		// 멤버가 연속적으로 되어있어 x를 넘기면 x, y, z 순서대로 접근가능
		return &x;
	}

private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

void PrintPoint(float points[3])
{
	cout << points[0] << endl;
	cout << points[1] << endl;
	cout << points[2] << endl;
}

int main()
{
	Won w(10);

	Print(w);

	Point p(1.0f, 2.0f, 3.0f);

	PrintPoint(p);

	return 0;
}


/*
	과제 : class 캐스팅
		- Hour 클래스가 Minute, Second, Milli_Second 클래스로 캐스팅되도록 처리

	+ 추가 과제
		- Milli_Second 클래스가 Hour, Minute, Second 클래스로 캐스팅되도록 처리

*/

//class Hour
//{
//
//};
//
//class Minute
//{
//
//};
//
//class Second
//{
//
//};
//
//class Milli_Second
//{
//
//};
//
//void PrintHour(Hour h)
//{
//	// TODO: h의 시간 출력
//}
//
//void PrintMinute(Minute m)
//{
//	// TODO: m의 시간 출력
//}
//
//void PrintSecond(Second s)
//{
//	// TODO: s의 시간 출력
//}
//
//void PrintMilli_Second(Milli_Second ms)
//{
//	// TODO: ms의 시간 출력
//}
//
//int main()
//{
//	Hour h(10);
//
//	PrintHour(h);
//	PrintMinute(h);
//	PrintSecond(h);
//	PrintMilli_Second(h);
//
//	return 0;
//}


