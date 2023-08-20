// 15_reference_variable.cpp

/*
	L-value : 나중에 다시 접근 가능한 값, 메모리를 특정할 수 있는 값
	R-value : 식이 끝나면 접근하지 못하는 값, 메모리를 특정할 수 없는 값
*/

#include<iostream>

int Test1(int& a) { return a; }
int Test2(int&& a) { return a; }

int main()
{
	int a = 10;

	// a : L
	// 15 : R
	a = 15;

	// & : L-value reference
	// a == l, a의 새로운 별명 l을 지어줌
	int& l = a;

	l = 10; // a가 가르키는 메모리의 값을 10으로 변경

	// L-balue만 담을 수 있다ㅣ
	// int& l2 = 10;

	// 예외적으로 const 키워드를 사용할 경우에는 가능
	const int& l2 = 10;


	// && : R-value reference
	int&& r = 10;



	return 0;
}