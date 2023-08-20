// 16_virtual_base_class_and_the_diamond_problem.cpp

#include<iostream>
using namespace std;

/*
   A       A
   |       |
   B       C
    \     /
       D

   class A {};
   class B : public A {};
   class C : public A {};
   class D : public B, public C {};

   B�� A�� ������ �ִ�.
   C�� A�� ������ �ִ�.
   B�� C�� ������ D�� A�� 2�� ������.
   => D���忡���� �� A�� ������� ����ؾ� �ϴ���
   ���� ��ȣ���� �߻�
*/

/*
      A
     /   \
   B       C
     \   /
      D

   class A {};
   class B : virtual public A {};
   class C : virtual public A {};
   class D : public B, public C {};

   ��ӽ� virtual Ű���带 �ٿ� ���� ����� �ϸ�
   A��ü�� �ϳ��� �����Ͽ� ������ ����.
*/

class PoweredDevice
{
public:
    PoweredDevice(int power) { cout << "PoweredDevice" << power << endl; }

public:
    int i;
};

class Scanner : virtual public PoweredDevice // ���� ���
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice(power)
    {
        cout << "Scanner : " << scanner << endl;
    }
};

class Printer : virtual public PoweredDevice // ���� ���
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power)
    {
        cout << "Printer : " << printer << endl;
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power1, int power2, int power3)
        : Scanner(scanner, power1)
        , Printer(printer, power2)
        , PoweredDevice(power3) // ���� ��ӽ� ���̾Ƹ�� ����� �޴� ������ �Ļ� Ŭ������ ���� �ʱ�ȭ ����� �Ѵ�. 
    {}
};

int main()
{
    Copier copier(1, 2, 3, 4, 5);

    // �Ϲ� ��ӽ� �ٸ� �ּ� ��� -> �ΰ��� A��ü�� ���� 
    // ���� ��ӽ� ���� �ּ� ��� -> �ϳ��� A��ü�� ����
    cout << &copier.Scanner::PoweredDevice::i << endl;
    cout << &copier.Printer::PoweredDevice::i << endl;

    copier.i; // ambiguous, ���� ��ӽ� ����X

    return 0;
}