// 09_enum_class.cpp

#include<iostream>

int main()
{
	// c style enum�� ������
	{
		// �ߺ������� �ذ��ϱ����� ����̸� �տ� �ڷ����� �̸��� �ٿ���� �Ѵ�.

		// ���� ���� ������������ ������ �޶� �����ϱ� ���� �̸��� �ٿ�����
		enum Color
		{
			Color_Red,
			Color_Blue
		};

		enum Tint_Color
		{
			Tint_Color_Red,
			Tint_Color_Blue
		};
		
		enum Fruit
		{
			APPLE,
			BANANA
		};

		// ���������� ������ �������̱� ������ ������� �ڷ������� �Ͻ��� ĳ������ ��
		int test_color = Color_Red;

		Color color = Color_Red;
		Fruit fruit = APPLE;

		// �ٸ� �ǹ̸� ������ �������� ���������� ������ �������̱� ������ �񱳰� ����
		if (color == fruit)
		{

		}

		// �ٸ� �ǹ̸� ������ �������� ���������� ������ �������̱� ������ �񱳰� ����
		if (color == 0)
		{

		}

	}

	/*
		Scoped Enumerations(c++ 11)
		- ���� ���� ������
	*/

	{
		enum class BaseColor : unsigned long long int // �ڷ����� ������ �� �� �ִ�. �Ǽ���, �������� �ȵ�
		{
			Red,
			Blue,
		};

		enum class BaseTintColor
		{
			Red,
			Blue
		};

		// �̸������� ������ �ٿ��� �ϹǷ� �ߺ� ������ �ذ��� �� �ִ�
		BaseColor::Red;
		BaseTintColor::Red;

		BaseColor c = BaseColor::Red;
		BaseTintColor tc = BaseTintColor::Red;

		// ���� Ÿ�Գ����� �� ����
		//if (c == tc)
		{

		}

		if (static_cast<int>(c) == 0)
		{

		}

		// �ѹ��� �ڵ��ϼ� ����
		// switch �ڵ��ϼ� -> ������ ������ �ڷ��� �Է� -> �ƹ� ��ġ�� ���콺 ��Ŭ�� 
		switch (c)
		{
		case BaseColor::Red:
			break;
		case BaseColor::Blue:
			break;
		default:
			break;
		}

	}

	return 0;
}