// 04_dependencies.cpp

#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono; // 시간 관련 함수

class Timer
{
public:
	Timer()
	{
		start_time = high_resolution_clock::now(); //현재시간으로 초기화
	}

	void Elapsed()
	{
		auto current_time = high_resolution_clock::now(); // 지나온 시간 - 현재시간
		duration<double, std::milli> delta = current_time - start_time; // 두 시간 차이에 대한 정보를 double형의 milli로 받음

		cout << delta.count() << std::endl;
	}
private:
	time_point<high_resolution_clock> start_time;// 시간을 측정하는 자료형 객체
};

class Worker
{
public:
	void DoSomething()
	{
		// 의존 관계
		// 필요할 때만 가져다 쓰는 관계
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

// 과제
// chrono조사 