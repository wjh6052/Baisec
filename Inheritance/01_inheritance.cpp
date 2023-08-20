// 01_inheritance.cpp

/*
   Inheritance - ���
    - �ٸ� Ŭ������ ������ �״�� ������ �� �ִ� ���(���������� ��������.)
    - ����� ������ ���ȭ�Ͽ� �ڵ带 ���� �ϱ⿡ �����ϴ�.
    - �Ļ� Ŭ������ ����� ��� Ŭ������ ����� ����/Ȯ���ϱ⿡ ����
    - �ڵ��� �ߺ��� �ٿ� ����ȭ �� �� �ִ�.
*/

#include<iostream>
using namespace std;

class Base
{
public:
    int GetA() const
    {
        cout << "Base::GetA" << endl;
        return a;
    }
    void SetA(const int& a) { this->a = a; }

private:
    int a;

public:
    int b;
    int c;
};


// Derived class - �Ļ� Ŭ����, base class�� ����� ��� ��ӹ޴´�
class Derived : public Base
{
public:
    int GatA() const
    {
        cout << "Derived::GetA" << endl;

        // ��� ���� ����� �ڽ� Ŭ���� ���ο��� ��밡��
        c; // Base::c

        // ���/�Ļ� Ŭ������ ����� �̸��� �ߺ��Ǹ� �Ļ� Ŭ������ ����� �켱�� �ȴ�.
        b; // Derived::b
        Base::b;    // ���� �����̽��� ����Ͽ� ��� Ŭ���� ����� ���ٰ���
        Derived::b;

        // ��� Ŭ������ private ����� ����� �Ǿ ������ �ȵȴ�.
        // �ڽ� Ŭ���������� protected�� puvlic ����� ���� ����
        // return a;


        return Base::GetA();

        // __super�� �θ� Ŭ���� ǥ������, vc ����
        // __super::GetA();
    }
private:
    int b;

};

int main()
{
    Derived d;

    // ��� Ŭ�������� ��ӹ��� ��� �Լ�
    d.SetA(10);

    // ���/�Ļ� Ŭ������ ����� �ߺ��ɰ�� �Ļ� Ŭ������ ����� �켱�� �ȴ�
    // �Ļ� Ŭ������ ����� �켱�ؼ� ȣ���� �� ��� Ŭ������ ����� ��� ������ �ִ�.
    d.GatA();

    // ���ӽ����̽��� ����Ͽ� ������ �θ��� ����� ���ٰ���
    d.Base::GetA();

    return 0;
}