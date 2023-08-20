// 04_inheritance_and_casting.cpp

/*
	Up Casting
	- �ڽ� Ŭ������ �θ� Ŭ���� ���·� �����Ͽ� ����Ű�� ��
	- �ڽ� Ŭ������ �� ũ�� ������ ���������� �� ū����� ���°��̱� ������ �Ͻ��� ����ȯ�� �ȴ�
	- �پ��� �ڽ� Ŭ������ �ϳ��� �θ� Ŭ���� �ڷ������� ���� �ϰ������� ó���� ����

	Down Casting
	- �θ� Ŭ���� ���·� �����ϴ� �ڽ� Ŭ������ ��ü�� �ٽ� �ڽ� Ŭ������ ���� ���·� ����Ű�� ��
	- �θ� Ŭ�������� �ڽ� Ŭ�������� ��ȯ�� �Ͻ��� ����ȯ�� ���� ����
*/


#include<iostream>
using namespace std;

class Snack {};

class Chitos : public Snack {};
class ChocoChip : public Snack {};
class Homerunball : public Snack {};

int main()
{
	// �� ĳ����
	Snack* chitos = new Chitos();

	Snack* chocochip = new ChocoChip();

	// ���� �ٸ� �ڽ� Ŭ������ ����� �θ� Ŭ������ ���� ����� ����
	Snack* snack[2] = { chitos, chocochip };


	// �ٿ� ĳ����

	// �Ͻ��� ����ȯ�� ���� �ʴ´�.
	//Chitos* test1 = chitos;

	// ����� ����ȯ���� ó�� �ؾ���
	Chitos* test2 = static_cast<Chitos*>(chitos);

	return 0;
}