// 09_class_and_const.cpp

#include<iostream>
using namespace std;

/*
   const ��� �Լ�
   - �ش� ��� �Լ������� ���ο��� ��� ������ ���ȭ �ȴ�. -> ���� �Ұ���
   - mutable�� ����� ��� ������ ����
*/

class Data
{
public:

	Data() : value1(0), value2(0) {}

	int& GetValue1() { cout << "not const" << endl; return value1; }

	//int& GetValue1() const // �Լ��� ����ο� ���Ǻ� ���̿� const Ű���� -> const ��� �Լ�
	//	// const�� ������ ��� �Լ��� constȭ �ȴ�
	//{ 
	//	// const Data * this
	//	// -> const ��� �Լ������� this�� ���ȭ, this�� ����� ������ �� ����.
	//	this;

	//	cout << "const" << endl;

	//	// ���ȭ �Ǿ� ������ �Ұ��� L-value
	//	//value1 = 10;

	//	// value�� ��� �������̱� ������ &���·� ��ȯ�� �Ұ���
	//	// -> ��ȸ������ ������ �� �ִ� �κ��� �����
	//	return value1;
	//}

	const int& GetValue1() const { cout << "const"; return value1; }


private:
	int value1;
	mutable int value2; // mutable : const �Լ� ���ο����� ������ ����������.
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