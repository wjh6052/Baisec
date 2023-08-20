// 11_assignment_operator.cpp

// deep copy vs shallow copy 
// ���� ����  vs ���� ����

#include<iostream>
#include<cassert>
using namespace std;

class MyString
{
public:
	MyString(const char* const src = "")
	{
		assert(src);

		length = strlen(src) + 1; // ���鹮�ڸ� �����ϰ� ������ ���־� +1 ���ش�.
		data = new char[length];

		for (int i = 0; i < length; i++)
			data[i] = src[i];

		data[length - 1] = '\0';
	}

	~MyString()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	// ���� ������
	MyString(const MyString& other)
	{
		cout << "copy constructor" << endl;

		/*
			shallow copy
			������ �ִ� ���� �״�� �����ϴ� ��
			���� : �����Ͱ� ����ɰ�� �ּҰ��� �����ϰԵǴµ� �ش� �����͸�
			Ŭ���� �Ҹ��ڿ��� �����ϰ� �ȴٸ� ���� �ּҸ� 2�� �̻� �����ϰԵǴ� ������ �߻�
		*/
		//length = other.length;
		//data = other.data;

		/*
			deep copy
			�ʿ��� ��� ���ο� ������ �Ҵ��Ͽ� ����
			-> �����Ҵ��� �ؾ��ϹǷ� ���� ���纸�ٴ� ����
		*/

		length = other.length;
		if (other.data != nullptr)
		{
			data = new char[length];
			for (int i = 0; i < length; i++)
				data[i] = other.data[i];
		}
		else
			data = nullptr;
	}

	// �̵� ������
	// ���� ��ü�� �������� ���� -> ���̻� �ܺο� ������ �������� ����
	MyString(MyString&& other)
	{
		cout << "move constructor" << endl;

		data = std::move(other.data);
		length = std::move(other.length);

		/*
			�޴� �Ű����� other�� ���̻� �ܺο� �������� �ʴ´ٰ� �����Ѵ�.
			�׷��� ������ other�� �����͸� �ʱ�ȭ�Ͽ� ���̻� �������� ���ϵ��� ���°� �����ϴ�.
		*/
		other.data = nullptr;
		other.length = 0;
	}

	// ���� ���� ������
	MyString& operator =(const MyString& other)
	{
		cout << "copy assignment operator" << endl;

		// ������ �ڵ带 ��������� �����ؾ��� ��
		
		// 1. prevent self-assignment, �ڽ��� �Ҵ��ϴ� �� ����
		if (this == &other)
			return *this;

		//2. data�� �̸� �Ҵ�Ǿ��ִ� �޸𸮰� �ִٸ� ����
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}

		length = other.length;
		if (other.data != nullptr)
		{
			data = new char[length];
			for (int i = 0; i < length; i++)
				data[i] = other.data[i];
		}
		else
			data = nullptr;

	}


	// �̵� ���� ������
	MyString& operator =(MyString&& other)
	{
		cout << "move assignment operator" << endl;

		// ������ �ڵ带 ��������� �����ؾ��� ��

		// 1. prevent self-assignment, �ڽ��� �Ҵ��ϴ� �� ����
		if (this == &other)
			return *this;

		//2. data�� �̸� �Ҵ�Ǿ��ִ� �޸𸮰� �ִٸ� ����
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}

		data = std::move(other.data);
		length = std::move(other.length);

		/*
			�޴� �Ű����� other�� ���̻� �ܺο� �������� �ʴ´ٰ� �����Ѵ�.
			�׷��� ������ other�� �����͸� �ʱ�ȭ�Ͽ� ���̻� �������� ���ϵ��� ���°� �����ϴ�.
		*/
		other.data = nullptr;
		other.length = 0;
	}

public:
	char* data = nullptr;
	int length = 0;
};

int main()
{

	MyString str("Hello");

	//copy
	{
		MyString copy(str);

		copy = str;
	}

	//move
	{
		MyString move(std::move(str));

		move = std::move(str);
	}

	return 0;
}