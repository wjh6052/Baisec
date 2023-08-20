// 19_default_parameter.cpp

#include<iostream>

struct Player
{
	int hp;
	bool is_active;
	int atk;
};


/*
	매번 is_active에 값을 넣어주기 번거롭다
	-> 보통 true값이 세티오디는데 false가 세팅되는 예외를 처리하기위해 번거롭게 받고있는 상황
	이러한 상황에서 따로 is_active값을 넘기지 않을때 true가 세팅되게 하고싶다
	-> default parameter를 사용하여 해결
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

// 주의점1 : 항상 마지막부터 넣어야 한다.
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

	// 주의점2 : 뒤에 있는 값을 수정하려면 앞에 있는 디폴트 값들도 넣어줘야함
	CreatePlayer2(150, 50, false);


	/*
		주의점 3 : 오버로드된 함수간의 모허성 문제 발생
		default parameter와 function overloadint은 동시에 사용하지 않는게 좋다
		CreatePlayer2(200.0, 300.0);
		CreatePlayer2(10);
	*/

	return 0; 
}