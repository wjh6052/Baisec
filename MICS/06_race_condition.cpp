// 06_race_condition.cpp

#include<iostream>  
#include<thread>
#include<chrono>
#include<mutex> // mutual exlusion : ��ȣ ����
#include<atomic>
using namespace std;

//============================================
// rece condition ���� �ذ��ϱ� 1 : mutex
//============================================

/*
    mutex
    - Ư�� ������ ��� �ѹ��� �� �����常 �����Ҽ� �ֵ��� �����.
    - �ش� ������ �Ӱ� �����̶�� �θ���.
    - mutex ����� �߰��ؾ� �Ѵ�.
*/

//int shared_memory;
//mutex mtx; // ������ ��� mutex ����
//
//int main()
//{
//    auto count_func = []()
//    {
//        
//        for (int i = 0; i < 1000; ++i)
//        {
//           std::this_thread::sleep_for(chrono::milliseconds(1));
//
//           // lock() : �� �����尡 lock()�Լ��� ȣ���� ������ ��� �ٸ� �����尡 ������ �۾��� �������� ���ϵ��� ���´�.
//           mtx.lock();
//           { //critical section : �Ӱ� ���� -> �ϳ��� �����常 �� �� �ִ� ����
//               ++shared_memory;
//           }
//           // unlock() : �� �����尡 unlock()�Լ��� ȣ���� ������ �ٽ� Ǯ���־� �ٸ� �����尡 �ش� ������ ������ �� �ֵ��� �����.
//           mtx.unlock();
//        }
//    };
//
//    thread t1 = thread(count_func);
//    thread t2 = thread(count_func);
//
//    t1.join();
//    t2.join();
//
//    // ���� ����� ��µǴ°��� Ȯ�� ����
//    cout << "After : " << shared_memory << endl;
//
//
//    return 0;
//}

//============================================
// rece condition ���� �ذ��ϱ� 2 : atomic
//============================================

/*
    atomic
    - �����尡 Ư�� �����͸� ���ÿ� �������� ���ϰ� �Ѵ�.
    - atomic���� ���� �����ʹ� atomic���� �����ǵ� �����ڸ� ����Ѵ�. -> ������.
    - �ݺ������� ȣ��Ǵ� �����Ϳ� ����ϸ� ������ ���ϵ� �� �ִ�.
    - atomic ����� �߰��ؾ� �Ѵ�.
*/

atomic<int> shared_memory; // �ش� �����͸� aotomic���� ����

int main()
{
    auto count_func = []()
    {
        for (int i = 0; i < 1000; ++i)
        {
            std::this_thread::sleep_for(chrono::milliseconds(1));
            ++shared_memory;
        }
    };

    thread t1 = thread(count_func);
    thread t2 = thread(count_func);

    t1.join();
    t2.join();

    // ���� ����� ��µǴ°��� Ȯ�� ����
    cout << "After : " << shared_memory << endl;

    return 0;
}

//============================================
// rece condition ���� Ȯ���ϱ�
//============================================

int shared_memory;

int main()
{
    auto count_func = []()
    {
        for (int i = 0; i < 1000; ++i)
        {
            std::this_thread::sleep_for(chrono::milliseconds(1));
            ++shared_memory;
        }
    };

    thread t1 = thread(count_func);
    thread t2 = thread(count_func);

    t1.join();
    t2.join();

    cout << "After : " << shared_memory << endl;

    /*
        ������ ����� 2000������ �װͺ��� ������ ���� ���´�.
        -> ���� �ٸ� ��������� ���� �ڿ��� ������ �� �������� �޶����� ������ �߻�
        -> �̰� ���� ����(race condition)�̶�� �θ���.
    */

    return 0;
}