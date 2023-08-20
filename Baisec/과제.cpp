
//단축키
/*
//Alt + 오른쪽 방향키 : 자동완성활성화

//윈도우 + g : 화면녹화
//윈도우 + Shift + s : 화면캡쳐

// ctrl + w : 커서위치 전체 선택

// ctrl + d						: 방향으로 행 복사
// Alt + 키보드 화살표 위, 아래	: 행 이동

// ctrl + k + c : 선택 영역 주석
// ctrl + k + u : 선택 영역 주석 해제

// ctrl + k + f : 자동 정렬

// Alt + Shift + 마우스 드래그 : 선택부분의 열을 전체 선택

// ctrl + k + s : 선택된 영역을 &로 감싸줌

// alt + shift + 방향키 : 방향키 방향으로 영역을 넓임



*/

/*
	23.6.20
	과제 : 슈팅게임 만들기

*/

/*
	23.6.14
	과제 : 함수 호출 규약 (function calling convension) 조사

	과제 : new와 malloc의 차이를 조사하고 아래 코드의 문제점을 찾아보기
	'생성자'에 대해 조사하기

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
	과제 : inline과 macro차이 조사
	과제 : rttr 조사
*/

/*
	23.6.8
	과제 : cast 종류 4가지 조사
	- static_cast
	- reinterpret_cast
	- dynamic_cast
	- onst_cast
*/

/*
	23.6.7
	로그라이크 만들기
	- 22번에서 배웠던 열거형을 활용하여 로그라이크 게임 만들기
	- 승리 조건, 패배조건
	- 몬스터, 플레이어, 벽, 함정 등등 게임에 등장하는 오브젝트 6종류 이상 만들기
	- 몬스터와 전투 구현
	- 전투 이외의 이벤트 2개 이상 구현
	- 메뉴 구현

	 과제 : 3가지 문제와 방지법에 대해서 조사하기
		- 메모리 누수
		- 메모리 단편화
		- 허상 포인터
*/


//23.5.29
/*
	카드게임 만들기
		- 섯다, 포커 중 하나 선택하여 만들기
		- 규칙은 나무위키 참고
		- 다음주 수업 시작전까지

	16바이트가 나오는 이유 조사하기(패딩 바이트)
*/

//23.5.24
/*
	빙고 게임 분석
		- 이번주 금요일까지
		- 각 코드를 분석하여 주석 달기
*/

