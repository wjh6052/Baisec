// 17_array.cpp

#include<iostream>
#include<array>

int main()
{

	using namespace std;

	int arr1[] = { 1,2,3,4,5 };
	int arr2[]{ 1,2,3,4,5 };
	//int arr3[](1, 2, 3, 4, 5);

	std::array<int, 5> arr4;
	std::array<int, 5> arr5{ 1,2,3,4,5 };

	// []는 예외처리를 하지 않은 대신 빠름

	arr5[0];


	//at()은 범위를 벗어난 값인지 체크하고 예외를 던지기 때문에 안전하지만 []보단 느림
	arr5.at(0);

	return 0;
}