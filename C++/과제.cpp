
//����Ű
/*
//Alt + ������ ����Ű : �ڵ��ϼ�Ȱ��ȭ

//������ + g : ȭ���ȭ
//������ + Shift + s : ȭ��ĸ��

// ctrl + w : Ŀ����ġ ��ü ����

// ctrl + d						: �������� �� ����
// Alt + Ű���� ȭ��ǥ ��, �Ʒ�	: �� �̵�

// ctrl + k + c : ���� ���� �ּ�
// ctrl + k + u : ���� ���� �ּ� ����

// ctrl + k + f : �ڵ� ����

// Alt + Shift + ���콺 �巡�� : ���úκ��� ���� ��ü ����

// ctrl + k + s : ���õ� ������ &�� ������

// alt + shift + ����Ű : ����Ű �������� ������ ����

// ctrl + ~ = �ش� �ش����Ϸ� �̵� [�����ʿ���]
(���� -> ȯ�� -> Ű���� -> �������Ȱ���´¸޴�.�ڵ�â.����ڵ�������ȯ)

*/


/*
	23.7.21
   1. ���� : Storage<bool>�� Ư��ȭ
   
   �Ʒ��� Ŭ������ ���� ���ø� ���ڿ� ���� �����͸� 8�� �������ִ� Ŭ�����̴�.

   ���⼭ ������ ����µ� bool���� ���� �� ������ �����ϰ� �ȴ�.
   -> bool���� 1����Ʈ ũ�⸸���ε� 8������ ǥ���� �� ������ �Ʒ���
   ���� ������ ��� 1����Ʈ * 8�� ũ�⸦ ������.

   �Ʒ��� Ŭ������ ���ø� Ư��ȭ�� bool���Ͻ�
   1����Ʈ�� ������ 8���� �Ұ��� ó���� �� �ְ� ������


template<typename T>
class Storage8
{
public:
	void Set(int index, const T& value)
	{
		arr[index] = value;
	}

	const T& Get(int index)
	{
		return arr[index];
	}

private:
	T arr[8];
};



   2. ���� : ��Ʈ �����ڸ� ����Ͽ� �Ʒ��� ������ �ذ�

   2������, bool��� ����, ��Ʈ����


   1.
   int a = 123;

	  a = 0;

	  a = a ? a -> ?�� ���� �����ڰ� ���� �� �ڵ庸�� ������ �ɱ�?

   2.
   int a = 123;
   int b = 456;

   a = a ? b
   b = a ? b
   a = a ? b

   temp�� ������� �ʰ� �ٲٴ¹� ã��

   3.
	  ¦��/Ȧ�� �Ǻ� -> %������� �ʰ�

   4.
	  ����/��� �Ǻ� -> ���迬���� ��� x


   5.
	  2�� �¼����� �ƴ��� �Ǻ� -> �ݺ��� ������� �ʰ�
	  ���� �ι��� �ϸ� �� �� ����

   6.
	  �빮��/�ҹ��� ��ȯ -> +, - �Ⱦ���
	  �ƽ�Ű �ڵ��� �빮�ڴ� ������° ��Ʈ�� ��� 0�̰�
	  �ҹ��ڴ� ��� 1 �̴�.


	  3. ���� : std, stl ����
*/


/*
	23.7.14
	����1 : virtual Ű����� ���� �Լ� ���̺� ����

	����2 : �������̽��� ����ϴ� ���� �����ϱ�

	����3 : SOLID �����ϱ�

	����4 ������ ���� (���� �̿ϼ�.. ����, ���� �� �߰� ���� / �⺻�� ������)
*/

/*
	23.7.13
	���� : ���� ����� ������ ����, ���̾Ƹ�� ��� ���� ����
*/

/*
	23.7.5
	���� : ���ٽ� ����
*/

/*
	23.6.30
	���� : ��� �Լ�
		- �����ϰ� ����
		- ��� �Լ��� ����� �Ǻ���ġ ���� ����
		- (�ʼ�x)��� �Լ��� ����� ������ ž ����


	����
	Won class�� ������ �����ε� �߰��ϱ�
	- ���ϱ�, ������, ������
	- += -= *= /= %=

	class Won
{
public:
	Won(int value) : value(value) {}

	int GetValue() const
	{
		return value;
	}

	int operator+(const Won& rhs)
	{
		return value + rhs.value;
	}
	Won operator-(const Won& rhs)
	{
		return value - rhs.value;
	}

private:
	int value;

};
*/

/*
	23.6.28
	���� : �̱��� ���� ����
*/

/*
	23.6.20
	���� : ���ð��� �����
*/

/*
	23.6.14
	���� : �Լ� ȣ�� �Ծ� (function calling convension) ����

	���� : new�� malloc�� ���̸� �����ϰ� �Ʒ� �ڵ��� �������� ã�ƺ���
	'������'�� ���� �����ϱ�

	struct Test
	{
	  int a;
	  int b;
	   std::string str;
	};

		int main()
	{
		 //Test* test = new Test;
		  Test* test = (Test*)malloc(sizeof(Test));

		  test->a = 10;
		  test->b = 20;
		  test->str = "Hello!!";

		 std::cout << test->a << std::endl;
		 std::cout << test->b << std::endl;
		 std::cout << test->str << std::endl;

		return 0;
	}
*/

/*
	23.6.9
	���� : inline�� macro���� ����
	���� : rttr ����
*/

/*
	23.6.8
	���� : cast ���� 4���� ����
	- static_cast
	- reinterpret_cast
	- dynamic_cast
	- onst_cast
*/

/*
	23.6.7
	�α׶���ũ �����
	- 22������ ����� �������� Ȱ���Ͽ� �α׶���ũ ���� �����
	- �¸� ����, �й�����
	- ����, �÷��̾�, ��, ���� ��� ���ӿ� �����ϴ� ������Ʈ 6���� �̻� �����
	- ���Ϳ� ���� ����
	- ���� �̿��� �̺�Ʈ 2�� �̻� ����
	- �޴� ����

	 ���� : 3���� ������ �������� ���ؼ� �����ϱ�
		- �޸� ����
		- �޸� ����ȭ
		- ��� ������
*/


//23.5.29
/*
	ī����� �����
		- ����, ��Ŀ �� �ϳ� �����Ͽ� �����
		- ��Ģ�� ������Ű ����
		- ������ ���� ����������

	16����Ʈ�� ������ ���� �����ϱ�(�е� ����Ʈ)
*/

