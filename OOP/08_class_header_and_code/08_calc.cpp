//08_calc.cpp

#include "08_calc.h"

#include<iostream>

void Test(int a)
{
	// using�� ���ο� ����� ������ ������� �ʵ��� ����
	using namespace std;
	cout << "sad";
}

inline Calc& Calc::Add(int value) { this->value += value; return *this; }

inline Calc& Calc::Sub(int value) { this->value -= value; return *this; }

inline Calc& Calc::Mul(int value) { this->value *= value; return *this; }

inline Calc& Calc::Div(int value) { this->value /= value; return *this; }

inline Calc& Calc::Mod(int value) { this->value %= value; return *this; }

// ��� �Լ��̱� ������ ��� Ŭ������ �Ҽ������� ����ؾ� ��밡���ϴ�. -> Ŭ�����̸�::�Լ��̸�(�Ű�����)
void Calc::Test(int a)
{



}
