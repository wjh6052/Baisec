// 12_dynamic_binding_and_static_binding.cpp

/*
	Binding - 바인딩
		- 프로그램 소스에 쓰인 각종 내부요소, 이름, 식별자들에 대해 값 또는 속성을 확정해주는 과정
		- 함수가 호출될 때 함수의 주소를 연결해주는 것

	Static Binding(Early Binding) - 정적 바인딩
		- 컴파일 타임때 이미 결정되어 있다.
		- 속도가 빠르지만, 유연하지 않다.

	Dynamic Binding(Late Binding) - 동적 바인딩
		- 런 타임때 결정이 난다
		- 느리지만 유연함
*/


#include<iostream>
using namespace std;

int add(int x, int y) { return x + y; }
int subract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }

int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0 : add, 1 : subtract, 2 : multiply" << endl;
	cin >> op;

	// 정적 바인딩

	int result;
	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subract(x, y); break;
	case 2: result = multiply(x, y); break;
	default: cout << "Invalid parameter" << endl; break;
	}

	cout << result << endl;


	// 동적 바인딩

	int(*func_ptr)(int, int) = nullptr;
	switch (op)
	{
	case 0: func_ptr = add; break;
	case 1: func_ptr = subract; break;
	case 2: func_ptr = multiply; break;
	default: cout << "Invalid parameter" << endl; break;
	}

	cout << func_ptr(x, y) << endl;

	return 0;
}