//23.5.24
/*
	���� ���� �м�
		- �̹��� �ݿ��ϱ���
		- �� �ڵ带 �м��Ͽ� �ּ� �ޱ�
*/

//23.5.18
/*
	���� ���� �����

	#include<stdio.h>
#include<time.h>
#include<Windows.h>
#define ũ�� 5   // ���� �� ũ�� ����
#define ���� 5  // ���� ����



int game[ũ��][ũ��] = { 0 };
int AI_game[ũ��][ũ��] = { 0 };

int s_int = 0; // ������
int in = 0; // �Է� ���� ����
int AI_in = 0; // AI�� �Է��� ����
int score = 0; // ����
int AI_score = 0; // AI����


void start(); // ������ ����
void AI_start(); // AI ������ ����

void setting();// ����
void output(); // ������ ���
void AI_output(); // AI ������ ���
void input(); // �Է�
void AI_input(); // AI�� �Է�

void Application(); // �Է� ���� �͵��� ����

void check(); // ���� üũ

void END();// ��


//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
int main(void)
{
	start(); //������ ����
	AI_start(); // AI ������ ����
	setting();// ����

	while (true)
	{
		system("cls"); // �����
		if (s_int == 1)
		{
			AI_output(); //AI ������ ���
		}else
		{
			output(); //���
		}
		if (���� <= score || ���� <= AI_score) break;
		input(); // �Է�
		AI_input(); // AI�� �Է�
		Application(); // �Է� ���� �͵��� ����
		check(); // ���� üũ
	}
	END(); // ��
	return 0;
}
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�



void start()
{
	int count = 7;
	for (int i = 0; i < ũ��; i++)
	{
		for (int j = 0; j < ũ��; j++)
		{
			srand((unsigned int)time(NULL) + count);
			int ABC = 0;
			int abc = 0;
			ABC = rand() % (ũ�� * ũ��) + 1;
			count++;

			for (int ii = 0; ii < ũ��; ii++)
			{
				for (int jj = 0; jj < ũ��; jj++)
				{
					if (game[ii][jj] == ABC)
					{
						abc = 1;
						ii = ũ��;
						jj = ũ��;
					}
				}
			}
			if (abc == 0)
			{
				game[i][j] = ABC;
			}
			else if (abc == 1)
			{
				j--;
			}
		}
	}

}
void AI_start()
{
	int count = 10;
	for (int i = 0; i < ũ��; i++)
	{
		for (int j = 0; j < ũ��; j++)
		{
			srand((unsigned int)time(NULL) + count);
			int ABC = 0;
			int abc = 0;
			ABC = rand() % (ũ�� * ũ��) + 1;
			count++;

			for (int ii = 0; ii < ũ��; ii++)
			{
				for (int jj = 0; jj < ũ��; jj++)
				{
					if (AI_game[ii][jj] == ABC)
					{
						abc = 1;
						ii = ũ��;
						jj = ũ��;
					}
				}
			}
			if (abc == 0)
			{
				AI_game[i][j] = ABC;
			}
			else if (abc == 1)
			{
				j--;
			}
		}
	}

}
void setting()
{
	while (true)
	{
		printf("���� ������ ����\n");
		printf("1. ���\n");
		printf("2. ������� �ʴ´�\n");
		printf("�Է� : ");
		scanf_s("%d", &s_int);
		if (s_int == 1 || s_int == 2)
		{
			return;
		}else
		{
			printf("\n�߸� �Է��ϼ̽��ϴ�\n");
			printf("�ٽ� �Է����ּ���\n\n\n");
		}
	}
	return;
}
void output()
{
	printf("---------������---------\n");
	for (int i = 0; i < ũ��; i++)
	{
		for (int j = 0; j < ũ��; j++)
		{
			if (game[i][j] < 10) // 1�ڸ� ���� ���� ���߱�
			{
				printf("[ %d]", game[i][j]);
			}
			else if (game[i][j] == 100) // �׸� �Է�
			{
				printf("[��]");
			}
			else // �׿�
			{
				printf("[%d]", game[i][j]);
			}
		}
		printf("\n");
	}
	printf("����� [ %d ]�� �Է��ϼ̽��ϴ�.\n", in);
	printf("AI�� [ %d ]�� �Է��ϼ̽��ϴ�.\n\n", AI_in);
	printf("����� [ %d ] ����! \n", score);
	printf("����� [ %d ] ����! \n", AI_score);

	return;
} //���
void AI_output()
{
	printf("------������------\t---����� ������---\n");
	for (int i = 0; i < ũ��; i++)
	{
		for (int j = 0; j < ũ��; j++)
		{
			if (game[i][j] < 10) // 1�ڸ� ���� ���� ���߱�
			{
				printf("[ %d]", game[i][j]);
			}
			else if (game[i][j] == 100) // �׸� �Է�
			{
				printf("[��]");
			}
			else // �׿�
			{
				printf("[%d]", game[i][j]);
			}
		}
		printf("\t");
		for (int j = 0; j < ũ��; j++)
		{
			if (AI_game[i][j] < 10) // 1�ڸ� ���� ���� ���߱�
			{
				printf("[ %d]", AI_game[i][j]);
			}
			else if (AI_game[i][j] == 100) // �׸� �Է�
			{
				printf("[��]");
			}
			else // �׿�
			{
				printf("[%d]", AI_game[i][j]);
			}
		}
		printf("\n");
	}
	printf("����� [ %d ]�� �Է��ϼ̽��ϴ�.  \n", in);
	printf("AI�� [ %d ]�� �Է��ϼ̽��ϴ�.  \n", AI_in);
	printf("\n����� [ %d ] ����! \n", score);
	printf("����� [ %d ] ����! \n", AI_score);
	return;
}
void input()
{
	while (true)
	{
		in = 0;
		printf("���ϴ� ��ġ�� ���� �Է��� �ּ���.\n");
		printf("�Է� : ");
		scanf_s(" %d", &in);

		// �Է��� ���� ��ü
		if (in >= 1 && in <= ũ�� * ũ��)
		{
			int abcd = 0;
				for (int i = 0; i < ũ��; i++) {
					for (int j = 0; j < ũ��; j++) {
						if (game[i][j] != in) {
							abcd++;
						}
					}
				}
				if (abcd == 25) {
					printf("�ߺ��� ���� �Է��ϼ̽��ϴ� \n");
					printf("�ٽ� �Է����ּ��� \n\n\n");
				}
				else {
					return;
				}


		}else
		{
			printf("\n\n1 ~ %d������ ���� �Է��ϼž��մϴ� \n", ũ�� * ũ��);
			printf("�ٽ� �Է����ּ��� \n\n\n");
		}



	}

}
void AI_input()
{
	int T = 0;
	while (T <= 2){
		int ppp = 0;
		srand((unsigned int)time(NULL));
		AI_in = 0;
		AI_in = rand() % (ũ�� * ũ��) + 1;

		// �÷��̾���� �ߺ�����
		if (AI_in != in) {
			T++;
			break;
		}

		// �ߺ�����
		if (AI_in >= 1 && AI_in <= ũ�� * ũ��) {
			int abcd = 0;
			for (int i = 0; i < ũ��; i++) {
				for (int j = 0; j < ũ��; j++) {
					if (AI_game[i][j] != AI_in) abcd++;

				}
			}

			if (abcd == ũ��*ũ��) {
				T++;
				break;
			}
		}


	}

	return;
}
void Application()
{
	for (int i = 0; i < ũ��; i++) {
		for (int j = 0; j < ũ��; j++)
		{
			if (in == game[i][j])
			{
				game[i][j] = 100; // 100�� �׸�� �ٲ�
			}
			if (AI_in == game[i][j])
			{
				game[i][j] = 100; // 100�� �׸�� �ٲ�
			}
		}
	}
	for (int i = 0; i < ũ��; i++) {
		for (int j = 0; j < ũ��; j++)
		{
			if (AI_in == AI_game[i][j])
			{
				AI_game[i][j] = 100; // 100�� �׸�� �ٲ�
			}
			if (in == AI_game[i][j])
			{
				AI_game[i][j] = 100; // 100�� �׸�� �ٲ�
			}
		}
	}
}
void check()
{
	score = 0; //�˻��� �ʱ�ȭ

	// �����밢 (���� 1�� ����)
	int L = 0;
	for (int i = 0; i < ũ��; i++) {
		if (game[i][i] == 100) {
			L++;
		}
		if (L == ũ��) {
			score++;
		}
	}

	// ���� �밢 (���� 1���� ���� 1����)
	int R = 0;
	while (true)
	{
		int a = 0;
		int b = (ũ��-1);
		for (int i = 0; i < ũ��; i++) {
			if (game[a][b] == 100) {
				R++;
			}
			if (R == ũ��) {
				score++;
			}
			a++;
			b--;
		}
		break;
	}

	// ���� Ȯ��
	int H = 0;
	for (int j = 0; j < ũ��; j++) {
		H = 0;
		for (int i = 0; i < ũ��; i++) {
			if (game[i][j] == 100) {
				H++;
			}
			if (H == ũ��) {
				score++;
			}

		}
	}

	// ���� Ȯ��
	int W = 0;
	for (int i = 0; i < ũ��; i++)
	{
		W = 0;
		for (int j = 0; j < ũ��; j++)
		{
			if (game[i][j] == 100) {
				W++;
			}
			if (W == ũ��) {
				score++;
			}
		}
	}



	//�ٸ� �˰��� AI üũ
	AI_score = 0;
	int A = 0; // �����밢 üũ(���� 1�� ����)
	int B = 0; // �����밢 üũ(���� 1���� ���� 1����)

	for (int i = 0; i < ũ��; i++)
	{
		int C = 0; // ���� üũ
		int D = 0; // ���� üũ
		for (int j = 0; j < ũ��; j++)
		{
			if (AI_game[i][j] == 100) C++;
			if (AI_game[j][i] == 100) D++;
			if (C == ũ��) AI_score++;
			if (D == ũ��) AI_score++;
		}
		if (AI_game[i][i] == 100) A++;
		if (AI_game[i][(ũ��-1)-i] == 100) B++;
		if (A == ũ��) AI_score++;
		if (B == ũ��) AI_score++;
	}
	return;
}
void END()
{
	if (���� <= score && ���� <= AI_score)
	{
		printf("\n\n���ÿ� %d���̻��� ��� ���º��Դϴ�! \n", ����);
	}
	else if(score <= AI_score)
	{
		printf("\n\n��밡 ���� %d�� ��� �й��ϼ̽��ϴ�... \n", AI_score);

	}else if (AI_score <= score)
	{
		printf("\n\n����� ���� %d���� ��� �¸��Դϴ�!! \n", score);
	}

	return;
}






*/

