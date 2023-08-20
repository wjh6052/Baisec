// 12_random_number.cpp

#include<iostream>

// c ����
#include<stdlib.h>
#include<time.h>

// c++ ����
#include<random>

int main()
{

	/*
		c style ������ ������
		- �õ尪�� ���� �ð����� �ϱ� ������ ���� �ð����� ���α׷���
		������ �õ尪�� ������.
		- %���� �����ڸ� ����� ���� ������ ���̱� ������ �յ��ϰ� ���� ��е��� ����
		- rand()��ü�� ���� �˰����� ���� �ʴ�.
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