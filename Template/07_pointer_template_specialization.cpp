// 07_pointer_template_specialization.cpp


#include<iostream>
using namespace std;

// 1. ������ Ÿ���� ���� ��� Print() �Լ����� ��� ������ ���� �ּҰ��� ����̵ȴ�
// -> T�� ������ �ڷ����̶�� Ư��ȭ�� Print() �Լ����� �ּҰ� ���� �����͸� ����غ���
template <class T>
class A
{
public:
    A(const T& value)
        : value(value)
    {}

    void Print()
    {
        cout << value << endl;
    }

private:
    T value;
};

//2. ������ ���ø� Ư��ȭ
template <class T> // ��� ������ Ÿ�Կ� ���� Ư��ȭ�� �ؾ��ϱ� ������ �ڷ����� ����ؾ���
class A<T*>
{
public:
    A(T* value)
        : value(value)
    {}

    void Print()
    {
        cout << *value << endl;
    }

private:
    T* value;
};

int main()
{
    A<int> a_int(123);
    a_int.Print();

    int temp = 456;

    A<int*> a_int_ptr(&temp);
    a_int_ptr.Print();

    return 0;
}