//23.05.17
/*
	���� : �ø�ƽ, ���ؽ� ���� �����ϱ�

	�ø�ƽ ����
	�ø�ƽ ������ �ǹ̻��� �����Դϴ�.
	������ ������ �ƴϸ� �����Ͽ� ���⵵ ���� ������, ���α׷� ���� ���� ������ �����Դϴ�

	���ؽ� ����
	C�� ��Ģ�� ������ �ʾ��� �� �߻��ϴµ�, �̰��� ������ ���� ������ ����մϴ�
	���� ������ �ַ� ���� ������ �߸鼭, �ڵ������� ����ִ� ������ �����Դϴ�.
	�������  ;(�����ݷ�)�� �;��ϴ� ���� �Ǽ��� �ݷ� ��:���� ������. �̷� ���� ������ ���ý� ������ ���մϴ�.
*/

//23.05.04
/*
text rpg ���׷��̵�

1. ������ �̺�Ʈ�� �ϳ� ����� �߰��ϱ�
2. ���� �ִ� �̺�Ʈ �ϳ� �����ؼ� ���׷��̵�
3. ��带 �Ҹ��� �� �ִ� �̺�Ʈ �߰�
4. �¸� ���� �߰�
5. ���� �̺�Ʈ ���׷��̵�(������ �߰�, ����, ���, ȸ�� ��� �����Ӱ�)

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct
{
	char name[50];
	int hp;
	int atk;
	int gold;
}Pleyer;

typedef struct
{
	char name[50];
	int hp;
	int atk;
	int gold;
}Monster;

void rpg();

int main()
{
	rpg();

	return 0;
}

void rpg()
{
	Pleyer p;
	Monster monster_table[4] = { // �̸�, hp, atk, gold
		{"����� ���̴� ����", 30, 10, 50},
		{"���غ��̴� ����", 50, 20, 50},
		{"���غ��̴� ����", 15, 5, 50},
		{"����", 70, 25, 250}
	};


	printf("���ӿ� ���Ű� ȯ���մϴ�~~\n\n");
	printf("����� �̸���? : ");
	scanf_s("%s", &p.name, sizeof(p.name));

	p.hp = 100;
	p.atk = 10;
	p.gold = 0;

	int ABC = 0;
	int DEF = 0;

	do
	{
		printf("���丮�� Ȯ�� �Ͻðڽ��ϱ�? \n");
		printf("1. Ȯ���Ѵ� \n2. ��ŵ�Ѵ�\n�Է� :	");
		scanf_s("%d", &ABC);

		printf("\n\n");
		switch (ABC)
		{
		case(1):
		{

			printf("���� ����Į������ �����\n");
			printf("���� ����ǰ�� ������ ������ ���� ��ǥ�Դϴ�\n");
			printf("���� �ִ� �߱� ��Ʈ�� ������ ì��� ����մϴ�\n\n\n\n");
			DEF = 1;
			Sleep(1000);
			break;
		}
		case(2):
		{
			printf("���丮�� ��ŵ�ϼ̽��ϴ�\n\n\n");
			DEF = 1;
			Sleep(800);
			break;
		}
		default:
		{
			printf("�߸��� ���� �Է��ϼ̽��ϴ� \n");
			DEF = 0;
			break;
		}
		}

	} while (DEF != 1);

	printf("*********************** ���� ���� ***********************\n\n");
	Sleep(400);

	int A = 18;
	srand((unsigned int)time(NULL));

	while (true)
	{
		if (p.hp <= 0)
		{
			printf("\n\n\n\-------- YOU DIED --------\n\n\n", p.name);
			break;
		}
		if (A <= 1)
		{
			printf("\n\n\n\1���� ������ ������ �������ϴ�.\n");
			printf("������ �����մϴ�.\n\n");
			break;
		}

		system("PAUSE");
		printf("\n\n\n");
		system("cls"); // ����
		printf("���� %d���Դϴ�", A);
		printf("\n\n\n");
		Sleep(1200);


		int RANDOM = rand() % 5;

		switch (RANDOM)
		{
		case(0): // �������� ��� �߰�
		{
			int abc = 0;
			int b = 0;
			printf("������ �� �ִ� ����� �߰��߽��ϴ�\n");

			do
			{
				printf("����� �������ðڽ��ϱ�?\n");
				printf("1. ��������\n");
				printf("2. �������� �ʴ´�\n");
				printf("�Է� : ");
				scanf_s("%d", &abc);
				printf("\n\n");

				switch (abc)
				{
				case(1):
				{
					printf("'����� ��������'�� �����ϼ̽��ϴ�.\n");
					printf("����� �������ϴ�\n");
					A -= 1;
					b = 1;
					break;
				}
				case(2):
				{
				printf("'����� �������� �ʴ´�'�� �����ϼ̽��ϴ�.\n");
				printf("����� �������� �ʾ� %d���� �ӹ��ϴ�\n\n\n",A);
				b = 1;
				break;
				}
				default:
				{
					printf("�߸��Է��ϼ̽��ϴ�\n\n");
					break;
				}
				}

			} while (b != 1);

			Sleep(1000);
			break;
		}
		case(1): // ���� ������
		{
			Monster m = monster_table[rand() % 3];
			printf("%s�� �������ϴ�.\n", m.name);
			printf("������ �����մϴ�.\n\n");
			Sleep(700);


			do
			{
				int a = 0;
				int b = 0;
				do
				{
					printf("���� ����� �������ּ��� \n");
					printf("1.���� 2.��� 3.ī����\n");
					printf("�Է�: ");
					scanf_s("%d", &a);

					switch (a)
					{
					case(1):
					{
						b = 1;
						printf("����� ���� \n\n");
						break;
					}
					case(2):
					{
						b = 1;
						printf("����� ��� \n\n");
						break;
					}
					case(3):
					{
						b = 1;
						printf("����� ī���� \n\n");
						break;
					}
					default:
					{
						b = 0;
						printf("�߸� �Է��ϼ̽��ϴ�. \n\n");
						break;
					}
					}
				} while (b != 1);



				int c = rand() % 2;
				switch (c)
				{
				case(0):
					printf("%s�� ���� \n\n", m.name);
					break;
				case(1):
					printf("%s�� ��� \n\n", m.name);
					break;
				}

				if (c == 0) // ���� ����
				{
					switch (a)
					{
					case(1):
						printf("��Ű� %s�� ���� �����Ͽ� �������� �޾ҽ��ϴ�\n", m.name);
						m.hp -= p.atk;
						p.hp -= m.atk;
						printf("��� HP : %d \n", p.hp);
						printf("%s�� HP : %d \n", m.name, m.hp);
						break;
					case(2):
						printf("����� %s�� ������ ���� �������� ���� �ʾҽ��ϴ� \n", m.name);
						break;
					case(3):
						printf("%s�� ������ ���� �� ī���� ���� \n", m.name);
						printf("����� ������ ġ��Ÿ�� �����ϴ� \n");
						m.hp -= (p.atk * 2);
						printf("%s�� HP : %d \n\n", m.name, m.hp);
						break;
					}
				}
				else if (c == 1) // ���� ���
				{
					switch (a)
					{
					case(1):
						printf("����� ������ %s�� ���ҽ��ϴ�.\n", m.name);
						break;
					case(2):
						printf("��Ű� %s�� ���� �� �Ͽ����ϴ� \n", m.name);
						break;
					case(3):
						printf("����� %s�� �� Ǯ�� �����߽��ϴ� \n", m.name);
						printf("����� %s���� ���� ������ �����ϴ� \n", m.name);
						m.hp -= (p.atk / 2);
						printf("%s�� HP : %d \n\n", m.name, m.hp);
						break;
					}
				}

				if (p.hp <= 0)
				{
					break;
				}
				else if (m.hp <= 0)
				{
					printf("%s�� ���������ϴ� \n", m.name);
					p.gold += m.gold;
					printf("����ǰ���� %d gold�� ������ϴ� \n", m.gold);
					printf("������ ������ : %d gold \n\n", p.gold);
					break;
				}
			} while (true);



			Sleep(1000);
			break;
		}
		case(2): // ������ �Ǹ��ϴ� ��� �߰� (���� ���ݷ� �߰�, ü������ ,������)
		{
			printf("������ �Ǹ��ϴ� ����� �������ϴ�\n\n");
			int b = 0;
			do
			{
				int f = 0;
				printf("1. ���� ����(���ݷ� 10 �߰�) 30.gold\n");
				printf("2. ���� ����(HPȸ�� 20) 10.gold \n");
				printf("3. ������\n");
				printf("�Է� : ");
				scanf_s(" %d", &f);
				printf("\n\n");

				switch (f)
				{
				case(1):
				{
					printf("1. ���� ���Ÿ� �����ϼ̽��ϴ�\n");
					if (p.gold >= 30)
					{
						printf("���⸦ �����ϼ̽��ϴ�\n");
						p.gold -= 30;
						printf("-30 gold\n");
						printf("���� ���� ��� : %d\n", p.gold);
						p.atk += 10;
						printf("���ݷ��� ����ϼ̽��ϴ�\n");
						printf("���� ���ݷ� : %d\n\n\n", p.atk);
						Sleep(500);
					}
					else if (p.gold <= 30)
					{
						printf("���� ��尡 �����մϴ�\n");
						printf("���� ���� ��� : %d gold\n\n\n\n", p.gold);
						Sleep(500);
					}
					b = 0;
					break;
				}

				case(2):
				{
					printf("2. ���� ���Ÿ� �����ϼ̽��ϴ�\n");
					if (p.gold >= 10)
					{
						printf("������ �����ϼ̽��ϴ�\n");
						p.gold -= 10;
						printf("-10 gold\n");
						printf("���� ���� ��� : %d\n", p.gold);
						p.hp += 20;
						printf("ü���� ȸ�� �ϼ̽��ϴ�\n");
						printf("���� ü�� : %d\n\n\n", p.hp);
						Sleep(500);
					}
					else if (p.gold <= 10)
					{
						printf("���� ��尡 �����մϴ�\n");
						printf("���� ���� ��� : %d gold\n\n\n\n", p.gold);
						Sleep(500);
					}
					b = 0;
					break;
				}

				case(3):
				{
					printf("�����⸦ �����ϼ̽��ϴ�\n");
					b = 1;
					break;
				}

				default:
				{
					b = 0;
					printf("�߸� �Է��ϼ̽��ϴ�. \n\n");
					break;
				}
				}


			} while (b != 1);

			Sleep(1000);
			break;
		}
		case(3): // ��ħ HP-
		{
			printf("�������� �� ��ī�ο� ���ǿ� �ܿ����ϴ�\n");
			p.hp -= 5;
			printf("���� HP : %d\n", p.hp);

			Sleep(1000);
			break;
		}
		case(4): // ���� �ִ� �� �߰� +gold
		{
			printf("���� �����ִ� ���� �߰��߽��ϴ� \n");
			int b = 0;
			do
			{

				int f = 0;
				printf("1. ����\n");
				printf("2. ���� �ʴ´� \n");
				printf("�Է� : ");
				scanf_s(" %d", &f);
				printf("\n\n");

				switch (f)
				{
				case(1):
				{
					printf("'����'�� �����ϼ̽��ϴ�\n");
					b = 1;
					int c = rand() % 4;
					switch (c)
					{
					case(0):
					{
						printf("����� ������ �߰��߽��ϴ�\n");
						p.hp += 10;
						printf("������ �Ծ� ü���� ȸ�� �ϼ̽��ϴ�\n");
						printf("+10 HP\n");
						printf("���� ü�� : %d\n\n\n", p.hp);
						Sleep(500);
						break;
					}

					case(1):
					{
						printf("��ī�ο� ���ǿ� �ܿ����ϴ�\n");
						printf("�ƹ��͵� �߰����� ���Ͽ����ϴ�\n");
						p.hp -= 5;
						printf("���� HP : %d\n", p.hp);
						break;
					}

					case(2):
					{
						printf("��ο� Ȯ������ ���� �ٴ��� ���ۿ� ���������ϴ� \n");
						printf("���� �Ʒ��� ���������ϴ� \n");
						printf("������ ������� �ٸ��� ���ƽ��ϴ� \n");
						printf("-15 HP \n");
						p.hp -= 15;
						printf("���� HP : %d\n", p.hp);
						A -= 1;
						break;
					}
					case(3):
					{
						printf("������ �߰��߽��ϴ� \n");
						printf("���ѷ� ������ ���濡 �ֽ��ϴ� \n");
						printf("+15 gold \n");
						p.hp += 15;
						printf("���� gold : %d\n", p.gold);
						break;
					}
					}
					break;
				}

				case(2):
				{
					printf("'���� �ʴ´�'�� �����ϼ̽��ϴ�\n");
					b = 1;
					break;
				}

				default:
				{
					b = 0;
					printf("�߸� �Է��ϼ̽��ϴ�. \n\n");
					break;
				}
				}
				Sleep(500);
				break;

			} while (b != 1);
			Sleep(1000);
			break;
		}
		case(5): // ����
		{
			Monster mm = monster_table[3];
			printf("%s�� �������ϴ�.\n", mm.name);
			printf("������ �����մϴ�.\n\n");
			Sleep(700);


			do
			{
				int a = 0;
				int b = 0;
				do
				{
					printf("���� ����� �������ּ��� \n");
					printf("1.���� 2.��� 3.ī����\n");
					printf("�Է�: ");
					scanf_s("%d", &a);

					switch (a)
					{
					case(1):
						b = 1;
						printf("����� ���� \n\n");
						break;
					case(2):
						b = 1;
						printf("����� ��� \n\n");
						break;
					case(3):
						b = 1;
						printf("����� ī���� \n\n");
						break;
					default:
						b = 0;
						printf("�߸� �Է��ϼ̽��ϴ�. \n\n");
						break;
					}
				} while (b != 1);



				int c = rand() % 3;
				switch (c)
				{
				case(0):
					printf("%s�� ���� \n\n", mm.name);
					break;
				case(1):
					printf("%s�� ��� \n\n", mm.name);
					break;
				case(2):
					printf("%s�� ī���� \n\n", mm.name);
					break;
				}

				if (c == 0) // ���� ����
				{
					switch (a)
					{
					case(1):
						printf("��Ű� %s�� ���� �����Ͽ� �������� �޾ҽ��ϴ�\n", mm.name);
						mm.hp -= p.atk;
						p.hp -= mm.atk;
						printf("��� HP : %d \n", p.hp);
						printf("%s�� HP : %d \n", mm.name, mm.hp);
						break;
					case(2):
						printf("����� %s�� ������ ���� �������� ���� �ʾҽ��ϴ� \n", mm.name);
						break;
					case(3):
						printf("%s�� ������ ���� �� ī���� ���� \n", mm.name);
						printf("����� ������ ġ��Ÿ�� �����ϴ� \n");
						mm.hp -= (p.atk * 2);
						printf("%s�� HP : %d \n\n", mm.name, mm.hp);
						break;
					}
				}
				else if (c == 1) // ���� ���
				{
					switch (a)
					{
					case(1):
						printf("����� ������ %s�� ���ҽ��ϴ�.\n", mm.name);
						break;
					case(2):
						printf("��Ű� %s�� ���� �� �Ͽ����ϴ� \n", mm.name);
						break;
					case(3):
						printf("����� %s�� �� Ǯ�� �����߽��ϴ� \n", mm.name);
						printf("����� %s���� ���� ������ �����ϴ� \n", mm.name);
						mm.hp -= (p.atk / 2);
						printf("%s�� HP : %d \n\n", mm.name, mm.hp);
						break;
					}
				}
				else if (c == 2) // ������ ī����
				{
					switch (a)
					{
					case(1):
						printf("%s�� ����� ������ ���� �� ī���� ���� \n", mm.name);
						printf("����� ġ����� �����ϴ� \n");
						p.hp -= (mm.atk * 2);
						printf("����� HP : %d \n\n", p.hp);
						break;
					case(2):
						printf("%s�� ����� �� Ǯ�� �����߽��ϴ� \n", mm.name);
						printf("%s�� ��ſ��� ���� ������ �����ϴ� \n", mm.name);
						p.hp -= (mm.atk / 2);
						printf("��� HP : %d \n\n", p.hp);
						break;
					case(3):
						printf("��Ű� %s�� ���� ī���͸� �Ͽ����ϴ� \n", mm.name);
						break;
					}
				}

				if (p.hp <= 0)
				{
					break;
				}
				else if (mm.hp <= 0)
				{
					printf("%s�� ���������ϴ� \n", mm.name);
					p.gold += mm.gold;
					printf("����ǰ���� %d gold�� ������ϴ� \n", mm.gold);
					printf("������ ������ : %d gold \n\n", p.gold);
					break;
				}

			} while (true);

			Sleep(1000);
		} while (true);
		}
	}
}``
*/

