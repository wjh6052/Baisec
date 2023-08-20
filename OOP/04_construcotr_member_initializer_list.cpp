// 04_construcotr_member_initializer_list.cpp

#include<iostream>


using namespace std;

class Data
{
public:
	Data(int a, int b, int c)
		// ��� �ʱ�ȭ ����Ʈ�� ����� ������ ���ÿ� ���� �־��� �� �ִ�.
		:a(a), 
		b{b}, 
		c(this->a - c),
		d(c)
	{
		// �̹� a,b,c �޸𸮰� ������� ���·� ����Ǿ�
		// const ��� ������ ������ �ȵ�
		//this->a = a;
		//this->b = b;
		//this->c = c;

	}

private:
	const int a;
	const int b;
	const int c;
	int& d;
};

int main()
{
	Data d(10, 20, 30);
	
	return 0;
}