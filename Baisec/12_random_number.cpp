// 12_random_number.cpp

#include<iostream>

// c 난수
#include<stdlib.h>
#include<time.h>

// c++ 난수
#include<random>

int main()
{

	/*
		c style 난수의 문제점
		- 시드값을 현재 시간으로 하기 때문에 같은 시간대의 프로그램이
		동일한 시드값을 가진다.
		- %같은 연산자를 사용해 값의 범위를 줄이기 때문에 균등하게 값이 배분되지 않음
		- rand()자체의 난수 알고리즘이 좋지 않다.
	*/
	{
		srand((unsigned int)time(NULL));

		for (int i = 0; i < 10; i++)
			printf("%d, ", rand() % 10);
		printf("\n");
	}

	//c++ style
	{
		std::random_device rd;

		std::mt19937_64 merssenne(rd());

		std::uniform_int_distribution<> dice(1, 6);

		for (int i = 0; i < 10; i++)
			std::cout << dice(merssenne) << ", ";
		std::cout << std::endl;
	}

	return 0;
}