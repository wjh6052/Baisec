// 08_templatize.cpp

#include<iostream>
using namespace std;


template <class T>
class A
{
public:
    A(const T& value)
        : value(value)
    {}

    template <typename TT>
    void DoSomething()
    {
        cout << "Hello1" << endl;
        cout << typeid(T).name() << "" << typeid(TT).name() << endl;
    }

    template <typename TT>
    void DoSomething(const TT& input)
    {
        cout << "Hello2" << endl;
        cout << typeid(T).name() << "" << typeid(TT).name() << endl;
    }

    void Print()
    {
        cout << value << endl;
    }

private:
    T value;
};


int main()
{
    A<int> a_int(123);
    a_int.Print();

    //1. Ÿ�Ը� �䱸�ϴ� ���
    a_int.DoSomething<float>();

    //2. �Ű������� �޴� ���
    a_int.DoSomething<float>(10.0f);
    a_int.DoSomething(10.0f);
    a_int.DoSomething(char());



    return 0;
}