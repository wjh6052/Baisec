// 03_variable.cpp

#include<iostream>
#include<numeric>

int main()
{
    /*
     Initialziation
    */

    int x = 10;      // copy
    int y(10);      // direct
    int z{ 10 };   // uniform : �����ϰ� ������ �ʱ�ȭ ����

    int a = 1.1;
    //int b{1.1};      // error, ���� ������ ĳ���õǾ� �����Ͱ� �ս�
    char c = 500;
    //char d{500};      // error, ���� �÷ο찡 �Ͼ ������ �ս�

    /*
       limits
       - ������ �ڷ����� �Ѱ谪�� ������ �ִ� Ŭ����
    */

    // <> : template
    std::cout << std::numeric_limits<short>::max() << std::endl;
    std::cout << std::numeric_limits<int>::min() << std::endl;
    std::cout << std::numeric_limits<int>::max() << std::endl;
    std::cout << std::numeric_limits<float>::min() << std::endl;
    std::cout << std::numeric_limits<float>::max() << std::endl << std::endl;

    /*
       Casting
    */
    float k = 10.0f;


    std::cout << k << std::endl;
    std::cout << (int)k << std::endl; // c style �ʹ� ������ -> ������� �ڷ��������� ����ȯ�� ������
    std::cout << int(k) << std::endl; // c++ style �ʹ� ������ -> ������� �ڷ��������� ����ȯ�� ������
    std::cout << static_cast<int>(k) << std::endl;


    // ���� : cast ���� 4���� ����
    // - static_cast
    // - reinterpret_cast
    // - dynamic_cast
    // - const_cast


    /*
       const vs constexpr
    */

    /*
       const
       - �ʱ�ȭ�ϴ� ���� ���� ��Ÿ���̳� ������ Ÿ�Ӷ� ���� ��������.
    */

    // ���ͷ� ���(������ Ÿ�Ӷ� Ȯ���� ��)���� �ʱ�ȭ�ϴ� ��� ������ Ÿ�Ӷ� ������ 
    const int c1(123);

    int i1 = 10;
    // ����(��Ÿ�Ӷ� �����Ǵ� ��)���� �ʱ�ȭ�ϴ� ��� ��Ÿ�Ӷ� ������
    const int c2 = i1;

    int arr_1[c1];
    //int arr_2[c2];

    /*
       constexpr
       - ������ Ÿ�Ӷ� ��������
       - ��ũ�ο� ��������� ������� �����ϴ�.
    */

    constexpr float pi1 = 3.141592f;

    float pi2 = 3.141592f;
    //constexpr float pi3 = pi2; // error : ������ ������ ������ ���� �� �� ���� �־��� �� ����

	return 0;
}