//23.5.18
/*
	빙고 게임 만들기

	#include<stdio.h>
#include<time.h>
#include<Windows.h>
#define 크기 5   // 게임 판 크기 조절
#define 점수 5  // 점수 조절



int game[크기][크기] = { 0 };
int AI_game[크기][크기] = { 0 };

int s_int = 0; // 설정값
int in = 0; // 입력 받은 숫자
int AI_in = 0; // AI가 입력한 숫자
int score = 0; // 점수
int AI_score = 0; // AI점수


void start(); // 빙고판 생성
void AI_start(); // AI 빙고판 생성

void setting();// 설정
void output(); // 게임판 출력
void AI_output(); // AI 게임판 출력
void input(); // 입력
void AI_input(); // AI의 입력

void Application(); // 입력 받은 것들을 적용

void check(); // 빙고 체크

void END();// 끝


//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
int main(void)
{
	start(); //빙고판 생성
	AI_start(); // AI 빙고판 생성
	setting();// 설정

	while (true)
	{
		system("cls"); // 지우기
		if (s_int == 1)
		{
			AI_output(); //AI 게임판 출력
		}else
		{
			output(); //출력
		}
		if (점수 <= score || 점수 <= AI_score) break;
		input(); // 입력
		AI_input(); // AI의 입력
		Application(); // 입력 받은 것들을 적용
		check(); // 빙고 체크
	}
	END(); // 끝
	return 0;
}
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ



void start()
{
	int count = 7;
	for (int i = 0; i < 크기; i++)
	{
		for (int j = 0; j < 크기; j++)
		{
			srand((unsigned int)time(NULL) + count);
			int ABC = 0;
			int abc = 0;
			ABC = rand() % (크기 * 크기) + 1;
			count++;

			for (int ii = 0; ii < 크기; ii++)
			{
				for (int jj = 0; jj < 크기; jj++)
				{
					if (game[ii][jj] == ABC)
					{
						abc = 1;
						ii = 크기;
						jj = 크기;
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
	for (int i = 0; i < 크기; i++)
	{
		for (int j = 0; j < 크기; j++)
		{
			srand((unsigned int)time(NULL) + count);
			int ABC = 0;
			int abc = 0;
			ABC = rand() % (크기 * 크기) + 1;
			count++;

			for (int ii = 0; ii < 크기; ii++)
			{
				for (int jj = 0; jj < 크기; jj++)
				{
					if (AI_game[ii][jj] == ABC)
					{
						abc = 1;
						ii = 크기;
						jj = 크기;
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
		printf("상대방 빙고판 보기\n");
		printf("1. 출력\n");
		printf("2. 출력하지 않는다\n");
		printf("입력 : ");
		scanf_s("%d", &s_int);
		if (s_int == 1 || s_int == 2)
		{
			return;
		}else
		{
			printf("\n잘못 입력하셨습니다\n");
			printf("다시 입력해주세요\n\n\n");
		}
	}
	return;
}
void output()
{
	printf("---------빙고판---------\n");
	for (int i = 0; i < 크기; i++)
	{
		for (int j = 0; j < 크기; j++)
		{
			if (game[i][j] < 10) // 1자리 숫자 길이 맞추기
			{
				printf("[ %d]", game[i][j]);
			}
			else if (game[i][j] == 100) // 네모 입력
			{
				printf("[■]");
			}
			else // 그외
			{
				printf("[%d]", game[i][j]);
			}
		}
		printf("\n");
	}
	printf("당신은 [ %d ]을 입력하셨습니다.\n", in);
	printf("AI는 [ %d ]을 입력하셨습니다.\n\n", AI_in);
	printf("당신의 [ %d ] 빙고! \n", score);
	printf("상대의 [ %d ] 빙고! \n", AI_score);

	return;
} //출력
void AI_output()
{
	printf("------빙고판------\t---상대의 빙고판---\n");
	for (int i = 0; i < 크기; i++)
	{
		for (int j = 0; j < 크기; j++)
		{
			if (game[i][j] < 10) // 1자리 숫자 길이 맞추기
			{
				printf("[ %d]", game[i][j]);
			}
			else if (game[i][j] == 100) // 네모 입력
			{
				printf("[■]");
			}
			else // 그외
			{
				printf("[%d]", game[i][j]);
			}
		}
		printf("\t");
		for (int j = 0; j < 크기; j++)
		{
			if (AI_game[i][j] < 10) // 1자리 숫자 길이 맞추기
			{
				printf("[ %d]", AI_game[i][j]);
			}
			else if (AI_game[i][j] == 100) // 네모 입력
			{
				printf("[■]");
			}
			else // 그외
			{
				printf("[%d]", AI_game[i][j]);
			}
		}
		printf("\n");
	}
	printf("당신은 [ %d ]을 입력하셨습니다.  \n", in);
	printf("AI는 [ %d ]을 입력하셨습니다.  \n", AI_in);
	printf("\n당신의 [ %d ] 빙고! \n", score);
	printf("상대의 [ %d ] 빙고! \n", AI_score);
	return;
}
void input()
{
	while (true)
	{
		in = 0;
		printf("원하는 위치의 수를 입력해 주세요.\n");
		printf("입력 : ");
		scanf_s(" %d", &in);

		// 입력한 숫자 교체
		if (in >= 1 && in <= 크기 * 크기)
		{
			int abcd = 0;
				for (int i = 0; i < 크기; i++) {
					for (int j = 0; j < 크기; j++) {
						if (game[i][j] != in) {
							abcd++;
						}
					}
				}
				if (abcd == 25) {
					printf("중복된 값을 입력하셨습니다 \n");
					printf("다시 입력해주세요 \n\n\n");
				}
				else {
					return;
				}


		}else
		{
			printf("\n\n1 ~ %d사이의 값을 입력하셔야합니다 \n", 크기 * 크기);
			printf("다시 입력해주세요 \n\n\n");
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
		AI_in = rand() % (크기 * 크기) + 1;

		// 플레이어와의 중복방지
		if (AI_in != in) {
			T++;
			break;
		}

		// 중복방지
		if (AI_in >= 1 && AI_in <= 크기 * 크기) {
			int abcd = 0;
			for (int i = 0; i < 크기; i++) {
				for (int j = 0; j < 크기; j++) {
					if (AI_game[i][j] != AI_in) abcd++;

				}
			}

			if (abcd == 크기*크기) {
				T++;
				break;
			}
		}


	}

	return;
}
void Application()
{
	for (int i = 0; i < 크기; i++) {
		for (int j = 0; j < 크기; j++)
		{
			if (in == game[i][j])
			{
				game[i][j] = 100; // 100이 네모로 바뀜
			}
			if (AI_in == game[i][j])
			{
				game[i][j] = 100; // 100이 네모로 바뀜
			}
		}
	}
	for (int i = 0; i < 크기; i++) {
		for (int j = 0; j < 크기; j++)
		{
			if (AI_in == AI_game[i][j])
			{
				AI_game[i][j] = 100; // 100이 네모로 바뀜
			}
			if (in == AI_game[i][j])
			{
				AI_game[i][j] = 100; // 100이 네모로 바뀜
			}
		}
	}
}
void check()
{
	score = 0; //검사전 초기화

	// 좌측대각 (각각 1씩 증가)
	int L = 0;
	for (int i = 0; i < 크기; i++) {
		if (game[i][i] == 100) {
			L++;
		}
		if (L == 크기) {
			score++;
		}
	}

	// 우측 대각 (가로 1증가 세로 1감소)
	int R = 0;
	while (true)
	{
		int a = 0;
		int b = (크기-1);
		for (int i = 0; i < 크기; i++) {
			if (game[a][b] == 100) {
				R++;
			}
			if (R == 크기) {
				score++;
			}
			a++;
			b--;
		}
		break;
	}

	// 세로 확인
	int H = 0;
	for (int j = 0; j < 크기; j++) {
		H = 0;
		for (int i = 0; i < 크기; i++) {
			if (game[i][j] == 100) {
				H++;
			}
			if (H == 크기) {
				score++;
			}

		}
	}

	// 가로 확인
	int W = 0;
	for (int i = 0; i < 크기; i++)
	{
		W = 0;
		for (int j = 0; j < 크기; j++)
		{
			if (game[i][j] == 100) {
				W++;
			}
			if (W == 크기) {
				score++;
			}
		}
	}



	//다른 알고리즘 AI 체크
	AI_score = 0;
	int A = 0; // 좌측대각 체크(각각 1씩 증가)
	int B = 0; // 우측대각 체크(가로 1증가 세로 1감소)

	for (int i = 0; i < 크기; i++)
	{
		int C = 0; // 가로 체크
		int D = 0; // 세로 체크
		for (int j = 0; j < 크기; j++)
		{
			if (AI_game[i][j] == 100) C++;
			if (AI_game[j][i] == 100) D++;
			if (C == 크기) AI_score++;
			if (D == 크기) AI_score++;
		}
		if (AI_game[i][i] == 100) A++;
		if (AI_game[i][(크기-1)-i] == 100) B++;
		if (A == 크기) AI_score++;
		if (B == 크기) AI_score++;
	}
	return;
}
void END()
{
	if (점수 <= score && 점수 <= AI_score)
	{
		printf("\n\n동시에 %d점이상을 얻어 무승부입니다! \n", 점수);
	}
	else if(score <= AI_score)
	{
		printf("\n\n상대가 먼저 %d을 얻어 패배하셨습니다... \n", AI_score);

	}else if (AI_score <= score)
	{
		printf("\n\n당신이 먼저 %d점을 얻어 승리입니다!! \n", score);
	}

	return;
}






*/

