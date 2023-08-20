// 03_constructor.cpp

#include<iostream>
#include<utility>

using namespace std;

class Fraction
{
public:
    Fraction(int n, int d)
    {
        numerator = n;
        denominator = d;
        cout << "constructor!!" << endl;
    }

    /*
       - default constructor - �⺻ ������
          �� �����ڸ� �ϳ��� �������� ������� �⺻������ �����Ǵ� ������
          �� �����ڸ� �ϳ� �������� ��� �������� ����

       - copy constructor - ���� ������
          �� �ڽŰ� ���� Ÿ���� Ŭ������ & ���·� �޾� �����Ǵ� ��� ȣ��
          �� ���� �������� ��� �ܺο� �����ϴ� ������ ���� �����Ͽ� �纻�� ��������Ҷ� ����Ѵ�.
          �� ���� ����� ���� ���簡 �ִ�.

       - move constructor - �̵� ������
          �� �ڽŰ� ���� Ÿ���� Ŭ������ && ���·� �޴°�� ȣ��
          �� �������� ��� ���� ��ü�� ���� �����Ͽ� ����ü�� �̵���Ű�����Ҷ� ����Ѵ�.
    */

    //Fraction(){}                  // �⺻ ������
    //Fraction(const Fraction&){}      // ���� ������
    //Fraction(Fraction&&){}         // �̵� ������

    Fraction()
    {
        cout << "default constructor!!" << endl;
    }

    Fraction(const Fraction& frac)
    {
        cout << "copy constructor!!" << endl;
    }

    Fraction(Fraction&& frac) noexcept
    {
        cout << "move constructor!!" << endl;
    }

private:
    int numerator = 10;
    int denominator = 10;
};

class IntArray
{
public:
    IntArray(const int& in_length)
    {
        length = in_length;
        arr = new int[length];
        cout << "constructor!!" << endl;
    }

private:
    int* arr = nullptr;
    int length = 0;
};

int main()
{
    //Fraction f1();

    //Fraction f1;
    //Fraction f2(10, 20);


    Fraction d;

    Fraction c(d);

    Fraction m(std::move(d));


    return 0;
}