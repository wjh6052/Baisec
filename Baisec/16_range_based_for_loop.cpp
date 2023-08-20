// 16_range_based_for_loop.cpp

#include<iostream>

int main()
{

	using namespace std;

	int fibonacci[]{ 0,1,1,2,3,5,8,13,21,34,55,89 };

	//for (int i = 0; i < sizeof(fibonacci) / sizeof(int); i++)
	//	cout << fibonacci[i] << endl;

	int a = 10;
	int b = a;


	/*
		���ӵ� �����͸� ������ �����ϴ� ��	
	*/
	for (const auto& number : fibonacci) // auto�� �ڷ����� �ڵ����� ������
		cout << number << endl;

	for (const auto& number : { 0,1,1,2,3,5,8,13,21,34,55,89 })
		cout << number << endl;


	int* test1 = new int[10];

	// for(auto t : test1) // ������ Ư���� �� �־�� ����

	struct Test
	{
		int arr[10] = { 0 };
		int a = 10;

		int* begin()
		{
			return &arr[2];
		}

		int* end()
		{
			return &arr[7] + 1;
		}
	};

	// 0 1 2 3 4 5 6 7 8 9

	Test test2;
	for (auto t : test2)
	cout << t << endl;


	return 0;
}