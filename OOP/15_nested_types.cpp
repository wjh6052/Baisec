// 15_nested_types.cpp

#include<iostream>
using namespace std;

class Character
{
public:
	enum class Movement
	{
		Min = 0,
		Idle = Min,
		Walk,
		Run,
		Max = Run,
		Count
	};

public:

	Character(const string& str) : name(name) { }


	void SetCharacterMovement(Movement new_move)
	{
		movement_state = new_move;
		speed = movement_speed[static_cast<int>(new_move)];
	}

	void PrintCurrentMovementState()
	{
		switch (movement_state)
		{
		case Character::Movement::Idle:
			cout << name << "의 현재 이동 상태 : idle, 현재 속도 : " << speed << endl;
			break;
		case Character::Movement::Walk:
			cout << name << "의 현재 이동 상태 : Walk, 현재 속도 : " << speed << endl;
			break;
		case Character::Movement::Run:
			cout << name << "의 현재 이동 상태 : Run, 현재 속도 : " << speed << endl;
			break;

		default:
			break;
		}
	}

private:
	static constexpr int movement_speed[static_cast<int>(Movement::Count)] =
	{
		0,
		200,
		400
	};

	std::string name;

	Movement movement_state = Movement::Idle;

	int speed = movement_speed[static_cast<int>(Movement::Idle)];
};


int main()
{
	Character player(string("Player"));

	player.PrintCurrentMovementState();

	player.SetCharacterMovement(Character::Movement::Walk);

	player.PrintCurrentMovementState();

	cout << endl;

	Character enemy(string("Enemy"));

	enemy.PrintCurrentMovementState();

	enemy.SetCharacterMovement(Character::Movement::Run);

	enemy.PrintCurrentMovementState();

	return 0;
}