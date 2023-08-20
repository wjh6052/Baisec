// 02_composition_and_aggregation.cpp

#include<iostream>
using namespace std;

// 부품
class Point2D
{
public:
	int x;
	int y;
};

// 전체
class Monster
{
public:

	//1. composition
	Monster(int x, int y)
	{
		position1.x = x;
		position1.y = y;
	}

	//2. Aggregation
	Monster(Point2D* point)
	{
		this->position2 = point;
	}

private:
	std::string name;
	Point2D position1; // Monster객체가 사라지면 같이 사라짐 -> composition관계
	Point2D* position2;  // Monster객체가 사라져도 존재함 -> Aggregation관계
};

int main()
{
	//1. composition
	Monster mon(10, 20);

	//2. Aggregation
	Point2D point;
	{
		Monster mon(&point);
	}

	return 0;
}