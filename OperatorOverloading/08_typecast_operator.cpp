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

	// �迭�� �Ű������� �ѱ涧 �����ͷ� ���� 
	// -> ĳ������ �����ͷ� ó���ؾ���
	operator float* ()
	{
		// ����� ���������� �Ǿ��־� x�� �ѱ�� x, y, z ������� ���ٰ���
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
	���� : class ĳ����
		- Hour Ŭ������ Minute, Second, Milli_Second Ŭ������ ĳ���õǵ��� ó��

	+ �߰� ����
		- Milli_Second Ŭ������ Hour, Minute, Second Ŭ������ ĳ���õǵ��� ó��

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
//	// TODO: h�� �ð� ���
//}
//
//void PrintMinute(Minute m)
//{
//	// TODO: m�� �ð� ���
//}
//
//void PrintSecond(Second s)
//{
//	// TODO: s�� �ð� ���
//}
//
//void PrintMilli_Second(Milli_Second ms)
//{
//	// TODO: ms�� �ð� ���
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


