// 06_destructor.cpp

#include<iostream>

using namespace std;

class Test
{
public:
	Test()
	{
		cout << "constructor" << endl;
	}

	// ~ : tilde(not, ������ �ǹ�)
	~Test() // �Ҹ���
	{
		cout << "destructor" << endl;
	}

private:

};

class IntArray
{
public:
	IntArray(const int& in_length)
	{
		length = in_length;
		arr = new int[length];
		cout << "constructor!!" << endl;
	}
	~IntArray()
	{
		delete[] arr;
		cout << "destructor!!" << endl;
	}

private:
	int* arr = nullptr;
	int length = 0;
};


int main()
{
	class IntArray
{
public:
   IntArray(const int& in_length)
   {
      length = in_length;
      arr = new int[length];
      cout << "constructor!!" << endl;
   }

private:
   int* arr = nullptr;
   int length = 0;
};
	Test a;


	{
		while (true)
		{
			// �Ҹ��Ҷ� ���������� ������ �޸𸮸� �������� ���Ѵٸ� �޸� ���� �߻�
			// -> �Ҹ��Ҷ� �޸𸮸� ������ ���̹Ƿ� �Ҹ��ڿ� �޸� ���� �ڵ带 �����ִ°� �����ϰ� ����
			IntArray my_arr(1000);
		}

	}

	return 0;
}