// 01_class.cpp

/*
	PP	- procedure programming			- 프로세서(함수) 프로그래밍	-> 함수 단위로 실행
	OOP	- Object Oriented Programming	- 객체 지향 프로그래밍		-> 객체 단위로 실행
*/

/*
	객체(Object) -> class + Instance
	- class
		ㅁ 무엇을 만들지에 대한 설계도, 혹은 상상 예) dna, 붕어빵틍, 자동차 설계도...
		ㅁ 사물의 공통된 속성과 동작을 각각 멤버 변수(data)와 멤버 함수(method)로 만들어 표현(추상화)

	- Instance
		ㅁ class를 통해 만들어진 실체
		ㅁ class는 하나지만 하나의 class를 통해 다양한 instance가 존재한다
		예) 자동차 설계도 하나만 있으면 설계도에 있는 자동차를 계속 만들어낼 수 있다
*/

/*
	객체지향 3요소

	캡슐화(Encpulation)
	- 객체의 속성(멤버 변수)와 동작(멤버 함수)를 클래스로 묶는 것
	- 접근 지정자를 통해 외부에 필요한 내용만 공개하고 나머지는 숨긴다
		-> 정보 은닉(Information hiding)
	- 필요한 정보만 공개해 사용하기 쉽게한다. 예) 리모컨은 버튼만 조작하면 내부 회로를 몰라도 사용가능

	상속(Inheritance)
	- 상위 클래스의 속성과 기능을 물려받는 하위 클래스를 만들어 속성과 기능을 확장할 수 있다
	- 부모 클래스 자식 클래스라고도 부른다

	다형성(Polymorphism)
	- 하나의 객체가 여러가지 형태의 자료형을 가질 수 있는것
		-> 다양한 형태로 객체를 표현가능
		ㅁ 오버 라이딩
			ㄴ 부모 클래스에서 상속받은 매서드를 자식 클래스에서 재정의 하는 것
		ㅁ 오버 로딩
			ㄴ 같은 이름을 가진 매서드를 인자값의 형태나 개수를 다르게하여
				다른 기능을 수행하도록 정의 하는 것
*/

#include<iostream>
#include<string>

using namespace std;

class Person // 상상, 설계도 -> 추상화
{ // 캡슐화

	// 접근 지정자: 접근 범위를 제어한다
public: // 모두에게 공개
	virtual void Work()
	{
		cout << "Person" << endl;
	}

	void Sleep()
	{

	}

	// 정보 은닉
protected: // 자신과 자식 클래스 내부에서만 접근가능

private: // 자신(클래스내부)만 접근가능
	std::string name;
	int age;
	float height;
	float weight;


};

// 상속 : Person을 상속받는 Workerl
class Worker1 : public Person
{
public:
	// Person::Work 함수를 자식 클래스에서 재정의
	void Work()
	{
		cout << "Worker1" << endl;
	}
};




int main()
{
	Person p; // instance
	//p.age; // 은닉된 정보 접근 -> error
	p.Work();// 공개된 멤버에만 접근가능

	Worker1 w1;
	w1.Work();

	Person* p_w = new Worker1();
	p_w->Work();

	return 0;

}





