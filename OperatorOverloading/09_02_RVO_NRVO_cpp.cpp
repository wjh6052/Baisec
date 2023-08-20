// 09_02_RVO_NRVO_cpp

#include<iostream>
using namespace std;

/*
	RVO - Return Value Optimization
	- � �Լ��� ��ü�� ��ȯ�ؾ� �� ���, �ʿ����� ���� �ӽ� ��ü�� �������� �ʵ��� ����ȭ �ϴ°�
	- Debug/Release���� �ȴ�.
	- ��ȯ ��ü�� �������� ������ ���� ��� ����ȭ �ȴ�.
	- �������� ���� ��� ����ȭ�� ���� �ʾ����� NRVO�� �߰��Ǿ� �����ϰ� �Ǿ���.

	NRVO - Named Return Value Optimization
	- RVO�� ���� ������� ����ȭ�� �����Ѵ�.
	- Debug������ ����ȭ x, Release������ ����ȭ o
*/

class Test
{
public:
	Test(int value)
		: value1(value)
		, value2(count++)
	{
		cout << "constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	Test(const Test& rhs)
		: value1(rhs.value1)
		, value2(count++)
	{
		cout << "copy constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	~Test()
	{
		cout << "destructor : " << this->value1 << ", " << this->value2 << endl;
	}

public:
	static int count;

private:
	int value1;
	int value2;

};

int Test::count = 1;

// Debug, Release : �ӽð�ü ����/�Ҹ� x 
Test MakeRVO(int value) // RVO -> ��ȯ ��ü�� �̸��� ���� ��� 
{
	return Test(value);
}

// Debug	: �ӽð�ü ����/�Ҹ� o
// Release	: �ӽð�ü ����/�Ҹ� x 
Test MakeNRVO(int value) // NRVO -> ��ȯ ��ü�� �̸��� ���� ��� 
{
	Test test(value);	// �ӽð�ü�� ���������.
	return test;
}


int main()
{
	cout << "----RVO----" << endl;
	MakeRVO(1);

	cout << "----NRVO----" << endl;
	MakeNRVO(2);

	cout << "----end----" << endl;

	return 0;

}