// 15_pure_virtual_function_and_abstract_class.cpp

/*
	pure virtual function - 순수 가상 함수
	- 파생 클래스에서 반드시 재정의해야 하는 함수
	- 동작을 정의하는 정의부가 없다
	- 정의 되지 않은 함수이므로 순수 가상 함수를 포함한 클래스는
	인스턴스화가 안되고 상속으로만 사용해야한다 -> 참조 형태의 자료형은 선언 가능

	abstract class - 추상 클래스
	- 하나 이상의 순수 가상 함수를 포함한 클래스

	interface - 인터페이스
	- 순수 가상 함수로만 이루어진 클래스

	과제 : 인터페이스를 사용하는 이유 조사하기
*/

#define 순수_가상함수_추상_클래스
#define 인터페이스

#include<iostream>
#include<string>
using namespace std;

// 과제 : SOLID 조사하기

#ifdef 순수_가상함수_추상_클래스

class Animal
{
public:
	Animal(const string& name): name(name){}

	const string& GetName() const { return name; }

	// 순수 가상 함수
	virtual void speak() const = 0;

private:
	string name;
};


class Cat : public Animal
{
public:
	Cat(string name) : Animal(name) {}
	void Speak() const { cout << "Meow" << endl; }
};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name) {}
	void Speak()const { cout << "Woof" << endl; }
};

class Fox : public Animal
{
public:
	Fox(string name) : Animal(name) {}
};

#endif 

#ifdef 인터페이스

class IErrorLog
{
public:
	virtual ~IErrorLog() = default;
	virtual bool ReportError(const char* const error) = 0;
};

class FileErrorLog : public IErrorLog
{
public:
	virtual bool ReportError(const char* error) override
	{
		cout << "Writting error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	virtual bool ReportError(const char* error) override
	{
		cout << "Printing error to a console" << endl;
		return true;
	}
};


void DoSomething(IErrorLog& log)
{
	log.ReportError("Error");
}

int main()
{
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	DoSomething(file_log);
	DoSomething(console_log);
}

#endif 


int main()
{
	Cat cat("DiDi");
	Dog dog("Corgi");

	cat.Speak();
	dog.Speak();

	// 순수 가상 함수를 가지는 클래스 이므로 실체화 불가능
    //Animal ani("lala"); 
    //ani.Speak();

	// 상속받은 순수 가상 함수를 재정의 하지 않아 에러
    //Fox fox("RURU");
    //fox.Speak();

	return 0;
}