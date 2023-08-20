// 04_function_template_specialization.cpp

#include<iostream>
using namespace std;


template<typename T>
T GetMax(T x, T y)
{
	return (x > y) ? x : y;
}

template<>
char GetMax(char x, char y)
{
	cout << "경고 : 문자끼리 비교중임" << endl;
	return (x > y) ? x : y;
}

template <class T>
class Storage
{
public:
	Storage(T value)
		:value(value)
	{}

	void Print()
	{
		cout << value << endl;
	}

private:
	T value;
};

template<>
void Storage<double>::Print()
{
	cout << scientific << value << endl;
}

int main()
{
	cout << GetMax<int>(1u, 2) << endl;
	cout << GetMax<float>(2.0f, 4.0f) << endl;
	cout << GetMax<char>('a', 'b') << endl << endl;

	Storage<int> s1(10);
	s1.Print();

	Storage<double> s2(10);
	s2.Print();

	return 0;
}










