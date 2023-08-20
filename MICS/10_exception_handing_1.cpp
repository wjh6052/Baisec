// 10_exception_handing_1.cpp

/*
   예외처리
   try, catch, throw
*/
#include<iostream>
using namespace std;

int main()
{
	double x;
	cin >> x;

	// try : 예외가 발생할 수 있는 지역을 표시한다
	try
	{
		// throw : 예외를 던지고 try 지역을 벗어난다
		// 아래에 catch에서 예외를 받아 처리해준다
		// 만약 catch에서 예외를 받지 못할경우 에러가 발생한다
		if (x < 0.0) throw - 1.0;

		if (x >= 100) throw "100이상의 값이 입력됨";

		cout << sqrt(x) << endl;
	}
	// catch : throw한 예외를 받아 처리한다
	// throw한 타입과 일치해야 chtch할 수 있다
	catch (double x)
	{
		cerr << x << endl;
	}
	// catch를 여러개 작성하여 다양한 타입으로 throw하고 catch할 수 있다
	// 상수 데이터를 참조 형태로 받는경우에는 const를 잡 맞춰줘야 한다
	catch (const char* error_message)
	{
		cerr << error_message << endl;
		clog;
	}

	return 0;
}