//23.04.28
/*
	1. ����
		1. ����� 10�� int�� �迭�� ����� �� ���ҿ� ������ ���ڸ� �־��ش�.
		2. ���� 0�� ���� ������� �� ���� ������ش�.
		3. ������������ �����Ͽ� ������ش�.
		4. ������������ �����Ͽ� ������ش�.

		�������� : ���� ������ ū ���� �����ϴ� �� 1, 2, 3,....
		�������� : ū ������ ���� ���� �����ϴ� �� 10, 9, 8, 7....

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void IN(int arr[]); //���� �Է�
void RANDOM(int arr[]); //�����Է�
void UP(int arr[]); //�ø�����
void DOWN(int arr[]); // ��������


int main()
{
	int arr[10];
	int a = 0;
	printf("�Է� ����� ������ �ּ���\n");
	printf("1.�����Է�  2.�����Է�\n");
	printf("�Է� : ");
	scanf_s("%d", &a);

	switch (a)
	{
	case 1:
	{
		printf("�����Է��� �����ϼ̽��ϴ�\n");
		IN(arr);
		break;
	}
	case 2:
	{
		printf("�����Է��� �����ϼ̽��ϴ�\n");
		RANDOM(arr);
		break;
	}
	default:
		printf("�߸� �Է��Ͽ����ϴ�.\n");
		printf("���α׷��� �ٽ� ������ �ּ���.\n");
		return 0;
	}

	int b = 0;
	printf("�ø����� or ���������� ������ �ּ���\n");
	printf("1.�ø�����  2.��������\n");
	printf("�Է� : ");
	scanf_s("%d", &b);

	switch (b)
	{
	case 1:
	{
		printf("�ø������� �����ϼ̽��ϴ�\n");
		UP(arr);
		break;
	}
	case 2:
	{
		printf("���������� �����ϼ̽��ϴ�\n");
		DOWN(arr);
		break;
	}
	default:
		printf("�߸� �Է��Ͽ����ϴ�.\n");
		printf("���α׷��� �ٽ� ������ �ּ���.\n");
		return 0;
	}


	printf("���� ��� : ");
	for (int i = 0; i < 9; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("%d \n", arr[9]);
	return 0;
}




void IN(int arr[]) //���� �Է�
{
	printf("���ڸ� �Է����ּ���\n");

	for (int i = 0; i < 10; i++)
	{
		printf("�Է� : (%d�� ���ҽ��ϴ�)\n", (10 - i));
		scanf_s(" %d", &arr[i]);
	}

}

void RANDOM(int arr[]) //�����Է�
{
	srand((unsigned)time(NULL));

	for (int B = 0; B < 10; B++)
	{
		arr[B] = rand() % (101); //0~100�� ���� ����
	}
}

void UP(int arr[]) //�ø�����
{
	int bum;
	for (int i = 0; i < 10; i++)
	{
		for (int o = 0; o < 10; o++)
		{
			if (arr[i]<arr[o])
			{
				bum = arr[i];
				arr[i] = arr[o];
				arr[o] = bum;
			}

		}
	}

}

void DOWN(int arr[]) // ��������
{
	int bum;
	for (int i = 0; i < 10; i++)
	{
		for (int o = 0; o < 10; o++)
		{
			if (arr[i] > arr[o])
			{
				bum = arr[i];
				arr[i] = arr[o];
				arr[o] = bum;
			}

		}
	}
}


	2. ����
		������ ȣ�� �ο����� �Է¹ް�
		������ �ѿ�, �ش� ����Ʈ�� �� �ο��� ����ϴ� �Լ�
		3�� 5ȣ �̻�

#include<stdio.h>
#include<stdlib.h>
#include<time.h>




int main()
{
	int arr[3][5];

	int a = 0;
	printf("�Է� ����� ������ �ּ���\n");
	printf("1.�����Է�  2.�����Է�\n");
	printf("�Է� : ");
	scanf_s("%d", &a);

	switch (a)
	{
	case 1:
	{
		printf("�����Է��� �����ϼ̽��ϴ�\n\n");
		printf("�α��� �Է����ּ���\n");

		for (int i = 0; i < 3; i++)
			for (int o = 0; o < 5; o++)
			{
				printf("�Է� : %d�� %dȣ �Դϴ�)\n", (i+1), (o+1));
				scanf_s(" %d", &arr[i][o]);
			}
		break;
	}
	case 2:
	{
		printf("�����Է��� �����ϼ̽��ϴ�\n\n");
		srand((unsigned)time(NULL));

		for (int i = 0; i < 3; i++)
			for (int o = 0; o < 5; o++)
			{
				arr[i][o] = rand() % (8+1); //���� ����
			}
		break;
	}
	default:
		printf("�߸� �Է��Ͽ����ϴ�.\n");
		printf("���α׷��� �ٽ� ������ �ּ���.\n");
		return 0;
	}


	for (int i = 0; i < 3; i++)
	{
		int A = 0;
		for (int o = 0; o < 3; o++)
		{
			A += arr[i][o];
		}
		printf("%d���� �ѿ� : %d�� �Դϴ�. \n", (i + 1), A);
	}

	int A = 0;
	int B = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int o = 0; o < 3; o++)
		{
			B += arr[i][o];
		}
		A += B;
	}

	printf("����Ʈ�� �ѿ� : %d�� �Դϴ�. \n", B);

	return 0;
}



*/