//23.05.17
/*
	과제 : 시맨틱, 신텍스 에러 조사하기

	시맨틱 에러
	시맨틱 에러는 의미상의 에러입니다.
	문법적 오류가 아니며 컴파일에 영향도 주지 않으나, 프로그램 로직 상의 논리적인 오류입니다

	신텍스 에러
	C의 규칙을 따르지 않았을 때 발생하는데, 이것은 영어의 문법 오류와 비슷합니다
	개발 툴에서 주로 빨간 밑줄이 뜨면서, 자동적으로 잡아주는 종류의 에러입니다.
	예를들어  ;(세미콜론)이 와야하는 곳에 실수로 콜론 ‘:’을 적었다. 이런 식의 오류는 신택스 에러에 속합니다.
*/

//23.05.04
/*
text rpg 업그레이드

1. 본인이 이벤트를 하나 만들어 추가하기
2. 원래 있던 이벤트 하나 선택해서 업그레이드
3. 골드를 소모할 수 있는 이벤트 추가
4. 승리 조건 추가
5. 전투 이벤트 업그레이드(선택지 추가, 공격, 방어, 회복 등등 자유롭게)

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
	Monster monster_table[4] = { // 이름, hp, atk, gold
		{"평범해 보이는 좀비", 30, 10, 50},
		{"강해보이는 좀비", 50, 20, 50},
		{"약해보이는 좀비", 15, 5, 50},
		{"강도", 70, 25, 250}
	};


	printf("게임에 오신걸 환영합니다~~\n\n");
	printf("당신의 이름은? : ");
	scanf_s("%s", &p.name, sizeof(p.name));

	p.hp = 100;
	p.atk = 10;
	p.gold = 0;

	int ABC = 0;
	int DEF = 0;

	do
	{
		printf("스토리를 확인 하시겠습니까? \n");
		printf("1. 확인한다 \n2. 스킵한다\n입력 :	");
		scanf_s("%d", &ABC);

		printf("\n\n");
		switch (ABC)
		{
		case(1):
		{

			printf("좀비 아포칼립스의 세계관\n");
			printf("집에 생필품이 떨어져 나가는 것이 목표입니다\n");
			printf("집에 있던 야구 배트와 가방을 챙기며 출발합니다\n\n\n\n");
			DEF = 1;
			Sleep(1000);
			break;
		}
		case(2):
		{
			printf("스토리를 스킵하셨습니다\n\n\n");
			DEF = 1;
			Sleep(800);
			break;
		}
		default:
		{
			printf("잘못된 값을 입력하셨습니다 \n");
			DEF = 0;
			break;
		}
		}

	} while (DEF != 1);

	printf("*********************** 게임 시작 ***********************\n\n");
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
			printf("\n\n\n\1층에 도착해 밖으로 나갔습니다.\n");
			printf("게임을 종료합니다.\n\n");
			break;
		}

		system("PAUSE");
		printf("\n\n\n");
		system("cls"); // 지움
		printf("현재 %d층입니다", A);
		printf("\n\n\n");
		Sleep(1200);


		int RANDOM = rand() % 5;

		switch (RANDOM)
		{
		case(0): // 내려가는 계단 발견
		{
			int abc = 0;
			int b = 0;
			printf("내려갈 수 있는 계단을 발견했습니다\n");

			do
			{
				printf("계단을 내려가시겠습니까?\n");
				printf("1. 내려간다\n");
				printf("2. 내려가지 않는다\n");
				printf("입력 : ");
				scanf_s("%d", &abc);
				printf("\n\n");

				switch (abc)
				{
				case(1):
				{
					printf("'계단을 내려간다'를 선택하셨습니다.\n");
					printf("계단을 내려갑니다\n");
					A -= 1;
					b = 1;
					break;
				}
				case(2):
				{
				printf("'계단을 내려가지 않는다'를 선택하셨습니다.\n");
				printf("계단을 내려가지 않아 %d층에 머뭅니다\n\n\n",A);
				b = 1;
				break;
				}
				default:
				{
					printf("잘못입력하셨습니다\n\n");
					break;
				}
				}

			} while (b != 1);

			Sleep(1000);
			break;
		}
		case(1): // 좀비 만나기
		{
			Monster m = monster_table[rand() % 3];
			printf("%s를 만났습니다.\n", m.name);
			printf("전투를 시작합니다.\n\n");
			Sleep(700);


			do
			{
				int a = 0;
				int b = 0;
				do
				{
					printf("전투 방식을 선택해주세요 \n");
					printf("1.공격 2.방어 3.카운터\n");
					printf("입력: ");
					scanf_s("%d", &a);

					switch (a)
					{
					case(1):
					{
						b = 1;
						printf("당신의 공격 \n\n");
						break;
					}
					case(2):
					{
						b = 1;
						printf("당신의 방어 \n\n");
						break;
					}
					case(3):
					{
						b = 1;
						printf("당신의 카운터 \n\n");
						break;
					}
					default:
					{
						b = 0;
						printf("잘못 입력하셨습니다. \n\n");
						break;
					}
					}
				} while (b != 1);



				int c = rand() % 2;
				switch (c)
				{
				case(0):
					printf("%s의 공격 \n\n", m.name);
					break;
				case(1):
					printf("%s의 방어 \n\n", m.name);
					break;
				}

				if (c == 0) // 몬스터 공격
				{
					switch (a)
					{
					case(1):
						printf("당신과 %s가 서로 공격하여 데미지를 받았습니다\n", m.name);
						m.hp -= p.atk;
						p.hp -= m.atk;
						printf("당신 HP : %d \n", p.hp);
						printf("%s의 HP : %d \n", m.name, m.hp);
						break;
					case(2):
						printf("당신이 %s의 공격을 막아 데미지를 받지 않았습니다 \n", m.name);
						break;
					case(3):
						printf("%s의 공격을 피한 후 카운터 공격 \n", m.name);
						printf("당신의 공격이 치명타를 입힙니다 \n");
						m.hp -= (p.atk * 2);
						printf("%s의 HP : %d \n\n", m.name, m.hp);
						break;
					}
				}
				else if (c == 1) // 몬스터 방어
				{
					switch (a)
					{
					case(1):
						printf("당신의 공격을 %s가 막았습니다.\n", m.name);
						break;
					case(2):
						printf("당신과 %s이 서로 방어를 하였습니다 \n", m.name);
						break;
					case(3):
						printf("당신이 %s의 방어를 풀며 공격했습니다 \n", m.name);
						printf("당신의 %s에게 약한 공격을 입힙니다 \n", m.name);
						m.hp -= (p.atk / 2);
						printf("%s의 HP : %d \n\n", m.name, m.hp);
						break;
					}
				}

				if (p.hp <= 0)
				{
					break;
				}
				else if (m.hp <= 0)
				{
					printf("%s가 쓰러졌습니다 \n", m.name);
					p.gold += m.gold;
					printf("전리품으로 %d gold를 얻었습니다 \n", m.gold);
					printf("현재의 소지금 : %d gold \n\n", p.gold);
					break;
				}
			} while (true);



			Sleep(1000);
			break;
		}
		case(2): // 물건을 판매하는 사람 발견 (무기 공격력 추가, 체력포션 ,나가기)
		{
			printf("물건을 판매하는 사람을 만났습니다\n\n");
			int b = 0;
			do
			{
				int f = 0;
				printf("1. 무기 구매(공격력 10 추가) 30.gold\n");
				printf("2. 음식 구매(HP회복 20) 10.gold \n");
				printf("3. 나가기\n");
				printf("입력 : ");
				scanf_s(" %d", &f);
				printf("\n\n");

				switch (f)
				{
				case(1):
				{
					printf("1. 무기 구매를 선택하셨습니다\n");
					if (p.gold >= 30)
					{
						printf("무기를 구매하셨습니다\n");
						p.gold -= 30;
						printf("-30 gold\n");
						printf("현재 보유 골드 : %d\n", p.gold);
						p.atk += 10;
						printf("공격력이 상승하셨습니다\n");
						printf("현재 공격력 : %d\n\n\n", p.atk);
						Sleep(500);
					}
					else if (p.gold <= 30)
					{
						printf("소지 골드가 부족합니다\n");
						printf("현재 보유 골드 : %d gold\n\n\n\n", p.gold);
						Sleep(500);
					}
					b = 0;
					break;
				}

				case(2):
				{
					printf("2. 음식 구매를 선택하셨습니다\n");
					if (p.gold >= 10)
					{
						printf("음식을 구매하셨습니다\n");
						p.gold -= 10;
						printf("-10 gold\n");
						printf("현재 보유 골드 : %d\n", p.gold);
						p.hp += 20;
						printf("체력을 회복 하셨습니다\n");
						printf("현재 체력 : %d\n\n\n", p.hp);
						Sleep(500);
					}
					else if (p.gold <= 10)
					{
						printf("소지 골드가 부족합니다\n");
						printf("현재 보유 골드 : %d gold\n\n\n\n", p.gold);
						Sleep(500);
					}
					b = 0;
					break;
				}

				case(3):
				{
					printf("나가기를 선택하셨습니다\n");
					b = 1;
					break;
				}

				default:
				{
					b = 0;
					printf("잘못 입력하셨습니다. \n\n");
					break;
				}
				}


			} while (b != 1);

			Sleep(1000);
			break;
		}
		case(3): // 다침 HP-
		{
			printf("지나가던 중 날카로운 물건에 긁였습니다\n");
			p.hp -= 5;
			printf("현재 HP : %d\n", p.hp);

			Sleep(1000);
			break;
		}
		case(4): // 열려 있는 집 발견 +gold
		{
			printf("문이 열려있는 집을 발견했습니다 \n");
			int b = 0;
			do
			{

				int f = 0;
				printf("1. 들어간다\n");
				printf("2. 들어가지 않는다 \n");
				printf("입력 : ");
				scanf_s(" %d", &f);
				printf("\n\n");

				switch (f)
				{
				case(1):
				{
					printf("'들어간다'를 선택하셨습니다\n");
					b = 1;
					int c = rand() % 4;
					switch (c)
					{
					case(0):
					{
						printf("당신은 음식을 발견했습니다\n");
						p.hp += 10;
						printf("음식을 먹어 체력을 회복 하셨습니다\n");
						printf("+10 HP\n");
						printf("현재 체력 : %d\n\n\n", p.hp);
						Sleep(500);
						break;
					}

					case(1):
					{
						printf("날카로운 물건에 긁였습니다\n");
						printf("아무것도 발견하지 못하였습니다\n");
						p.hp -= 5;
						printf("현재 HP : %d\n", p.hp);
						break;
					}

					case(2):
					{
						printf("어두워 확인하지 못한 바닥의 구멍에 떨어졌습니다 \n");
						printf("한층 아래로 떨어졌습니다 \n");
						printf("떨어진 충격으로 다리를 다쳤습니다 \n");
						printf("-15 HP \n");
						p.hp -= 15;
						printf("현재 HP : %d\n", p.hp);
						A -= 1;
						break;
					}
					case(3):
					{
						printf("현금을 발견했습니다 \n");
						printf("서둘러 현금을 가방에 넣습니다 \n");
						printf("+15 gold \n");
						p.hp += 15;
						printf("현재 gold : %d\n", p.gold);
						break;
					}
					}
					break;
				}

				case(2):
				{
					printf("'들어가지 않는다'를 선택하셨습니다\n");
					b = 1;
					break;
				}

				default:
				{
					b = 0;
					printf("잘못 입력하셨습니다. \n\n");
					break;
				}
				}
				Sleep(500);
				break;

			} while (b != 1);
			Sleep(1000);
			break;
		}
		case(5): // 강도
		{
			Monster mm = monster_table[3];
			printf("%s를 만났습니다.\n", mm.name);
			printf("전투를 시작합니다.\n\n");
			Sleep(700);


			do
			{
				int a = 0;
				int b = 0;
				do
				{
					printf("전투 방식을 선택해주세요 \n");
					printf("1.공격 2.방어 3.카운터\n");
					printf("입력: ");
					scanf_s("%d", &a);

					switch (a)
					{
					case(1):
						b = 1;
						printf("당신의 공격 \n\n");
						break;
					case(2):
						b = 1;
						printf("당신의 방어 \n\n");
						break;
					case(3):
						b = 1;
						printf("당신의 카운터 \n\n");
						break;
					default:
						b = 0;
						printf("잘못 입력하셨습니다. \n\n");
						break;
					}
				} while (b != 1);



				int c = rand() % 3;
				switch (c)
				{
				case(0):
					printf("%s의 공격 \n\n", mm.name);
					break;
				case(1):
					printf("%s의 방어 \n\n", mm.name);
					break;
				case(2):
					printf("%s의 카운터 \n\n", mm.name);
					break;
				}

				if (c == 0) // 강도 공격
				{
					switch (a)
					{
					case(1):
						printf("당신과 %s가 서로 공격하여 데미지를 받았습니다\n", mm.name);
						mm.hp -= p.atk;
						p.hp -= mm.atk;
						printf("당신 HP : %d \n", p.hp);
						printf("%s의 HP : %d \n", mm.name, mm.hp);
						break;
					case(2):
						printf("당신이 %s의 공격을 막아 데미지를 받지 않았습니다 \n", mm.name);
						break;
					case(3):
						printf("%s의 공격을 피한 후 카운터 공격 \n", mm.name);
						printf("당신의 공격이 치명타를 입힙니다 \n");
						mm.hp -= (p.atk * 2);
						printf("%s의 HP : %d \n\n", mm.name, mm.hp);
						break;
					}
				}
				else if (c == 1) // 강도 방어
				{
					switch (a)
					{
					case(1):
						printf("당신의 공격을 %s가 막았습니다.\n", mm.name);
						break;
					case(2):
						printf("당신과 %s이 서로 방어를 하였습니다 \n", mm.name);
						break;
					case(3):
						printf("당신이 %s의 방어를 풀며 공격했습니다 \n", mm.name);
						printf("당신의 %s에게 약한 공격을 입힙니다 \n", mm.name);
						mm.hp -= (p.atk / 2);
						printf("%s의 HP : %d \n\n", mm.name, mm.hp);
						break;
					}
				}
				else if (c == 2) // 강도의 카운터
				{
					switch (a)
					{
					case(1):
						printf("%s가 당신의 공격을 피한 후 카운터 공격 \n", mm.name);
						printf("당신은 치명상을 입힙니다 \n");
						p.hp -= (mm.atk * 2);
						printf("당신의 HP : %d \n\n", p.hp);
						break;
					case(2):
						printf("%s가 당신의 방어를 풀며 공격했습니다 \n", mm.name);
						printf("%s가 당신에게 약한 공격을 입힙니다 \n", mm.name);
						p.hp -= (mm.atk / 2);
						printf("당신 HP : %d \n\n", p.hp);
						break;
					case(3):
						printf("당신과 %s이 서로 카운터를 하였습니다 \n", mm.name);
						break;
					}
				}

				if (p.hp <= 0)
				{
					break;
				}
				else if (mm.hp <= 0)
				{
					printf("%s가 쓰러졌습니다 \n", mm.name);
					p.gold += mm.gold;
					printf("전리품으로 %d gold를 얻었습니다 \n", mm.gold);
					printf("현재의 소지금 : %d gold \n\n", p.gold);
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
	1. 과제
		1. 사이즈가 10인 int형 배열을 만들어 각 원소에 난수로 숫자를 넣어준다.
		2. 먼저 0번 부터 순서대로 들어간 값을 출력해준다.
		3. 오름차순으로 정렬하여 출력해준다.
		4. 내림차순으로 정렬하여 출력해준다.

		오름차순 : 작은 수에서 큰 수로 정렬하는 것 1, 2, 3,....
		내림차순 : 큰 수에서 작은 수로 정렬하는 것 10, 9, 8, 7....

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void IN(int arr[]); //직접 입력
void RANDOM(int arr[]); //랜덤입력
void UP(int arr[]); //올림차순
void DOWN(int arr[]); // 내림차순


int main()
{
	int arr[10];
	int a = 0;
	printf("입력 방법을 선택해 주세요\n");
	printf("1.직접입력  2.랜덤입력\n");
	printf("입력 : ");
	scanf_s("%d", &a);

	switch (a)
	{
	case 1:
	{
		printf("직접입력을 선택하셨습니다\n");
		IN(arr);
		break;
	}
	case 2:
	{
		printf("랜덤입력을 선택하셨습니다\n");
		RANDOM(arr);
		break;
	}
	default:
		printf("잘못 입력하였습니다.\n");
		printf("프로그램을 다시 실행해 주세요.\n");
		return 0;
	}

	int b = 0;
	printf("올림차순 or 내림차순을 선택해 주세요\n");
	printf("1.올림차순  2.내림차순\n");
	printf("입력 : ");
	scanf_s("%d", &b);

	switch (b)
	{
	case 1:
	{
		printf("올림차순을 선택하셨습니다\n");
		UP(arr);
		break;
	}
	case 2:
	{
		printf("내림차순을 선택하셨습니다\n");
		DOWN(arr);
		break;
	}
	default:
		printf("잘못 입력하였습니다.\n");
		printf("프로그램을 다시 실행해 주세요.\n");
		return 0;
	}


	printf("정렬 결과 : ");
	for (int i = 0; i < 9; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("%d \n", arr[9]);
	return 0;
}




void IN(int arr[]) //직접 입력
{
	printf("숫자를 입력해주세요\n");

	for (int i = 0; i < 10; i++)
	{
		printf("입력 : (%d번 남았습니다)\n", (10 - i));
		scanf_s(" %d", &arr[i]);
	}

}

void RANDOM(int arr[]) //랜덤입력
{
	srand((unsigned)time(NULL));

	for (int B = 0; B < 10; B++)
	{
		arr[B] = rand() % (101); //0~100의 난수 생성
	}
}

void UP(int arr[]) //올림차순
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

void DOWN(int arr[]) // 내림차순
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


	2. 과제
		층마다 호의 인원수를 입력받고
		각층의 총원, 해당 아파트의 총 인원을 출력하는 함수
		3층 5호 이상

#include<stdio.h>
#include<stdlib.h>
#include<time.h>




int main()
{
	int arr[3][5];

	int a = 0;
	printf("입력 방법을 선택해 주세요\n");
	printf("1.직접입력  2.랜덤입력\n");
	printf("입력 : ");
	scanf_s("%d", &a);

	switch (a)
	{
	case 1:
	{
		printf("직접입력을 선택하셨습니다\n\n");
		printf("인구를 입력해주세요\n");

		for (int i = 0; i < 3; i++)
			for (int o = 0; o < 5; o++)
			{
				printf("입력 : %d층 %d호 입니다)\n", (i+1), (o+1));
				scanf_s(" %d", &arr[i][o]);
			}
		break;
	}
	case 2:
	{
		printf("랜덤입력을 선택하셨습니다\n\n");
		srand((unsigned)time(NULL));

		for (int i = 0; i < 3; i++)
			for (int o = 0; o < 5; o++)
			{
				arr[i][o] = rand() % (8+1); //난수 생성
			}
		break;
	}
	default:
		printf("잘못 입력하였습니다.\n");
		printf("프로그램을 다시 실행해 주세요.\n");
		return 0;
	}


	for (int i = 0; i < 3; i++)
	{
		int A = 0;
		for (int o = 0; o < 3; o++)
		{
			A += arr[i][o];
		}
		printf("%d층의 총원 : %d명 입니다. \n", (i + 1), A);
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

	printf("아파트의 총원 : %d명 입니다. \n", B);

	return 0;
}



*/

