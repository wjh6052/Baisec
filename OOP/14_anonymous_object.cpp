// 14_anonymous_object.cpp

#include<iostream>
using namespace std;

class A
{
public:
    void print()
    {
        cout << "print" << endl;
    }
};

int main()
{
    // ��� �Լ��� ȣ���ϱ� ���� �ν��Ͻ��� ���� 
    // -> ���� �ν��Ͻ��� ������ �����ؼ� �������ʰ� �����ϰ� ��� �Լ��� ȣ���ϰ�ʹٸ�?
    A a;
    a.print();

    // �͸� ��ü�� ����ϸ� ���� ���ϰ� ��밡��
    A().print(); // �����ǰ� �Լ� ������ �����

    return 0;
}