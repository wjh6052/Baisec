// 03_template_and_non_type_prarameter.cpp

/*
   non-type parameter
   - 자료형이 아닌 템플릿 매개변수
   - 자료형이 아닌 상수값을 넣어준다.
*/

#include<iostream>
#include<array>
using namespace std;



template <typename T, unsigned int SIZE>
class MyArray
{
public:
	MyArray() = default;
	~MyArray() = default;

private:
	T arr1[10];
	T arr2[SIZE]; // 템플릿 구체화 시점(컴파일 타임)때 SIZE가 매크로 상수 처럼 동작하면서 작성이됨
};

#define SIZE 10

int main()
{
	MyArray<int, 10> arr1;
	MyArray<double, 10> arr2;



	return 0;
}