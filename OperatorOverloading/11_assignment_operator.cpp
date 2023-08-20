// 11_assignment_operator.cpp

// deep copy vs shallow copy 
// 깊은 복사  vs 얕은 복사

#include<iostream>
#include<cassert>
using namespace std;

class MyString
{
public:
	MyString(const char* const src = "")
	{
		assert(src);

		length = strlen(src) + 1; // 공백문자를 제외하고 개수를 세주어 +1 해준다.
		data = new char[length];

		for (int i = 0; i < length; i++)
			data[i] = src[i];

		data[length - 1] = '\0';
	}

	~MyString()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	// 복사 생성자
	MyString(const MyString& other)
	{
		cout << "copy constructor" << endl;

		/*
			shallow copy
			가지고 있는 값을 그대로 전달하는 것
			문제 : 포인터가 복사될경우 주소값을 공유하게되는데 해당 포인터를
			클래스 소멸자에서 해제하게 된다면 같은 주소를 2번 이상 해제하게되는 문제가 발생
		*/
		//length = other.length;
		//data = other.data;

		/*
			deep copy
			필요한 경우 새로운 공간을 할당하여 복사
			-> 동적할당을 해야하므로 얕은 복사보다는 느림
		*/

		length = other.length;
		if (other.data != nullptr)
		{
			data = new char[length];
			for (int i = 0; i < length; i++)
				data[i] = other.data[i];
		}
		else
			data = nullptr;
	}

	// 이동 생성자
	// 원본 자체를 가져오는 개념 -> 더이상 외부에 원본이 존재하지 않음
	MyString(MyString&& other)
	{
		cout << "move constructor" << endl;

		data = std::move(other.data);
		length = std::move(other.length);

		/*
			받는 매개변수 other는 더이상 외부에 존재하지 않는다고 가정한다.
			그렇기 때문에 other의 데이터를 초기화하여 더이상 접근하지 못하도록 막는게 안전하다.
		*/
		other.data = nullptr;
		other.length = 0;
	}

	// 복사 대입 연산자
	MyString& operator =(const MyString& other)
	{
		cout << "copy assignment operator" << endl;

		// 안전한 코드를 만들기위해 주의해야할 점
		
		// 1. prevent self-assignment, 자신을 할당하는 것 방지
		if (this == &other)
			return *this;

		//2. data에 미리 할당되어있는 메모리가 있다면 해제
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}

		length = other.length;
		if (other.data != nullptr)
		{
			data = new char[length];
			for (int i = 0; i < length; i++)
				data[i] = other.data[i];
		}
		else
			data = nullptr;

	}


	// 이동 대입 연산자
	MyString& operator =(MyString&& other)
	{
		cout << "move assignment operator" << endl;

		// 안전한 코드를 만들기위해 주의해야할 점

		// 1. prevent self-assignment, 자신을 할당하는 것 방지
		if (this == &other)
			return *this;

		//2. data에 미리 할당되어있는 메모리가 있다면 해제
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}

		data = std::move(other.data);
		length = std::move(other.length);

		/*
			받는 매개변수 other는 더이상 외부에 존재하지 않는다고 가정한다.
			그렇기 때문에 other의 데이터를 초기화하여 더이상 접근하지 못하도록 막는게 안전하다.
		*/
		other.data = nullptr;
		other.length = 0;
	}

public:
	char* data = nullptr;
	int length = 0;
};

int main()
{

	MyString str("Hello");

	//copy
	{
		MyString copy(str);

		copy = str;
	}

	//move
	{
		MyString move(std::move(str));

		move = std::move(str);
	}

	return 0;
}