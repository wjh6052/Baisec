// 03_inheritance_and_access_specifier.cpp


#include<iostream>
using namespace std;

/*
   ��� ���� ������
   - ��� Ŭ������ �Ļ� Ŭ������ ��� ������ �� ����ϴ� �����ڰ� ��� ���� ������.
   - ��� ���� �����ڰ� ��� Ŭ������ ����� ���� �����ں��� ���� ���ѵ� ���� ������ ���,
   ��� ���� �����ڷ� ����ȴ�.
   - private����� ����� ������ ��� �Ļ� Ŭ�������� ���������� �Ұ����ϴ�.

   ��� ���� ������      ��� Ŭ����         �Ļ�Ŭ����
   public               public             public
                        protected          protected
                        private            ���� �Ұ�

   protected            public             protected
                        protected          protected
                        private            ���� �Ұ�

   private              public             private
                        protected          rivate
                        private            ���� �Ұ�

*/

class Base
{

public: // ��� �������� ���� ����
    void Test() {}
    int public_data;

protected: // ���/�Ļ� Ŭ���������� ���� ����
    int protected_data;

private: // ��� Ŭ���������� ���� ����
    int private_data;
};

// ��� Ŭ������ ����� ���� �����ڸ� ��� private��
class Derived : public Base // Derived�� �ٸ� Ŭ������ ����� �� 
{
public:
    Derived()
    {
        // �ش� ������� ��� ��� ���� �����ڿ� ���� private�� �ٲ�
        Test();
        public_data;
        protected_data;
        //private_data;   // private����� ��ӹ޾� ���� �Ұ�
    }
};

// Derived�� Base�� ����� private�� �޾ұ� ������
// ��� ���� �����ڸ� public�� �����Ͽ��� �ǹ̰� ����.
// -> ��� ���� �����ڰ� �� ������ ���ѵ� ��쿡�� ������ �Ǳ� ����
class A : public Derived
{
public:
    A()
    {
        // private����� ��ӹ޾� ������ �Ұ���
        Test();
        public_data;
        protected_data;
        private_data;
    }
};

int main()
{
    Base base;

    // �ܺο��� ���� ���� public
    base.Test();
    base.public_data;

    // �ܺο��� ���� �Ұ��� protected, private
    base.protected_data;
    base.private_data;

    // ��� �����ڸ� ��� private���� �޾� 
    // �ܺο��� ���� �Ұ���
    A a;

    a.Test();
    a.public_data;
    a.protected_data;
    a.private_data;

    return 0;
}