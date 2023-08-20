// 04_dependencies.cpp

#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono; // �ð� ���� �Լ�

class Timer
{
public:
	Timer()
	{
		start_time = high_resolution_clock::now(); //����ð����� �ʱ�ȭ
	}

	void Elapsed()
	{
		auto current_time = high_resolution_clock::now(); // ������ �ð� - ����ð�
		duration<double, std::milli> delta = current_time - start_time; // �� �ð� ���̿� ���� ������ double���� milli�� ����

		cout << delta.count() << std::endl;
	}
private:
	time_point<high_resolution_clock> start_time;// �ð��� �����ϴ� �ڷ��� ��ü
};

class Worker
{
public:
	void DoSomething()
	{
		// ���� ����
		// �ʿ��� ���� ������ ���� ����
		Timer timer;
		for (int i = 0; i < 100'000'000; i++)
			;
		timer.Elapsed();
	}
};

int main()
{
	Worker w;
	w.DoSomething();

	return 0;
}

// ����
// chrono���� 