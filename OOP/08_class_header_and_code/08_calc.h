#pragma once
// 08_calc.h

// �̸������� ��� �˾ƺ���
// #include<iostream>
//using namespace std;

void Test(int a);

//class�� �ٸ� �������� ���̴� ��찡 ���� ������ ���� header�� �� �ִ�
//�Լ��� ����� ������Ͽ� �ΰ� ���Ǻδ� �ҽ����Ϸ� �Ѱ��ش�.

class Calc
{
public:
	Calc(int value) : value(value) {}

    Calc& Add(int value);
    Calc& Sub(int value);
    Calc& Mul(int value);
    Calc& Div(int value);
    Calc& Mod(int value);

    void Test(int a);

private:
	int value;
};