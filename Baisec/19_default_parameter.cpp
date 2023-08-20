// 19_default_parameter.cpp

#include<iostream>

struct Player
{
	int hp;
	bool is_active;
	int atk;
};


/*
	�Ź� is_active�� ���� �־��ֱ� ���ŷӴ�
	-> ���� true���� ��Ƽ����µ� false�� ���õǴ� ���ܸ� ó���ϱ����� ���ŷӰ� �ް��ִ� ��Ȳ
	�̷��� ��Ȳ���� ���� is_active���� �ѱ��� ������ true�� ���õǰ� �ϰ�ʹ�
	-> default parameter�� ����Ͽ� �ذ�
	Player CreatePlayer(int hp, bool is_active)
	{
		Player p{ hp, is_active };
		return p;
	}
*/

Player CreatePlayer(int hp, bool is_active = true)
{
	Player p{ hp, is_active };
	return p;
}

// ������1 : �׻� ���������� �־�� �Ѵ�.
//Player CreatePlayer(bool is_active = true, int hp)
//{
//	Player p{ hp, is_active };
//	return p;
//}

Player CreatePlayer2(int hp = 150, int akt = 50, bool is_active = true)
{
	Player p{ hp, is_active, akt };
	return p;
}

Player CreatePlayer2(float hp, float akt, bool is_active = true)
{
	Player p{ hp, is_active, akt };
	return p;
}

int main()
{
	Player p1 = CreatePlayer(10);
	Player p2 = CreatePlayer(10);
	Player p3 = CreatePlayer(10);
	Player p4 = CreatePlayer(10);

	// ������2 : �ڿ� �ִ� ���� �����Ϸ��� �տ� �ִ� ����Ʈ ���鵵 �־������
	CreatePlayer2(150, 50, false);


	/*
		������ 3 : �����ε�� �Լ����� ���㼺 ���� �߻�
		default parameter�� function overloadint�� ���ÿ� ������� �ʴ°� ����
		CreatePlayer2(200.0, 300.0);
		CreatePlayer2(10);
	*/

	return 0; 
}