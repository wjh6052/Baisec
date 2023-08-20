// 18_function_overloading.cpp

/*
	함수의 매개변수를 다르게 하여
	같은 이름의 함수를 중복(적재)하여 사용하는 것
*/

#include<iostream>

int add(int a, int b) { return a + b; }
int add(int a) { return a + 1; }
int add(int a, int b, int c) { return a + b + c; }
// 위에 같은 타입을 받는 함수가 있어서 안됨
// int add(int a, int b) { return a + b + 10; }

// 반환값으로 구분이 안됨
// void add(int a, int b) { }

using integer = int;
// 컴파일러가 보이게 같은 int형이기 때문에 안됨
// integer add(integer a, integer b) { return a + b; }  


float add(float a, float b) { return a + b; }

void output(unsigned int value) {}
void output(float value) {}

int main()
{
	using namespace std;

	auto result1 = add(10, 20);
	auto result2 = add(10.0f, 20.0f);

	cout << result1 << ", " << result2 << endl;


	output(1.1f);
	output(10u);

	// 인자로 보낸 값이 2개 이상의 함수와 매칭됨
	// -> 어떤 함수를 선택해야지 알 수 없어 모호성 문제 발생
	// output(10);

	return 0;
}