// 11_structures.cpp

#include<iostream>

struct Person
{
	/*
		��� �Լ��� �ڵ� ������ �Ҵ�Ǿ� ����ü ������ ũ�⿡ ������ ���� �ʴ´�
		-> ���� Person��ü�� �����ϴ��� ��� �Լ��� �ϳ��� �����Ͽ� ��� ��ü�� �����ؼ� ���

		�׷��� ������ ��� �Լ��� ȣ���� ��ü�� �����ϱ� ���ؼ� �ش� ��� �Լ��� ȣ����
		��ü�� �����͸� �Ѱܹ޴� �������� ȣ���� ��ü�� �����Ѵ�.
		-> �̷��� ������� �Լ��� ȣ���ϴ� ���� thiscall ����̶�� �θ���.

		thiscall ����� ��� �Լ��� ȣ���ϴ� ��ü�� �����Ͱ� �ʿ��ϱ� ������
		��ü ���̴� ���� ȣ���� �� ����.

		// ���� : �Լ� ȣ�� �Ծ� (function calling convension) ����
	
	*/
	void __thiscall Print(/*Person* this*/)
	{
		this->name;
		this->age;


		std::cout << name << "�� ���̴�" << age << "�Դϴ�." << std::endl;
	}

	// C�� �ٸ��� �⺻�� ������ ����
	int age = 15;
	float weight;
	std::string name;
};



int main()
{
	Person p1{ 10, 50.0f, "DIDI" };

	p1.Print(/*&p1*/);

	return 0;
}