//23.04.26
/*
	1. 과제: 별그리기
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
	printf("값을 입력해주세요 : ");
	scanf_s("%d", &a);

	for (int b = 1; b <= a; b++) //층
	{
		for (int c = 0; c < b; c++) //갯수
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
	printf("값을 입력해주세요 : ");
	scanf_s("%d", &a);

	for (int b = 0; b < a; b++) //줄
	{
		for (int c = 0; c < b; c++) //띄어쓰기
		{
			printf(" ");
		}
		for(int d =0; d < a-b; d++) // 별
			printf("*");
		printf("\n");
	}

	return 0;
}


2. 과제 : int형 값 num1, num2 를 받아 num1^num2 을
반환하는 함수 pow작성

#include<stdio.h>
int IN() //입력
{
	int in;
	printf("숫자를 입력해주세요 : ");
	scanf_s("%d", &in);
	return in;
}
int pow(int a, int b) //제곱 계산
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
	printf("제곱할 숫자를 입력하세요\n");
	int X1 = IN();
	printf("몇제곱(지수)을 하시겠습니까?\n");
	int X2 = IN();

	printf("%d의 %d승 = %d \n", X1, X2, pow(X1, X2));
	return 0;
}


*/

// 23.04.21
/*
	1. 과제 : 가위 바위 보 게임 업그레이드
			- 상대가 무작위로 내도록 변경하기
			- 3선 2승제

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define 가위 1
#define 바위 2
#define 보 3
//1<2<3<1

int main()
{
	srand((unsigned int)time(NULL));
	int A = 0, B = 0;//A 유저, B 상대
	int a = 0, b = 0;//a 유저, b 상대 점수
	int Q = 0; //가위바위보 승리 여부

	do
	{
		printf("가위 바위 보를 시작하겠습니다. \n");
		printf("3판 2선승제 입니다. \n");


		printf("[1: 가위 2: 바위 3. 보]\n\n"); //입력
		printf("입력 : ");
		scanf_s("%d", &A);

		if (A > 0 && A < 4);  //잘못된 입력일경우 종료
		else
		{
			printf("잘못된 값을 입력하였습니다\n");
			printf("프로그램을 다시 실행하여 주세요.\n");
			return 0;
		}

		B = (rand() % 3 + 1); //랜덤값

		switch (A)
		{
		case 가위:
			printf("당신은 가위를 냈습니다\n"); break;
		case 바위:
			printf("당신은 바위를 냈습니다\n"); break;
		case 보:
			printf("당신은 보를 냈습니다\n"); break;
		}
		switch (B)
		{
		case 가위:
			printf("상대가 가위를 냈습니다\n"); break;
		case 바위:
			printf("상대가 바위를 냈습니다\n"); break;
		case 보:
			printf("상대가 보를 냈습니다\n"); break;
		}

		if (A == B) Q = 1; //비김
		else if (B > ((A + 1) % 3)) Q = 2;
		else Q = 3;

		switch (Q)
		{
		case 1:
			printf("비겼습니다\n\n\n");
			break;
		case 2:
			printf("이겼습니다\n\n\n");
			++a;
			printf("나 : %d //상대 : %d \n\n\n", a, b);
			break;
		case 3:
			printf("졌습니다\n\n\n");
			++b;
			printf("나 : %d //상대 : %d \n\n\n", a, b);
			break;
		}
	}while (a < 2 && b < 2);

	if (a == 2) printf("2점을 먼저 얻어 승리하셨습니다!!\n\n");
	else printf("상대가 2점을 먼저 얻어 패배하셨습니다...\n\n");


	printf("**********프로그램을 종료합니다**********\n");

	return 0;
}


	2. 과제 : 묵 찌 빠 게임 만들기
	#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define 가위 1
#define 바위 2
#define 보 3
//1<2<3<1

int main()
{
	srand((unsigned int)time(NULL));
	int A = 0, B = 0; //A 유저, B 상대
	int a = 0, b = 0; //a 유저, b 상대 점수
	int Q = 0, C = 0; //Q = 가위바위보 승리 여부,  C = 묵찌빠 공격권
	int D = 0; //D = 경기횟수
	printf("묵 찌 빠 게임을 시작하겠습니다. \n");
	printf("3판 2선승제 입니다. \n");

	do
	{
		do
		{
			++D;
			printf("%d번째 게임\n\n", D);
		printf("[1: 가위 2: 바위 3. 보]\n\n"); //입력
		printf("입력 : ");
		scanf_s("%d", &A);

		if (A > 0 && A < 4);  //잘못된 입력일경우 종료
		else
		{
			printf("잘못된 값을 입력하였습니다\n");
			printf("프로그램을 다시 실행하여 주세요.\n");
			return 0;
		}

		B = (rand() % 3 + 1); //랜덤값

		switch (A)
		{
		case 가위:
			printf("당신은 가위를 냈습니다\n"); break;
		case 바위:
			printf("당신은 바위를 냈습니다\n"); break;
		case 보:
			printf("당신은 보를 냈습니다\n"); break;
		}
		switch (B)
		{
		case 가위:
			printf("상대가 가위를 냈습니다\n"); break;
		case 바위:
			printf("상대가 바위를 냈습니다\n"); break;
		case 보:
			printf("상대가 보를 냈습니다\n"); break;
		}

		if (A == B) Q = 1; //비김
		else if (B > ((A + 1) % 3)) Q = 2;
		else Q = 3;

		switch (Q)
		{
		case 1:
			printf("비겼습니다\n\n\n");
			break;
		case 2:
			printf("이겼습니다\n\n\n");
			C = 1;
			break;
		case 3:
			printf("졌습니다\n\n\n");
			C = 2;
			break;
		}
		} while (C==1 && C==2);


		//묵찌빠 시작

		do
		{
			Q = 0;
			switch (C)
			{
			case 1:
				printf("\n당신의 공격권\n\n\n");
				break;
			case 2:
				printf("\n상대의 공격권\n\n\n");
				break;
			}
			printf("\n[1: 가위 2: 바위 3. 보]\n\n");
			printf("입력 : ");
			scanf_s("%d", &A);

			if (A > 0 && A < 4);  //잘못된 입력일경우 종료
			else
			{
				printf("잘못된 값을 입력하였습니다\n");
				printf("프로그램을 다시 실행하여 주세요.\n");
				return 0;
			}
			B = (rand() % 3 + 1);

			switch (A)
			{
			case 가위:
				printf("당신은 가위를 냈습니다\n"); break;
			case 바위:
				printf("당신은 바위를 냈습니다\n"); break;
			case 보:
				printf("당신은 보를 냈습니다\n"); break;
			}
			switch (B)
			{
			case 가위:
				printf("상대가 가위를 냈습니다\n"); break;
			case 바위:
				printf("상대가 바위를 냈습니다\n"); break;
			case 보:
				printf("상대가 보를 냈습니다\n"); break;
			}

			if (A == B) Q = 1; //비김
			else if (B > ((A + 1) % 3)) Q = 2;
			else Q = 3;


			switch (C)
			{
			case 1:
				switch (Q)
				{
				case 1: //같을때
					printf("이겼습니다!\n\n");
					C = 0;
					++a;
					printf("나 : %d / 상대 : %d \n\n\n\n", a, b);
					break;
				case 2: //이길때
					C = 1;
					break;
				case 3: //질때
					C = 2;
					break;
				}
				break;
			case 2:
				switch (Q)
				{
				case 1: //같을때
					printf("졌습니다....\n\n");
					C = 0;
					++b;
					printf("나 : %d / 상대 : %d \n\n\n\n", a, b);
					break;
				case 2: //이길때
					C = 2;
					break;
				case 3: //질때
					C = 1;
					break;
				}
			}


		} while (C==1||C==2);

	}while (a < 2 && b < 2);

	if (a == 2) printf("2점을 먼저 얻어 승리하셨습니다!!\n\n");
	else printf("상대가 2점을 먼저 얻어 패배하셨습니다...\n\n");


	printf("**********프로그램을 종료합니다**********\n");

	return 0;
}
*/

