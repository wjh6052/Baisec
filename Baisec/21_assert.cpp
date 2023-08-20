// 21_assert.cpp

#include<iostream>
#include<cassert>

int main()
{
	int x = 0;
	// x �Է��ڵ�
	std::cout << x << std::endl;

	/*
		assert
			- ���ǽ��� true��� ������� �ƴ϶�� ���� �߻�
			- Ư�� ������ ���������� Ȯ�� ����
			- debug ��忡���� Ȯ��, release ��忡���� ����
			- �Ϲ� assert�� ������ Ÿ���� �ƴ� �� Ÿ�Ӷ� Ȯ���Ѵ�. 
				-> ������ �غ��� Ȯ���� ����
	*/
	//assert(false);
	//assert(x != 0);

	// ���ڿ� ����� �׻� ���� �κ��� �̿��� ���ڿ��� ������ �� ����
	assert(x != 0 && "x is 0");

	
	// ������ Ÿ�Ӷ� Ȯ���� �ϴ� assert
	//static_assert(false);

	// ������ Ÿ�Ӷ� Ȯ�� ������ ���� ���ǽĿ��� ����� ����
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