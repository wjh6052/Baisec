// 02_composition_and_aggregation.cpp

#include<iostream>
using namespace std;

// ��ǰ
class Point2D
{
public:
	int x;
	int y;
};

// ��ü
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
	Point2D position1; // Monster��ü�� ������� ���� ����� -> composition����
	Point2D* position2;  // Monster��ü�� ������� ������ -> Aggregation����
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