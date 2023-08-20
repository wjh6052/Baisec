// 13_friend_class.cpp

/*
	friend Ű����
	- �ܺο��� Ŭ������ private, protected ����� ������ �� �ְ� ���ִ� Ű����
	- ������ �����ϰ� ���� �ʿ��� �����Ѵ�. -> �ܹ���
	- friend�� ����� ���� �ʴ´�.

*/

#include<iostream>
using namespace std;


//#define FRIEND_GLOBAL_FUNCTION
//#define FRIEND_MEMBER_CLASS
#define FRIEND_CLASS

#ifdef FRIEND_GLOBAL_FUNCTION
/*
	���� �Լ��� �������ִ� ���
*/
class A
{
public:
	const int& GetValue() const { return value; }

private:
	int value = 1;

	//1.
	// friend Ű���带 ����Ͽ� ���� �Լ����� Ŭ������ ������ ����� ���� ����
	friend void Test1(const A& a);

	//2.
	// friend ����� ���ÿ� �Լ��� ���Ǻ� �ۼ� ����
	// -> 1�� ����� �����ϰ� ���� �Լ��� ��޵ȴ�.
	friend void Test2(const A& a)
	{
		cout << a.value << endl;
	}

};

//1.
void Test1(const A& a)
{
	//cout << a.GetValue() << endl;

	cout << a.value << endl;
}

int main()
{
	A a;

	Test1(a);
	Test2(a);

	return 0;
}
#endif 


#ifdef FRIEND_MEMBER_CLASS
/*
	Ÿ���� �ٸ� Ŭ������ Ư�� �Լ����� �����Ϸ��� ���
*/

/*
	���� ����
	�ڿ� �ۼ��� Ŭ������ ����ü�� ���� �ڵ忡�� ������Ű�� ������ ���
*/
class B;

// ���� ������ �������� B�� ���������� ������ ��ü���� ������ �𸣴� ����
// -> B Ŭ������ �ν��Ͻ� ������ �� �� ����.
//B b1;

// ������ �ڷ����� ���� B Ŭ������ �ν��Ͻ��� �����ϴ°� �ƴ� 
// �ܼ� �ּҸ� �����ϱ� ������ ��ü���� ������ ���ʿ䰡 ���� ���� ����
B* b2;

class B* b3;

class A
{
public:
	void attack(B& b);
	// ���� ���� ���������� Ȯ�� ���� -> ����� �ȵǱ� ������ ����ο� ���Ǻθ� �и�
	//{
	//	cout << b.hp;
	//}

private:

};

class B
{
public:
	// B Ŭ�������� A::attack(B& b) �Լ����� �ڽ��� ����� ����
	friend void A::attack(B& b);

private:
	int hp = 100;
};



int main()
{
	A a;
	B b;

	a.attack(b);

	return 0;
}

void A::attack(B& b)
{
	cout << b.hp;
}

#endif 

#ifdef FRIEND_CLASS
/*
	friend class
	- Ÿ���� �ٸ� Ŭ������ ��� �������� ������ �����ϰ� ���
*/

class A
{
public:

	// ��� ��� �Լ����� ���� ����
	void Print_B_value1(class B& b);
	void Print_B_value2(class B& b);

};

class B
{
private:

	// class A���� B�� ��� ����� ���� �����ϵ��� ���
	// B���� A�� ������ �ȵȴ�. -> �ܹ���
	friend class A;

private:
	int value1 = 10;
	int value2 = 20;
};

int main()
{
	A a;
	B b;

	a.Print_B_value1(b);
	a.Print_B_value2(b);

	return 0;
}

void A::Print_B_value1(class B& b)
{
	cout << "value1 : " << b.value1 << endl;
}

void A::Print_B_value2(class B& b)
{
	cout << "value2 : " << b.value2 << endl;
}
#endif 
