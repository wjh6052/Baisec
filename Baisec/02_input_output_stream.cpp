// 02_input_output_stream.cpp

#include<iostream>
// #intclude<iomanip>

/*
   stream ( >> , <<)
   - �������� �Է°� ����� �帧�� ǥ���� ��
*/

int main()
{

    /*
        cout, endl

        << : output operator(stream)
    */

    int x = 1028;
    double pi = 3.141592;

    std::cout << "x is " << x << " pi is " << pi << std::endl << std::endl;

    /*
       cin

       >> : input operator(stream)
    */
    int z;
    std::cin >> z;
    std::cout << "Your input is " << z << std::endl << std::endl;
    
    /*
      ������(mainpulator)
      - ����� ������ �������� �� �ִ�
      - �����ϱ� ������ ������ �ɼ��� ��� �����ȴ�.
   */

    int num = 100;

    // ���� ��� ���� ������
    std::cout << std::oct << num << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl << std::endl;

    // showbase : � ���� ���·� ��µǴ��� ǥ��
    // showpos   : ������ ������ ��ȣ ǥ��
    // noshowbase, noshowpos�� ���� ����

    std::cout << std::showbase << std::showpos;
    std::cout << std::oct << num << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl << std::endl;
    std::cout << std::noshowbase << std::noshowpos;

    bool is_true = true;
    bool is_false = false;

    //bool���� ��� ������ �ٲ� �� �ִ�.
    std::cout << std::boolalpha; // true, false�������� ���
    std::cout << is_true << std::endl;
    std::cout << is_false << std::endl << std::endl;

    std::cout << std::noboolalpha; // boolalpha ���
    std::cout << is_true << std::endl;
    std::cout << is_false << std::endl << std::endl;




    return 0;
}

