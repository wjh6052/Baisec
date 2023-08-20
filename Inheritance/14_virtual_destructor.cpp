// 14_virtual_destructor.cpp

#include<iostream>
using namespace std;

class Base
{
public:
    //1. �� ĳ���ý� �Ļ�Ŭ������ �Ҹ��ڰ� ȣ���� �ȵ�
    //~Base() { cout << "~Base()" << endl; }


    //2. virtual Ű���带 ����Ͽ� �� ��ü�� �´� �Ҹ��� ȣ��ǵ��� �ؾ���
    virtual ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
    ~Derived() {
        cout << "~Derived()" << endl;
        //TODO: arr��� ���� ���� 
    }

private:
    int* arr = nullptr; // ���� �Ҵ� ���� ����� Ư���� ��찡 �ƴϸ� �Ҹ��ڿ��� �������־�� �Ѵ�.
};


// ����Ұ� ������ �Ҹ��ڿ� virtual������
// ������� �����Ÿ� final���̱� 

int main()
{
    //{
    //   Derived d;
    //}

    // ���� Ŭ������ �� ĳ���� �ϰ� �Ǹ� ���� Ŭ������ �Ҹ��ڰ� ���еǾ�
    // �Ҹ��ڰ� ȣ���� �ȵǴ� ������ �߻��Ѵ�. ���⼭ ���� Ŭ�������� �����Ҵ� ����
    // ����� �ִٸ� ������ �����ʾ� �޸� ������ �߻��Ѵ�. ���� virtual Ű���带 �ٿ�
    // ���� �Ҹ��ڷ� ����� �־�� �Ѵ�.
    {
        Base* base = new Derived;

        delete base;
    }

    // Ŭ������ ������� �����Ÿ� finalŰ���带 ����.
    // Ŭ������ ����� �����̸� ������ �Ҹ��ڿ� virtual Ű���带 ������
    // -> �Ҹ��ڰ� �ʿ���� ��� �޸𸮸� �� ������ �� ������ ���� ������ �����ϴ� ����.



    return 0;
}