// 23.04.20
/*
	1. 과제 : %c를 띄어쓰지 않을때 그냥 넘어가는 이유 조사하기
		scanf로 입력받을 시에 직접적으로 사용되지 않는 문자들(공백, 줄바꿈 등)은 버퍼에 그대로 남아있게 되는데,
		%c가 그것들을 사용하려고 해서 그렇습니다. 앞에 공백을 하나 넣어주면, 이러한 문자들을 버리고 입력을 받는 것으로 알고 있습니다.


	2. 과제 : 띄어쓰기를 제외한 다른 해결방법도 찾아보기
		getchar(); 사용하기 : getchar()은 scanf와 비슷한 문자열을 입력받는 함수로 입니다.
		첫번째 scanf사용후 getchar(void)를 사용하면  입력 버퍼, 즉 입력받는 공간 안에 있던 이상한 것들이 초기화 되기때문에
		scanf를 정상적으로 사용할 수 있게됩니다



	3. 과제 : bmi 계산기 업그레이드
		- 나온 bmi 수치에 따라 저체중 , 정상 , 과체중, 비만 출력하기
		#include<stdio.h>

	int main()
		{
			float A = 0, B = 0, C = 0;

			printf("신장을 표기해주세요 : ");
			scanf_s("%f", &A);

			printf("체중을 표기해주세요 : ");
			scanf_s("%f", &B);

			C = B / ((A * A)/10000);
			printf("신체질량지수(BMI) : %.2f",C);

			if (C <= 20)
				{
					printf(" BMI측정 결과 저체중입니다\n\n");
				}

			else if (C <= 24)
				{
					printf(" BMI측정 결과 정상입니다\n\n");
				}

			else if (C <= 30)
				{
					printf(" BMI측정 결과 과체중입니다\n\n");
				}

			else if (C >= 30)
				{
					printf(" BMI측정 결과 비만입니다\n\n");
				}


			return 0;
		}
	4. 과제 : 가위 바위 보 게임 만들기
		- 상대방은 가위로 고정
		- 플레이어가 내는 경우에 따라 승, 패, 무승부 출력

		#include<stdio.h>

#define 가위 1
#define 바위 2
#define 보 3

int main()
{
	printf("가위 바위 보 게임을 실행하겠습니다. \n");
	printf("[1: 가위 2: 바위 3. 보]\n");
	printf("입력 : ");
	int A;
	scanf_s("%d", &A);

	switch (A)
	{
	case 가위:
		printf("상대와 비겼습니다.\n");
		break;

	case 바위:
		printf("상대에게 이겼습니다.\n");
		break;

	case 보:
		printf("상대에게 졌습니다.\n");
		break;

		return 0;
	}
}



*/

// 23.04.19
/*
	1. 과제 : 비트 플래그가 무엇인지 조사하기.
	2. 과제 :  논리 연산자 문제
	3. 과제 : 환율 계산기 만들기
	4. 과제 : bmi 계산기 만들기
*/

// 23.04.13
/*
	1과제 : escape sequence, format specifier 조사

	2. 과제 : printf로 자기 소개 작성

	3.overflow와 underflow 조사

	4. 어떤 표현법인지 찾기 (변수 표기법)

	5. 과제 : ASCI코드 조사하기
*/



