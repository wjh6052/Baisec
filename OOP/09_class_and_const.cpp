// 09_class_and_const.cpp

#include<iostream>
using namespace std;

/*
   const 멤버 함수
   - 해당 멤버 함수에서는 내부에서 멤버 변수가 상수화 된다. -> 수정 불가능
   - mutable을 사용한 멤버 변수는 예외
*/

class Data
{
public:

	Data() : value1(0), value2(0) {}

	int& GetValue1() { cout << "not const" << endl; return value1; }

	//int& GetValue1() const // 함수의 선언부와 정의부 사이에 const 키워드 -> const 멤버 함수
	//	// const가 붙으면 멤버 함수가 const화 된다
	//{ 
	//	// const Data * this
	//	// -> const 멤버 함수에서는 this가 상수화, this의 멤버를 수정할 수 없다.
	//	this;

	//	cout << "const" << endl;

	//	// 상수화 되어 수정이 불가능 L-value
	//	//value1 = 10;

	//	// value가 상수 데이터이기 때문에 &형태로 반환이 불가능
	//	// -> 우회적으로 수정할 수 있는 부분을 잡아줌
	//	return value1;
	//}

	const int& GetValue1() const { cout << "const"; return value1; }


private:
	int value1;
	mutable int value2; // mutable : const 함수 내부에서도 변경이 가능해진다.
};

void Print(const Data& data)
{
	data.GetValue1();
}

int main()
{
	Data data1;
	const Data data2;

	data1.GetValue1();
	data2.GetValue1();

	return 0;
}