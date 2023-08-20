// 10_static_member_variable.cpp


/*
	static member variable
	- Ŭ���� ���ο� �ϳ��� �����ϴ�, Ŭ���� ��� ��ü�� �����ϴ� ����
	- ������ Ŭ��������, �ʱ�ȭ�� ���� ����(cpp)���� ���־�� �ߺ� ������ ������ �� �ִ�.
*/

#include<iostream>
using namespace std;


class Test
{
public:
	int value;

	void Add();


	/*	
		���� ��� ������ ���α׷��� �����Ҷ� �޸𸮰� �����Ǿ�� ��
		�׷��� class�� ����� ����
		-> ���⼭�� ���� ���ุ �����ϰ� ������ ���� �ʴ´�.
		-> �� �޸𸮿� �ö��� �ʴ´�
	*/
	//siatic int count = 10; // error
	static int count;

	// ���������� const Ű���带 ���̸� ����
	static const int test = 10;

	static constexpr float test2 = 10.0f;
};

// �ش� ���Ͽ��� �ʱ�ȭ�� ��� �ߺ������� �߻��� �� �ִ�
int Test::count = 0;

int main()
{
	Test t1;
	Test t2;

	t1.count = 10;
	t1.value = 10;
	 
	t2.count = 20;
	t2.value = 20;

	cout << &t1.value << ", " << t1.value << endl;
	cout << &t2.value << ", " << t2.value << endl;

	// �ν��Ͻ��� �������� �ʾƵ� ������ �����ϴ�
	cout << &Test::count << ", " << Test::count << endl;

	// �ϳ��� �����ϱ� �빮�� ���� ������
	cout << &t1.count << ", " << t1.count << endl;
	cout << &t2.count << ", " << t2.count << endl;

	return 0;
}


/*
	���� : �̱��� ���� ����
*/