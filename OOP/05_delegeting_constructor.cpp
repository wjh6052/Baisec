// 05_delegeting_constructor.cpp

/*
	delegeting constructor - ���� ������
	- ���� Ŭ�������� �����ڰ� �ٸ� �����ڸ� ȣ���ϴ� ��
*/

#include<iostream>
#include<string>
using namespace std;

class Student1
{
public:
	Student1(const int& id, const std::string& name)
		: id(id), name(name)
	{
		//...
		//...
		//...
		//...
		//...
	}

	//Student1(const std::string& name)
	//	: Student1(0, name) // Student1(id, name) ������ �����ڿ��� ������ ����
	//{
	//	// Student1(0, name)�� �۾��� ������ ó���Ǵ� �ڵ�
	//}

	// �̿Ͱ��� �پ��� ������� �ʱ�ȭ �� �� ������ �ʱ�ȭ ����� �ϳ��� �����ϴ°� ���������ϱ⿡ ����

private:
	int id;
	std::string name;
};


class Student2
{
public:
	Student2(const int& id, const std::string& name)
	{
		Initialize(id, name);
	}

	Student2(const std::string& name)
	{
		Initialize(0, name);
	}

	void Initialize(const int& id, const string& name)
	{
		//TODO:
	}

private:
	int id;
	std::string name;
};

int main()
{

	return 0;
}