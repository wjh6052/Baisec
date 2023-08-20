// 01_class.cpp

/*
	PP	- procedure programming			- ���μ���(�Լ�) ���α׷���	-> �Լ� ������ ����
	OOP	- Object Oriented Programming	- ��ü ���� ���α׷���		-> ��ü ������ ����
*/

/*
	��ü(Object) -> class + Instance
	- class
		�� ������ �������� ���� ���赵, Ȥ�� ��� ��) dna, �ؾ�v, �ڵ��� ���赵...
		�� �繰�� ����� �Ӽ��� ������ ���� ��� ����(data)�� ��� �Լ�(method)�� ����� ǥ��(�߻�ȭ)

	- Instance
		�� class�� ���� ������� ��ü
		�� class�� �ϳ����� �ϳ��� class�� ���� �پ��� instance�� �����Ѵ�
		��) �ڵ��� ���赵 �ϳ��� ������ ���赵�� �ִ� �ڵ����� ��� ���� �� �ִ�
*/

/*
	��ü���� 3���

	ĸ��ȭ(Encpulation)
	- ��ü�� �Ӽ�(��� ����)�� ����(��� �Լ�)�� Ŭ������ ���� ��
	- ���� �����ڸ� ���� �ܺο� �ʿ��� ���븸 �����ϰ� �������� �����
		-> ���� ����(Information hiding)
	- �ʿ��� ������ ������ ����ϱ� �����Ѵ�. ��) �������� ��ư�� �����ϸ� ���� ȸ�θ� ���� ��밡��

	���(Inheritance)
	- ���� Ŭ������ �Ӽ��� ����� �����޴� ���� Ŭ������ ����� �Ӽ��� ����� Ȯ���� �� �ִ�
	- �θ� Ŭ���� �ڽ� Ŭ������� �θ���

	������(Polymorphism)
	- �ϳ��� ��ü�� �������� ������ �ڷ����� ���� �� �ִ°�
		-> �پ��� ���·� ��ü�� ǥ������
		�� ���� ���̵�
			�� �θ� Ŭ�������� ��ӹ��� �ż��带 �ڽ� Ŭ�������� ������ �ϴ� ��
		�� ���� �ε�
			�� ���� �̸��� ���� �ż��带 ���ڰ��� ���³� ������ �ٸ����Ͽ�
				�ٸ� ����� �����ϵ��� ���� �ϴ� ��
*/

#include<iostream>
#include<string>

using namespace std;

class Person // ���, ���赵 -> �߻�ȭ
{ // ĸ��ȭ

	// ���� ������: ���� ������ �����Ѵ�
public: // ��ο��� ����
	virtual void Work()
	{
		cout << "Person" << endl;
	}

	void Sleep()
	{

	}

	// ���� ����
protected: // �ڽŰ� �ڽ� Ŭ���� ���ο����� ���ٰ���

private: // �ڽ�(Ŭ��������)�� ���ٰ���
	std::string name;
	int age;
	float height;
	float weight;


};

// ��� : Person�� ��ӹ޴� Workerl
class Worker1 : public Person
{
public:
	// Person::Work �Լ��� �ڽ� Ŭ�������� ������
	void Work()
	{
		cout << "Worker1" << endl;
	}
};




int main()
{
	Person p; // instance
	//p.age; // ���е� ���� ���� -> error
	p.Work();// ������ ������� ���ٰ���

	Worker1 w1;
	w1.Work();

	Person* p_w = new Worker1();
	p_w->Work();

	return 0;

}





