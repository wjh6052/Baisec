// 14_dynamic_memorey_allocation.cpp

#include<iostream>
#include<string>

int main()
{
	int* ptr1 = new int;	// 할당
	delete ptr1;			// 해제 

	int* ptr2 = new int(17);	// 할당과 동시에 (다이렉트, 유니폼)초기화 가능
	delete ptr2;				// 해제

	// new는 할당 실패시 nullptr을 리턴하지 않기 때문에
	// c와 같이 예외처리를 하고 싶다면 (std::nothrow)를 포함하여
	// nullptr를 리턴하도록 할 수 있다.
	int* ptr3 = new(std::nothrow) int{ 7 };
	delete ptr3;




	int* ptr4 = new int[10];	// 할당과 동시에 (다이렉트, 유니폼)초기화 가능
	delete[] ptr4;				// 해제
	// 배열일때 delete시 []를 붙여줘야한다



	return 0;
}

// 과제 : new와 malloc의 차이를 조사하고 아래 코드의 문제점을 찾아보기
// '생성자'에 대해 조사하기

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
		std::cout << "A객체가 생성됨1" << std::endl;
	}

	A(int a)
	{
		std::cout << "A객체가 생성됨2" << std::endl;
	}

	int a;
};


int main()
{
	//A* a1 = new A;
	A* a2 = (A*)malloc(sizeof(A));

	return 0;
}