// 01_stl_and_container.cpp

/*
	STL
	- �����̳�(container), �ݺ���(iterator), �˰���(algorithm) ������� �̷���� ���̺귯��
	- ���ø��� ����Ͽ� ��� Ÿ���� �����ͷ� ���� ���̺귯���� ����� �� �ֵ��� �Ϲ�ȭ �Ͽ���.
		-> �ڷ����� �Ϲ�ȭ �Ͽ� �ڵ��� �������� ������ �۾��� ������ �� �ְ� �Ͽ���

	�����̳�(container)
	- ���� Ÿ���� �����͸� ������ �� �ִ�

	�ݺ���(iterator)
	- �����̳ʿ� ������ ���ҿ� ������ �� ����Ѵ�

	�˰���(algorithm)
	- �ݺ��ڵ��� ������ �Ϸ��� �۾��� �����Ѵ�

	// ���� : std, stl ����
*/

/*
	container - �����̳�
	- ������ �ڷ����� ���� ��ü�� �����ϴ� ���� Ȥ�� ����Ҹ� �ǹ��Ѵ�
	- ���ø��� ����� �����ϴ� �������� �ڷ����� �����ϰ� �����̵� ���� �� �ֵ��� ����Ǿ��ִ�
	- sequence, associative, adapter �����̳� ������ �ִ�.
*/

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
using namespace std;

void Sequence_Container();
void Associative_Container();
void Container_Adapter();

int main()
{
	Sequence_Container();
	Associative_Container();
	Container_Adapter();


	return 0;
}

/*
	sequence container
	- �迭ó�� �����͸� �������� �����ϴ� �����̳�
	- Ư���� �����̳� ��Ģ���� ���Ҹ� �����Ѵ�
*/

void Sequence_Container()
{

	{
		vector<int> vec; //template�̸� template Ŭ������ ������� ��ü(�迭ó�� �������� �޸𸮸� ������ ����)
		for (int i = 0; i < 10; i++)
			vec.push_back(i);

		for (const auto& ele : vec)
			cout << ele << ' ';
		cout << endl;
	}

	{
		deque<int> deq;
		for (int i = 0; i < 10; i++)
		{
			deq.push_back(i);
			deq.push_front(i);
		}

		for (const auto& ele : deq)
			cout << ele << ' ';
		cout << endl;
	}

	{
		list<int> list;

		for (int i = 0; i < 10; i++)
			list.push_back(i);

		for (const auto& ele : list)
			cout << ele << ' ';
		cout << endl;
	}


}

/*
	associative container
	- �����͸� ������ ��Ģ�� ���� �����ϰ� �����ϴ� �����̳�
	- ����� ����� ��ġ�� ������ �� ���� RB-Tree�� �ؽ� ���̺��� �̿��Ͽ� ������ �Ǿ��ִ�
	- ���Ҹ� ������ ��� �ڵ����� �������ֱ⶧���� Ž���� ������
	- Ű(key) - ��(value) ������ ������
	=> Ư���� Ű���� ������ �����ϴ� ���� �����ش�
*/

void Associative_Container()
{


}

/*
	adapter container
	- ������ �����̳��� �������̽��� �����Ͽ� ���� ����� ���ѵǰų� ������ �����̳�
	- ������ ���ʰ� �Ǵ� Ŭ������ �������̽��� �����Ͽ� Ư�� ������ ���۸��� �����ϵ��� �Ѵ�
	- �ݺ��ڸ� �������� �ʾ� stl �˰��� ����� �ȵȴ�
*/

void Container_Adapter()
{


}