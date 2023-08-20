// 08_multi_return_values.cpp

#include<iostream>
#include<tuple>
using namespace std;

//��ȯ�� �پ��ϰ� �ϱ�
//int float func()
//{
//   //�Լ��� �ΰ��� ��ȯ�� �� ����.
//   // ����ü�� ����� �ذ��ϴ� ����� ������ �� ������ ����� ���� -> tuple
//   return 0, 0.1f; 
//}

/*
   tuple - �������� �������� ����
*/

//1.
tuple<int, int> func1() // int, int �ΰ� ���� ����
{

	return tuple<int, int>(123, 456);
}

//2
auto func2() // auto Ű���带 ����Ͽ� �����ϰ� ��ȯ�� �ۼ� ����
{
	return tuple<int, int, int>(123, 456, 789);
}

int main()
{
	//1.
	tuple<int, int> resul1 = func1();
	// get<>�� ����� tuple�� �����͸� ���� �� �ִ�.
	cout << get<0>(resul1) << ", " << get<1>(resul1) << endl;

	//2.
	auto resul2 = func2();
	cout << get<0>(resul2) << ", " << get<1>(resul2) << ", " << get<2>(resul2) << endl;

	return 0;
}