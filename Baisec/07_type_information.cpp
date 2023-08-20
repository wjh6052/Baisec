// 07_type_information.cpp

/*
   RTTI - Run Time Type Information
   - ��Ÿ�� �߿� �ǽð����� ������ Ÿ�Կ� ���� ������ ��� ���
   - �̰� �����־�� typeif()����� �ڷ����� ����� �д´�.
   - dynamic_cast�� ����Ҷ��� �ʿ��ϴ�.
   - ��Ÿ�Ӷ� �ڷ����� �о���°Ŷ� ������.
*/

/*
   ���� RTTI ����
*/

#include<iostream>
#include<typeinfo> // typeid

//int add(int a, int b) { return a + b; }
//short add(short a, short b) { return a + b; }
//float add(float a, float b) { return a + b; }

template<typename T>
T add(T a, T b)
{
	std::cout << "a : " << typeid(a).name() << std::endl;
	std::cout << "b : " << typeid(b).name() << std::endl;

	return a + b;
}

int main()
{
	add<int>(10, 20);
	add<float>(10, 20);

	return 0;
}
