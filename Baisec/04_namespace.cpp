// 04_namespace.cpp


/*
   �̸� ���� (namespace)
   - ���ǵ� ��ü�� ���� �Ҽ��� �����ִ� ��
   - std::cout, std::cin ���⼭ std�� cout, cin�� �̸� ����
   - �̸��� ���Ƶ� �̸������� �ٸ��� �ٸ� ��ü�� �ν��Ѵ�.
   - ������ �Լ��� �̸��� ��ġ�� ��츦 �ذ��� �� �ִ�.

   ����
   namespace �������̸�
   {
      ���
   }

   ���ٹ�

   �����̸�::���

   ��)

   namespace a
   {
      int b;
   }

   a::b = 10;
   - �̸����� a�� �ִ� ���� b�� �����Ͽ� 10����
*/


#include<iostream>

namespace my_namespace_1 
{
    int a;

    void DoSomething(){} // my_namespace_1:: DoSomething()

    // �̸������� ��ø�Ͽ� ��밡��
    namespace DIDI
    {
        namespace TITI
        {
            namespace RURU
            {
                int c; //my_namespace_1::DIDI::TITI::RURU::c
            }

        }

    }

    namespace my_namespace_1
    {
       int a;
    }

    // c++ 17 ����
    // namespace my_namespace_1::DIDI::TITI::RURU
	//{
	//	int test;
	//}

    namespace my_namespace_2
    {
        int a;
        void DoSomething() {}
    }

    /*
        using namespace �̸�����
        - �ش� �̸� ������ ������ ���������� ������� �ʰ� ������ �����ϴ�
    */

    using namespace std;

    int main()
    {

        //a; // error, ����Ǿ���������


        // �̸��������� �ߺ��� �̸����� ������ ���𰡴�
        my_namespace_1::a = 10;
        my_namespace_2::a = 15;

        std::cout << my_namespace_1::a << std::endl;
        std::cout << my_namespace_2::a << std::endl;

        // using namespace�� ������ �����ϰԵǸ� �ߺ������� ����ų ���ɼ��� ���� �����
        // �����ϴٸ� ����� �������� �����ϴ°� ����
        {
            using namespace my_namespace_1;
            using namespace my_namespace_2;

            // a; // ambiguous : ��ȣ�� ���� �߻�

            my_namespace_1::a;
        }

        return 0;
    }

}