//23.04.26
/*
	1. ����: ���׸���
	//*****
	//****
	//***
	//**
	//*

	//*****
	// ****
	//  ***
	//   **
	//    *

#include<stdio.h>

int main()
{
	int a = 0;
	printf("���� �Է����ּ��� : ");
	scanf_s("%d", &a);

	for (int b = 1; b <= a; b++) //��
	{
		for (int c = 0; c < b; c++) //����
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

#include<stdio.h>

int main()
{
	int a = 0;
	printf("���� �Է����ּ��� : ");
	scanf_s("%d", &a);

	for (int b = 0; b < a; b++) //��
	{
		for (int c = 0; c < b; c++) //����
		{
			printf(" ");
		}
		for(int d =0; d < a-b; d++) // ��
			printf("*");
		printf("\n");
	}

	return 0;
}


2. ���� : int�� �� num1, num2 �� �޾� num1^num2 ��
��ȯ�ϴ� �Լ� pow�ۼ�

#include<stdio.h>
int IN() //�Է�
{
	int in;
	printf("���ڸ� �Է����ּ��� : ");
	scanf_s("%d", &in);
	return in;
}
int pow(int a, int b) //���� ���
{
	int A = 1;
	for(int c = b; c >= 1; c--)
	{
		A *= a;
	}
	return A;
}

int main()
{
	printf("������ ���ڸ� �Է��ϼ���\n");
	int X1 = IN();
	printf("������(����)�� �Ͻðڽ��ϱ�?\n");
	int X2 = IN();

	printf("%d�� %d�� = %d \n", X1, X2, pow(X1, X2));
	return 0;
}


*/

