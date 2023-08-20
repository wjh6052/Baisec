// 01_stl_and_container.cpp

/*
	STL
	- 컨테이너(container), 반복자(iterator), 알고리즘(algorithm) 등등으로 이루어진 라이브러리
	- 템플릿을 사용하여 어떠한 타입의 데이터로 위의 라이브러리를 사용할 수 있도록 일반화 하였다.
		-> 자료형을 일반화 하여 코드의 수정없이 동일한 작업을 수행할 수 있게 하였다

	컨테이너(container)
	- 임의 타입의 데이터를 보관할 수 있다

	반복자(iterator)
	- 컨테이너에 보관된 원소에 접근할 때 사용한다

	알고리즘(algorithm)
	- 반복자들을 가지고 일련의 작업을 수행한다

	// 과제 : std, stl 조사
*/

/*
	container - 컨테이너
	- 도일한 자료형의 여러 객체를 저장하는 집합 혹은 저장소를 의미한다
	- 템플릿을 사용해 저장하는 데이터의 자료형에 무관하게 무엇이든 담을 수 있도록 설계되어있다
	- sequence, associative, adapter 컨테이너 종류가 있다.
*/

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
using namespace std;

void Sequence_Container();
void Associative_Container();
void Container_Adapter();

int main()
{
	Sequence_Container();
	Associative_Container();
	Container_Adapter();


	return 0;
}

/*
	sequence container
	- 배열처럼 데이터를 선형으로 저장하는 컨테이너
	- 특별한 제약이나 규칙없이 원소를 보관한다
*/

void Sequence_Container()
{

	{
		vector<int> vec; //template이며 template 클래스로 만들어진 객체(배열처럼 연속적인 메모리를 가지고 있음)
		for (int i = 0; i < 10; i++)
			vec.push_back(i);

		for (const auto& ele : vec)
			cout << ele << ' ';
		cout << endl;
	}

	{
		deque<int> deq;
		for (int i = 0; i < 10; i++)
		{
			deq.push_back(i);
			deq.push_front(i);
		}

		for (const auto& ele : deq)
			cout << ele << ' ';
		cout << endl;
	}

	{
		list<int> list;

		for (int i = 0; i < 10; i++)
			list.push_back(i);

		for (const auto& ele : list)
			cout << ele << ' ';
		cout << endl;
	}


}

/*
	associative container
	- 데이터를 일정한 규칙에 따라 저장하고 관리하는 컨테이너
	- 저장된 요소의 위치를 지정할 수 없고 RB-Tree나 해시 테이블을 이용하여 구현이 되어있다
	- 원소를 삽입할 경우 자동으로 정렬해주기때문에 탐색이 빠르다
	- 키(key) - 값(value) 구조를 가진다
	=> 특정한 키값을 넣으면 대응하는 값을 돌려준다
*/

void Associative_Container()
{


}

/*
	adapter container
	- 기존의 컨테이너의 인터페이스를 제한하여 만든 기능이 제한되거나 변형된 컨테이너
	- 각각의 기초가 되는 클래스의 인터페이스를 제한하여 특정 형태의 동작만을 수행하도록 한다
	- 반복자를 지원하지 않아 stl 알고리즘 사용이 안된다
*/

void Container_Adapter()
{


}