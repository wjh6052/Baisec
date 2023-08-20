// 01_arithmatic_operator.cpp


//#define Case1
#define Case2

#ifdef Case1
#include<iostream>

using namespace std;

class Won
{
public:
	Won(int value) : value(value) {}

	int GetValue() const
	{
		return value;
	}

private:
	int value;

	friend int operator+(const Won& lhs, const Won& rhs);

	friend Won operator-(const Won& lhs, const Won& rhs)
	{
		// ��ȯ ���� ������ �����ڰ� ������ ����
		return lhs.value - rhs.value;
	}
};

/*
	���� : ��� �Լ�
		- �����ϰ� ����
		- ��� �Լ��� ����� �Ǻ���ġ ���� ����
		- (�ʼ�x)��� �Լ��� ����� �ϳ��� ž ����
*/

int operator + (const Won& lhs, const Won& rhs)
{
	return lhs.value + rhs.value;
}

int main()
{
	Won l(10), r(20);

	int rl = l + r;

	cout << rl << endl;

	cout << (l - r).GetValue() << endl;

	return 0;
}
#endif


#ifdef Case2
#include<iostream>

using namespace std;

class Won
{
public:
	Won(int value) : value(value) {}

	int GetValue() const
	{
		return value;
	}

	int operator+(const Won& rhs)
	{
		return value + rhs.value;
	}
	Won operator-(const Won& rhs)
	{
		return value - rhs.value;
	}

private:
	int value;

};



int main()
{
	Won l(10), r(20);

	int rl = l + r;

	cout << rl << endl;

	cout << (l - r).GetValue() << endl;

	return 0;
}
#endif

/*
	����
	- Won class�� ������ �����ε� �߰��ϱ�
	- ���ϱ�, ������, ������
	- += -= *= /= %=
*/
