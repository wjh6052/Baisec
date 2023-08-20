// 06_subscript_operator.cpp

#include<iostream>
#include<cassert>
#include<vector>
using namespace std;

class IntArray
{
public:
public:
	// 1.
	int Get(int index) { return list[index]; }
	void Set(int index, int value) { list[index] = value; }


	// 2.
	int* GetList() { return list; }

	// 3.
	int& operator[](int index)
	{
		// �Ź� üũ�ؾ��ؼ� ��������
		//if (index >= 10 || index < 0)
		//{
		//	//todo:
		//}

		// ����� ��忡���� üũ
		assert(index >= 0 && index < 10);

		return list[index];
	}

private:
	int list[10];
};


int main()
{
	IntArray list;

	// 1. ���ŷӴ�
	list.Set(0, 1);
	list.Set(1, 2);
	list.Set(2, 3);
	list.Set(3, 4);
	list.Set(4, 5);
	list.Set(5, 6);

	cout << list.Get(0) << endl;
	cout << list.Get(1) << endl;
	cout << list.Get(2) << endl;
	cout << list.Get(3) << endl;
	cout << list.Get(4) << endl;
	cout << list.Get(5) << endl;

	//2. �迭�� ���Ϲ޾� ��밡��
	// ������ ũ�⿡ ���� ������ ���� -> �������� �ʴ�.
	auto arr = list.GetList();
	
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << arr[3] << endl;
	cout << arr[4] << endl;

	//3. 
	list[0] = 0;
	list[1] = 1;

	IntArray* list2 = new IntArray;

	//list2[0] = 10; // �����Ϳ� �����Ŷ� error
	(*list2)[0] = 10;

	vector<int> vecs;

	// ����׿����� ����ó��
	vecs[0];
	vecs[1];
	vecs[2];

	// �����/������� ����ó��
	vecs.at(0);
	vecs.at(1);

	return 0;
}