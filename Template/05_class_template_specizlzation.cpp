// 05_class_template_specizlzation.cpp

#include<iostream>
using namespace std;

template<typename T>
class A
{
public:
	A(const T& input){}
	
	void DoSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void Test() {};

};


template<>
class A<char>
{
public:
	A(const char& input) {}

	void DoSomething()
	{
		cout << "char class" << endl;
	}

};



int main()
{
	A<int> a1(10);
	A<float> a2(10.0f);
	A<char> a3('a');

	a1.DoSomething();
	a2.DoSomething();
	a3.DoSomething();


	a1.Test();
	a2.Test();


	// ���ø� Ŭ������ ����� �ٸ��� ���� �� �ִ�
	//a3.Test(); // Ư���� A<char>�� Test() ����� ������ ���� ����



	return 0;
}


/*
   ���� : Storage<bool>�� Ư��ȭ

   �Ʒ��� Ŭ������ ���� ���ø� ���ڿ� ���� �����͸� 8�� �������ִ� Ŭ�����̴�.

   ���⼭ ������ ����µ� bool���� ���� �� ������ �����ϰ� �ȴ�.
   -> bool���� 1����Ʈ ũ�⸸���ε� 8������ ǥ���� �� ������ �Ʒ���
   ���� ������ ��� 1����Ʈ * 8�� ũ�⸦ ������.

   �Ʒ��� Ŭ������ ���ø� Ư��ȭ�� bool���Ͻ�
   1����Ʈ�� ������ 8���� �Ұ��� ó���� �� �ְ� ������
*/

template<typename T>
class Storage8
{
public:
	void Set(int index, const T& value)
	{
		arr[index] = value;
	}

	const T& Get(int index)
	{
		return arr[index];
	}

private:
	T arr[8];
};


/*
   ���� : ��Ʈ �����ڸ� ����Ͽ� �Ʒ��� ������ �ذ�

   2������, bool��� ����, ��Ʈ����


   1.
   int a = 123;

	  a = 0;

	  a = a ? a -> ?�� ���� �����ڰ� ���� �� �ڵ庸�� ������ �ɱ�?

   2.
   int a = 123;
   int b = 456;

   a = a ? b
   b = a ? b
   a = a ? b

   temp�� ������� �ʰ� �ٲٴ¹� ã��

   3.
	  ¦��/Ȧ�� �Ǻ� -> %������� �ʰ�

   4.
	  ����/��� �Ǻ� -> ���迬���� ��� x


   5.
	  2�� �¼����� �ƴ��� �Ǻ� -> �ݺ��� ������� �ʰ�
	  ���� �ι��� �ϸ� �� �� ����

   6.
	  �빮��/�ҹ��� ��ȯ -> +, - �Ⱦ���
	  �ƽ�Ű �ڵ��� �빮�ڴ� ������° ��Ʈ�� ��� 0�̰�
	  �ҹ��ڴ� ��� 1 �̴�.
*/