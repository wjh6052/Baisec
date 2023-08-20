// 11_structures.cpp

#include<iostream>

struct Person
{
	/*
		멤버 함수는 코드 영역에 할당되어 구조체 변수의 크기에 포함이 되지 않는다
		-> 여러 Person객체를 생성하더라도 멤버 함수는 하나만 존재하여 모든 객체가 공유해서 사용

		그렇기 때문에 멤버 함수를 호출한 객체를 구분하기 위해서 해당 멤버 함수를 호출한
		객체의 포인터를 넘겨받는 형식으로 호출한 객체를 구별한다.
		-> 이러한 방식으로 함수를 호출하는 것을 thiscall 방식이라고 부른다.

		thiscall 방식은 멤버 함수를 호출하는 객체의 포인터가 필요하기 때문에
		객체 없이는 따로 호출할 수 없다.

		// 과제 : 함수 호출 규약 (function calling convension) 조사
	
	*/
	void __thiscall Print(/*Person* this*/)
	{
		this->name;
		this->age;


		std::cout << name << "의 나이는" << age << "입니다." << std::endl;
	}

	// C와 다르게 기본값 예약이 가능
	int age = 15;
	float weight;
	std::string name;
};



int main()
{
	Person p1{ 10, 50.0f, "DIDI" };

	p1.Print(/*&p1*/);

	return 0;
}