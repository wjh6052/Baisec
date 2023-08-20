// 08_overriding_and_final.cpp

/*
	Overriding
	- 파생 클래스가 기반 클래스에게 상속받은 매서드를 파생 클래스에서 재정의하는 것

	- 리턴 타입과 매개변수 구성이 서로 일치해야한다

	- 오버 라이딩된 기반 클래스의 함수는 가려지고 파생 클래스의 함수가 호출이 된다

	- 단순히 함수를 오버라이딩할 경우, 업 캐스팅시 파생 클래스의 함수가 아닌 기반 클래스의 함수가 호출된다
	그 이유는 C++ 컴파일러가 실제로 가리키는 개게의 자료형을 기준으로 하는게 아니라 포인터 변수의 자료형을 기준으로 하기 때문이다
	virtual 키워드를 사용하여 해결이 가능하다.

	- virtual
		ㅁ 자신을 호출하는 객체의 실제 타입에 맞게 함수를 호출할 수 있게 해주는 키워드
		ㅁ 기반 클래스의 함수에 키워드를 추가해주면 파생 클래스에 자동으로 상속된다

	class 동물
	{
	public:
		먹다
	};

	class 개 : 동물
	{
	public:
		먹다
	};

	class 지렁이 : 동물
	{
	public:
		먹다
	};
*/

#include<iostream>
using namespace std;
class A
//class A final
// final : 클래스를 상속시킬 수 없게 제한하는 키워드, 메서드에 붙이면 해당 메서드를 파생 클래스에서 오버라이딩하지 않게 제한
{
public:
	// virtual 키워드가 포함된 함수를 가상 함수라고 부른다
	virtual void print(int x) { cout << "A" << endl; }

private:
	int i = 0;
};

class B : public A
{
	/*
		오버 로딩은 종복된 이름을 가지는 함수들을 매개변수의 차이로 구분하여 다앙하게 만들어 사용하는 것이고
		오버 라이딩은 상속받은 매서드를 재정의하여 덮어 씌우는(재정의)하여 사용하는 것

		오버 라이딩은 부모의 함수를 재정의하여 사용하는 것이기 때문에 부모의 메서드 형태와 일치해야한다
	*/
public:
	void print(int x) /*final*/ { cout << "B" << endl; }

	/*
		override - 오버라이드 키워드
		- 파생 클래스에서 오버라이딩한 함수에 붙일 수 있다
		- 오버 라이딩이 가능한 함수인지 판단해주고(맞는 형태가 있는지) 없다면 에러를 발생시킨다
		- 오버 라이딩이 된 함수임을 명시적으로 표시한다. -> 코드 가독성이 향상된다
	*/

};


class C : public B
{
public:
	// 상속받은 메서드에 final 키워드가 존재한다면 오버 라이딩이 안됨
	void print(int x) { cout << "C" << endl; }

};


int main()
{
	A a;
	B b;
	C c;

	A& ab = b;
	A& ac = c;

	a.print(0);
	ab.print(0);
	ac.print(0);


	return 0;
}