// 23.04.21
/*
	1. ���� : ���� ���� �� ���� ���׷��̵�
			- ��밡 �������� ������ �����ϱ�
			- 3�� 2����

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ���� 1
#define ���� 2
#define �� 3
//1<2<3<1

int main()
{
	srand((unsigned int)time(NULL));
	int A = 0, B = 0;//A ����, B ���
	int a = 0, b = 0;//a ����, b ��� ����
	int Q = 0; //���������� �¸� ����

	do
	{
		printf("���� ���� ���� �����ϰڽ��ϴ�. \n");
		printf("3�� 2������ �Դϴ�. \n");


		printf("[1: ���� 2: ���� 3. ��]\n\n"); //�Է�
		printf("�Է� : ");
		scanf_s("%d", &A);

		if (A > 0 && A < 4);  //�߸��� �Է��ϰ�� ����
		else
		{
			printf("�߸��� ���� �Է��Ͽ����ϴ�\n");
			printf("���α׷��� �ٽ� �����Ͽ� �ּ���.\n");
			return 0;
		}

		B = (rand() % 3 + 1); //������

		switch (A)
		{
		case ����:
			printf("����� ������ �½��ϴ�\n"); break;
		case ����:
			printf("����� ������ �½��ϴ�\n"); break;
		case ��:
			printf("����� ���� �½��ϴ�\n"); break;
		}
		switch (B)
		{
		case ����:
			printf("��밡 ������ �½��ϴ�\n"); break;
		case ����:
			printf("��밡 ������ �½��ϴ�\n"); break;
		case ��:
			printf("��밡 ���� �½��ϴ�\n"); break;
		}

		if (A == B) Q = 1; //���
		else if (B > ((A + 1) % 3)) Q = 2;
		else Q = 3;

		switch (Q)
		{
		case 1:
			printf("�����ϴ�\n\n\n");
			break;
		case 2:
			printf("�̰���ϴ�\n\n\n");
			++a;
			printf("�� : %d //��� : %d \n\n\n", a, b);
			break;
		case 3:
			printf("�����ϴ�\n\n\n");
			++b;
			printf("�� : %d //��� : %d \n\n\n", a, b);
			break;
		}
	}while (a < 2 && b < 2);

	if (a == 2) printf("2���� ���� ��� �¸��ϼ̽��ϴ�!!\n\n");
	else printf("��밡 2���� ���� ��� �й��ϼ̽��ϴ�...\n\n");


	printf("**********���α׷��� �����մϴ�**********\n");

	return 0;
}


	2. ���� : �� �� �� ���� �����
	#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ���� 1
#define ���� 2
#define �� 3
//1<2<3<1

int main()
{
	srand((unsigned int)time(NULL));
	int A = 0, B = 0; //A ����, B ���
	int a = 0, b = 0; //a ����, b ��� ����
	int Q = 0, C = 0; //Q = ���������� �¸� ����,  C = ����� ���ݱ�
	int D = 0; //D = ���Ƚ��
	printf("�� �� �� ������ �����ϰڽ��ϴ�. \n");
	printf("3�� 2������ �Դϴ�. \n");

	do
	{
		do
		{
			++D;
			printf("%d��° ����\n\n", D);
		printf("[1: ���� 2: ���� 3. ��]\n\n"); //�Է�
		printf("�Է� : ");
		scanf_s("%d", &A);

		if (A > 0 && A < 4);  //�߸��� �Է��ϰ�� ����
		else
		{
			printf("�߸��� ���� �Է��Ͽ����ϴ�\n");
			printf("���α׷��� �ٽ� �����Ͽ� �ּ���.\n");
			return 0;
		}

		B = (rand() % 3 + 1); //������

		switch (A)
		{
		case ����:
			printf("����� ������ �½��ϴ�\n"); break;
		case ����:
			printf("����� ������ �½��ϴ�\n"); break;
		case ��:
			printf("����� ���� �½��ϴ�\n"); break;
		}
		switch (B)
		{
		case ����:
			printf("��밡 ������ �½��ϴ�\n"); break;
		case ����:
			printf("��밡 ������ �½��ϴ�\n"); break;
		case ��:
			printf("��밡 ���� �½��ϴ�\n"); break;
		}

		if (A == B) Q = 1; //���
		else if (B > ((A + 1) % 3)) Q = 2;
		else Q = 3;

		switch (Q)
		{
		case 1:
			printf("�����ϴ�\n\n\n");
			break;
		case 2:
			printf("�̰���ϴ�\n\n\n");
			C = 1;
			break;
		case 3:
			printf("�����ϴ�\n\n\n");
			C = 2;
			break;
		}
		} while (C==1 && C==2);


		//����� ����

		do
		{
			Q = 0;
			switch (C)
			{
			case 1:
				printf("\n����� ���ݱ�\n\n\n");
				break;
			case 2:
				printf("\n����� ���ݱ�\n\n\n");
				break;
			}
			printf("\n[1: ���� 2: ���� 3. ��]\n\n");
			printf("�Է� : ");
			scanf_s("%d", &A);

			if (A > 0 && A < 4);  //�߸��� �Է��ϰ�� ����
			else
			{
				printf("�߸��� ���� �Է��Ͽ����ϴ�\n");
				printf("���α׷��� �ٽ� �����Ͽ� �ּ���.\n");
				return 0;
			}
			B = (rand() % 3 + 1);

			switch (A)
			{
			case ����:
				printf("����� ������ �½��ϴ�\n"); break;
			case ����:
				printf("����� ������ �½��ϴ�\n"); break;
			case ��:
				printf("����� ���� �½��ϴ�\n"); break;
			}
			switch (B)
			{
			case ����:
				printf("��밡 ������ �½��ϴ�\n"); break;
			case ����:
				printf("��밡 ������ �½��ϴ�\n"); break;
			case ��:
				printf("��밡 ���� �½��ϴ�\n"); break;
			}

			if (A == B) Q = 1; //���
			else if (B > ((A + 1) % 3)) Q = 2;
			else Q = 3;


			switch (C)
			{
			case 1:
				switch (Q)
				{
				case 1: //������
					printf("�̰���ϴ�!\n\n");
					C = 0;
					++a;
					printf("�� : %d / ��� : %d \n\n\n\n", a, b);
					break;
				case 2: //�̱涧
					C = 1;
					break;
				case 3: //����
					C = 2;
					break;
				}
				break;
			case 2:
				switch (Q)
				{
				case 1: //������
					printf("�����ϴ�....\n\n");
					C = 0;
					++b;
					printf("�� : %d / ��� : %d \n\n\n\n", a, b);
					break;
				case 2: //�̱涧
					C = 2;
					break;
				case 3: //����
					C = 1;
					break;
				}
			}


		} while (C==1||C==2);

	}while (a < 2 && b < 2);

	if (a == 2) printf("2���� ���� ��� �¸��ϼ̽��ϴ�!!\n\n");
	else printf("��밡 2���� ���� ��� �й��ϼ̽��ϴ�...\n\n");


	printf("**********���α׷��� �����մϴ�**********\n");

	return 0;
}
*/

