// 07_this_pointer_and_chaining_member_functions.cpp

#include<iostream>
using namespace std;

#define THIS_POINTER
#define CHAINING_MEMBER_FUNCTION

#ifdef THIS_POINTER

/*
   this pointer : �Լ��� ȣ���� ��ü�� �����ϱ� ����
   �⺻������ �־��ִ� �ش� ��ü�� ������
*/

class Test // 12
{
public:
    Test() {}
    ~Test() {}


    // this : �ش� �Լ��� ȣ���� ��ü�� ������
    auto /*this call*/ GetA()
    {
        // this�� �ּҴ� �� ��ü�� �ּ�
        cout << this << endl;
        return a;
    }

    // �Ű������� ��� ������ �̸��� ������ ���� ���̵� �߻�
    //void SetA(const int& a) { a = a; } // �Ű������� �켱�� �ȴ�.

    // �����ϱ� ���� �̸��� ����
    //void SetA(const int& in_a) { a = in_a; }

    // this�� ����ϸ� �Ű������� �̸��� �����ϴ��� ��� ������ ����� �� �ִ�.
    void SetA(const int& a) { this->a = a; }

    auto GetB() { return b; }
    void SetB(const int& in_b) { b = in_b; }

private:
    int a;
    int b;
    int c;
};

int main()
{

    Test test1;
    test1.GetA();

    Test test2;
    test2.GetA();

    cout << &test1 << ", " << &test2 << endl;

    return 0;
}

#endif // THIS_POINTER


#ifdef CHAINING_MEMBER_FUNCTION
/*
   chaining member function
   - �ڽ��� ���������� ȣ���ϴ� �Լ�
*/

class Calc
{
public:
    Calc(int value) : value(value) {}

    //1.
    //void Add(int value) { this->value += value; }
    //void Sub(int value) { this->value -= value; }
    //void Mul(int value) { this->value *= value; }
    //void Div(int value) { this->value /= value; }
    //void Mod(int value) { this->value %= value; }

    // Calc a;
    // this  == &a
    // *this == *&a == a;

    //2.
    // reference ���·� ����
    // ��ȯ���� Calc& (�� ��ü)
    Calc& Add(int value) { this->value += value; return *this; }
    Calc& Sub(int value) { this->value -= value; return *this; }
    Calc& Mul(int value) { this->value *= value; return *this; }
    Calc& Div(int value) { this->value /= value; return *this; }
    Calc& Mod(int value) { this->value %= value; return *this; }

private:
    int value;
};


int test() { return 10; }

int main()
{
    cout << "a" << "b" << "c" << "d" << "e" << endl;

    //1.
    //Calc calc(10);
    //calc.Add(5);
    //calc.Div(2);
    //calc.Mul(3);
    //calc.Mod(5);
    //calc.Sub(2);

    //2. ���� ������ ���ٷ� ó���ϰ� ������ 

    Calc calc(10);

    // �̷��� ���������� ��� ���� = chaining
    // �̷��� ���� �켱���� ������� �տ������� ���
    calc.Add(5).Div(2).Mul(3).Mod(5).Sub(2);


    //3. �͸� ��ü�� ����ؼ� ȣ�� ����
    Calc(10).Add(5).Div(2).Mul(3).Mod(5).Sub(2);

    return 0;
}

#endif






