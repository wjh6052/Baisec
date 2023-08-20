// 09_perfect_fonwarding.cpp

#include <iostream>
#include <vector>

class MyClass {};

void func(MyClass& c) { std::cout << "L-ref" << std::endl; }
void func(const MyClass& c) { std::cout << "const L-ref" << std::endl; }
void func(MyClass&& c) { std::cout << "R-ref" << std::endl; }

/*
	1. 문제 확인

	아래와 같이 코드를 작성한다면 t라는 매개변수를 받을때 인자의 타입이 &든 &&든 전부 T라는 자료형으로 추론하게된다.
	-> T, T&, T&& 각각의 타입을 받을때 &를 제거한 T로 인식해버림

	그렇기 때문에 무슨 타입의 값을 받는 T t는 값을 카피해오게되고  L-value 타입의 변수가될 수 밖에 없다
	-> 이 문제를 해결하여 완벽하게 전달하고 싶음 -> perfect forwarding
*/

//template <typename T>
//void func_wrapper(T t) {
//	func(t);
//}



/*
	2. T -> T&로 바꾼다면?

	l-value만 받을 수 있기 때문에 func_wrapper(MyClass()); 에서 에러가 발생한다
	우측값을 받기위해 cosnt T& t 타입으로 오버로딩 하였으나 결국 인자를 받기위해서는
	이름이 있는 매개변수 값으로 받기 때문에 l-value로 추론해버린다는 문제가 발생하고
	오버로딩을 해줘야 한다는 번거로움이 생긴다.
*/
//template <typename T>
//void func_wrapper(T& t) {
//	func(t);
//}

//template <typename T>
//void func_wrapper(const T& t) {
//	func(t);
//}

/*
   3. T -> T&&로 바꾼다면?

   일반 함수에서는 임의의 타입에 대해서 &&로 받는다는 것은 r-value를 받는 다는 의미를 가지지만
   임의의 템플릿 타입을 T&& 형태로 받는다는 것은 l-value와 r-value를 전부 받을 수 있다는 것을 의미한다.
   -> 이것을 universal reference라고 부른다.

   하지만 이름이 있는 매개변수로 받기 때문에 타입 자체는 l-value로 인식하게된다.
   -> 이는 forward<T>()를 사용하여 해결가능


   universal reference는 레퍼런스 겹침 규칙에 따라 T의 타입을 추론한다.
   -> &를 1, &&를 0으로 두고 OR연산을 한다고 생각하면된다.

   typedef int& T1;
   T1& r1;	T1, &	->	int&, &	->	int&

   typedef int& T1;
   T1& r1;      T1&      -> int&, &      -> int&
   T1&& r2;   T1&&   -> int&, &&      -> int&&

   typedef int&& T2;
   T2& r3;   T2&      -> int&&, &      -> int&
   T2&& r4;  T2&&      -> int&&, &&   -> int&&
*/

template <typename T>
void func_wrapper(T&& t) {
	//func(t);

	func(std::forward<T>(t));
}

int main() {
	MyClass c;
	const MyClass cc;

	std::cout << "func" << std::endl;
	func(c);
	func(cc);
	func(MyClass());
	std::cout << std::endl;

	std::cout << "func_wrapper" << std::endl;
	func_wrapper(c);
	func_wrapper(cc);
	func_wrapper(MyClass());
	std::cout << std::endl;

}