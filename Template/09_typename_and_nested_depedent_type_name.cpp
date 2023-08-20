// 09_typename_and_nested_depedent_type_name.cpp


#include<iostream>
#include<vector>
using namespace std;

class A
{
public:
	using my_int = int;


};

template<typename T>
class B
{
public:

	/*
		���ø� ���ο��� ��ø ���� Ÿ�� �̸��� ����� �� typename�� ����ؾ� �Ѵ�

		dependent - ���� �̸�
		- ���� typename Tó�� Ÿ���� ���ڷ� �޾� ����� �� T�� ���� �̸��̶�� �θ���

		nested dependent type name - ��ø ���� Ÿ�� �̸�
		- ���� �̸��ӿ� �ٸ� Ÿ���� ���ǵ� ��쿡 ��ø ���� Ÿ�� �̸��̶�� �θ���
			-> EX) T::my_int
	*/

	//T::my_int i;


	typename T::my_int i;

};




int main()
{

	B<A> test;

	return 0;
}