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

	// []�� ����ó���� ���� ���� ��� ����

	arr5[0];


	//at()�� ������ ��� ������ üũ�ϰ� ���ܸ� ������ ������ ���������� []���� ����
	arr5.at(0);

	return 0;
}