// 23.04.20
/*
	1. ���� : %c�� ���� ������ �׳� �Ѿ�� ���� �����ϱ�
		scanf�� �Է¹��� �ÿ� ���������� ������ �ʴ� ���ڵ�(����, �ٹٲ� ��)�� ���ۿ� �״�� �����ְ� �Ǵµ�,
		%c�� �װ͵��� ����Ϸ��� �ؼ� �׷����ϴ�. �տ� ������ �ϳ� �־��ָ�, �̷��� ���ڵ��� ������ �Է��� �޴� ������ �˰� �ֽ��ϴ�.


	2. ���� : ���⸦ ������ �ٸ� �ذ����� ã�ƺ���
		getchar(); ����ϱ� : getchar()�� scanf�� ����� ���ڿ��� �Է¹޴� �Լ��� �Դϴ�.
		ù��° scanf����� getchar(void)�� ����ϸ�  �Է� ����, �� �Է¹޴� ���� �ȿ� �ִ� �̻��� �͵��� �ʱ�ȭ �Ǳ⶧����
		scanf�� ���������� ����� �� �ְԵ˴ϴ�



	3. ���� : bmi ���� ���׷��̵�
		- ���� bmi ��ġ�� ���� ��ü�� , ���� , ��ü��, �� ����ϱ�
		#include<stdio.h>

	int main()
		{
			float A = 0, B = 0, C = 0;

			printf("������ ǥ�����ּ��� : ");
			scanf_s("%f", &A);

			printf("ü���� ǥ�����ּ��� : ");
			scanf_s("%f", &B);

			C = B / ((A * A)/10000);
			printf("��ü��������(BMI) : %.2f",C);

			if (C <= 20)
				{
					printf(" BMI���� ��� ��ü���Դϴ�\n\n");
				}

			else if (C <= 24)
				{
					printf(" BMI���� ��� �����Դϴ�\n\n");
				}

			else if (C <= 30)
				{
					printf(" BMI���� ��� ��ü���Դϴ�\n\n");
				}

			else if (C >= 30)
				{
					printf(" BMI���� ��� ���Դϴ�\n\n");
				}


			return 0;
		}
	4. ���� : ���� ���� �� ���� �����
		- ������ ������ ����
		- �÷��̾ ���� ��쿡 ���� ��, ��, ���º� ���

		#include<stdio.h>

#define ���� 1
#define ���� 2
#define �� 3

int main()
{
	printf("���� ���� �� ������ �����ϰڽ��ϴ�. \n");
	printf("[1: ���� 2: ���� 3. ��]\n");
	printf("�Է� : ");
	int A;
	scanf_s("%d", &A);

	switch (A)
	{
	case ����:
		printf("���� �����ϴ�.\n");
		break;

	case ����:
		printf("��뿡�� �̰���ϴ�.\n");
		break;

	case ��:
		printf("��뿡�� �����ϴ�.\n");
		break;

		return 0;
	}
}



*/

// 23.04.19
/*
	1. ���� : ��Ʈ �÷��װ� �������� �����ϱ�.
	2. ���� :  �� ������ ����
	3. ���� : ȯ�� ���� �����
	4. ���� : bmi ���� �����
*/

// 23.04.13
/*
	1���� : escape sequence, format specifier ����

	2. ���� : printf�� �ڱ� �Ұ� �ۼ�

	3.overflow�� underflow ����

	4. � ǥ�������� ã�� (���� ǥ���)

	5. ���� : ASCI�ڵ� �����ϱ�
*/



