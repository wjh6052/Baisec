// 02_Encapsulation.cpp

#include<iostream>

struct Data1
{
	//public: 구조체는 public이 기본 접근 지정자
	int hp;
	int attack;
	float luck;
};

class Data2
{
	//private: class는 private가 기본 접근 지정자

public:
	/* member function */
	/*getter, setter */

	int SetHp(int hp) { this->hp = hp; }
					// this : 나의 hp를 사용하겠다
	int SetAttack(int attakc) { this->attack = attack; }

	int GetHp() { return hp; }
	int GetAttack() { return attack; }
	

private:
	/* member variable */
	int hp;
	int attack;
	float luck;
};


int main()
{
	Data1 d1;

	Data2 d2;


	return 0;
}