// 21_assert.cpp

#include<iostream>
#include<cassert>

int main()
{
	int x = 0;
	// x 입력코드
	std::cout << x << std::endl;

	/*
		assert
			- 조건식이 true라면 계속진행 아니라면 에러 발생
			- 특정 조건의 성공유무를 확인 가능
			- debug 모드에서만 확인, release 모드에서는 무시
			- 일반 assert는 컴파일 타임이 아닌 런 타임때 확인한다. 
				-> 실행을 해봐야 확인이 가능
	*/
	//assert(false);
	//assert(x != 0);

	// 문자열 상수는 항사 참인 부분을 이용해 문자열을 엮어줄 수 있음
	assert(x != 0 && "x is 0");

	
	// 컴파일 타임때 확인을 하는 assert
	//static_assert(false);

	// 컴파일 타임때 확인 가능한 값만 조건식에서 사용이 가능
	bool is_b = true;
	const bool is_cb = is_b;
	//static_assert(is_cb);

	constexpr int z = 30;
	constexpr int w = 20;

	static_assert(z > w, "w is bigger than z");

	return 0;
}

template<typename T>
void Test(T val)
{
	static_assert(typeid(T) != typeid(int), "T is int");
}