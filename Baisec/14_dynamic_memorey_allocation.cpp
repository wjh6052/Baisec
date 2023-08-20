// 14_dynamic_memorey_allocation.cpp

#include<iostream>
#include<string>

int main()
{
	int* ptr1 = new int;	// �Ҵ�
	delete ptr1;			// ���� 

	int* ptr2 = new int(17);	// �Ҵ�� ���ÿ� (���̷�Ʈ, ������)�ʱ�ȭ ����
	delete ptr2;				// ����

	// new�� �Ҵ� ���н� nullptr�� �������� �ʱ� ������
	// c�� ���� ����ó���� �ϰ� �ʹٸ� (std::nothrow)�� �����Ͽ�
	// nullptr�� �����ϵ��� �� �� �ִ�.
	int* ptr3 = new(std::nothrow) int{ 7 };
	delete ptr3;




	int* ptr4 = new int[10];	// �Ҵ�� ���ÿ� (���̷�Ʈ, ������)�ʱ�ȭ ����
	delete[] ptr4;				// ����
	// �迭�϶� delete�� []�� �ٿ�����Ѵ�



	return 0;
}

// ���� : new�� malloc�� ���̸� �����ϰ� �Ʒ� �ڵ��� �������� ã�ƺ���
// '������'�� ���� �����ϱ�

//struct Test
//{
//	int a;
//	int b;
//	std::string str;
//};
//
//int main()
//{
//	//Test* test = new Test;
//	Test* test = (Test*)malloc(sizeof(Test));
//
//	test->a = 10;
//	test->b = 20;
//	test->str = "Hello!!";
//
//	std::cout << test->a << std::endl;
//	std::cout << test->b << std::endl;
//	std::cout << test->str << std::endl;
//
//	return 0;
//}


struct A
{
	A()
	{
		std::cout << "A��ü�� ������1" << std::endl;
	}

	A(int a)
	{
		std::cout << "A��ü�� ������2" << std::endl;
	}

	int a;
};


int main()
{
	//A* a1 = new A;
	A* a2 = (A*)malloc(sizeof(A));

	return 0;
}