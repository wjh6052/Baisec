// 11_static_member_function.cpp

/*
   static member function
   - Ŭ������ ��ü�� �������� �ʰ� ȣ�Ⱑ���� �Լ�
   - ��ü�� �����Ƿ� this������ ����� �ȵǱ� ������ ���� ��� ������ ��� ����
   - const�Լ��� ���� �� ����. -> this �����Ͱ� ���� ������
*/

#include<functional>
#include<iostream>
using namespace std;

class Test
{
public:
    void Temp1() {
        this->value1;
        value2;
    }

    static void Temp2() {
        // thiscall ����� �ƴϱ� ������ this ������ ����� �ȵ�
        // Ŭ������ ���Ե� �Ϲ� �Լ��� �����ϸ� �ȴ�
        //this->value1;
        value2;
    }

private:
    int value1;
    static int value2;

public:
    int test;
};


int main()
{
    Test t1;

    //Test::Temp1();
    t1.Temp1();

    Test::Temp2();
    t1.Temp2();

    // thiscall�̶� �Ϲ� �Լ� ������ ���İ� �ٸ�
    //void (*ptr1)() = Test::Temp1;


    // �Ϲ� �Լ� ���İ� ��ġ��
    void (*ptr2)() = Test::Temp2;

    /*
         ��� ������
         - Ư�� Ŭ������ ���� ����� ����Ű�� ������
          - ��� �����͸� ����� ��� �Լ��� ���� �� �ִ�.
         - Ư�� �ν��Ͻ�ȭ�� ����� ��ġ�� �ƴ� ����� Ŭ������
        �����ϴ� ��ġ�� ������ ������ ����ϱ� ���ؼ� ��ü�� �־�����Ѵ�.
         - �ּҿ� ������ �� (.*) �����ڸ� ����Ѵ�.

        - �⺻ ������ ���Ŀ��� ���� �����̽��� �߰����ָ� �ȴ�.
        ��� ���� ������
        �ڷ��� Ŭ�����̸�::*�������̸� = &Ŭ�����̸�::�����̸�

        ��� �Լ� ������
        ��ȯ�� (Ŭ�����̸�::*�Լ��������̸�) = &Ŭ�����̸�::�Լ��̸�;
    */

    int Test::* ptr3 = &Test::test;
    t1.*ptr3 = 10;

    void (Test:: * ptr4)() = Test::Temp1;
    (t1.*ptr4)();

    //<functional> ��� �߰��ؾ���
    std::function<void(Test)> fp = Test::Temp1;
    fp(t1);


    return 0;
}