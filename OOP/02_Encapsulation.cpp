// 02_Encapsulation.cpp

#include<iostream>

struct Data1
{
	//public: ����ü�� public�� �⺻ ���� ������
	int hp;
	int attack;
	float luck;
};

class Data2
{
	//private: class�� private�� �⺻ ���� ������

public:
	/* member function */
	/*getter, setter */

	int SetHp(int hp) { this->hp = hp; }
					// this : ���� hp�� ����ϰڴ�
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