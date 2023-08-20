// 10_conversion_constructor.cpp

#include<iostream>
#include<cassert>
using namespace std;

/*
	conversion constructor - ��ȯ ������
	- �Ű������� �ϳ��� ������
	- �ٸ� �ڷ����� ������ �Ǹ� ������ ����ȯ�� �Ͼ�鼭 ȣ���� �ȴ�.
	- �Լ����� ��ȯ �����ڰ� �ִ� Ŭ������ �Ű������� ������ ���� �� �ӽ� ��ü�� ������ �� �ִ�.
		-> explicitŰ���带 �߰��Ͽ� ���氡��
*/

class Fraction
{
public:
	Fraction(int num, int den)
		: numerator(num)
		, denominator(den)
	{
		cout << "constructor" << endl;
	}

	Fraction(const Fraction& other)
		: numerator(other.numerator)
		, denominator(other.denominator)
	{
		cout << "copy constructor" << endl;
	}

	Fraction(int a) // �Ű������� �� �ϳ��� ������ conversion constructor�� �ȴ�. 
		: numerator(a), denominator(1)
	{
		cout << "conversion constructor" << endl;
	}

	//explicit Fraction(int a) // explicit�� ������ ����ȯ����� �ȵȴ�. 
	//	: numerator(a), denominator(1)
	//{
	//	cout << "conversion constructor" << endl;
	//}

	friend std::ostream& operator <<(std::ostream& out, const Fraction frac)
	{
		cout << frac.numerator << " / " << frac.denominator << endl;
		return out;
	}

private:
	int numerator;
	int denominator;
};

void PrintFraction(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	Fraction frac1(10, 20); // constructor -> ����Ʈ�ƴϰ� �׳� �츮�� ���� �Ϲ� ������
	Fraction frac2(frac1);  // copy constructor

	// �ٸ� �ڷ����� ���͵� ���� ����ȯ�Ͽ� ������ ȣ��
	Fraction frac3(1);      // �˸��� �ڷ����� ���� ��ȯ ������ ȣ��
	Fraction frac4('a');    // �ڷ����� �ٸ� -> int�� ����ȯ -> ������ ����ȯ�� �Ͼ
	Fraction frac5(3.14f);  // ����ȯ ������ �ڷᰡ �߸���. -> �ڷᰡ �߸� �� ������ �������� 

	PrintFraction(frac1);
	PrintFraction(frac2);

	// ��ȯ �����ڰ� ������ �ν��Ͻ��� �ƴ� ������ �Ű������� ������ �ӽð�ü�� ����� �Լ��� ȣ���� �ȴ�. 
	// �������� ����ȯ ������ �ڷᰡ �߷� ������ ���� �� �ִ�. -> �Լ� ȣ�� �� �ӽ� ��ü ������ ���� �ʹ�. -> explicit ���
	PrintFraction('a');
	PrintFraction(3.14f);
	PrintFraction(100);

	return 0;
}