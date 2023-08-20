// 09_Covariant.cpp

/*
   Covariant : ������ȯ��
   - �ڽ��� ������ ��ȯ�ϴ� ��� ��Ӱ��迡�� ���� ������ �Լ��� �����Ǵ� ��
   - is a �����̱� ������ �ڽ��� ������ ������ �� ���������� �ν��Ѵ�.
   - ��ȯ���� �ٸ����ص� �������̵��� ������ ���
*/

#include<iostream>
using namespace std;

class A
{
public:
	virtual A* GetThisPointer() { cout << "A" << endl; return this; }
};

class B : public A
{

public:
	B* GetThisPointer() override { cout << "B" << endl; return this; }

};