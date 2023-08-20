// 13_virtual_table.cpp


#include<iostream>
using namespace std;

/*
    class Base                                     Base my_base;
    *__vfptr         --------------------------->  -Base virtual-table
    virtual func1()  <---------------------------  -func1()
    virtual func2()  <---------------------------  -func2()
                 ^
                 |
                 \
                  \________________________________
                                                   \
    class Derived : public Base                     \   Derived my_derived;
    *__vfptr (inherited) --------------------------->\  -Derived virtual_table
    virtual func1()      <----------------------------\--func1()
                                                       \-func2()

    - virtual Ű���带 ���̸� ���� �Լ� ���̺� ����
    - ȣ���� �޼��带 ���� ���ε��� ���� �����Ѵ�.
    - �������̵����� ���� �޼��带 ���� �Լ��� ������ ��� �ǹ� ���� ���� ���ϸ� ����Ű�� ������ ����!
*/

class Base
{
public:
    virtual void func1() {}
    virtual void func2() {} // �ǹ� ���� ���� �Լ� 
};

class Derived : public Base
{
public:
    virtual void func1() {}

};
int main()
{
    Derived d;

    return 0;
}