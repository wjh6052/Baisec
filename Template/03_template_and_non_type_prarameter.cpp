// 03_template_and_non_type_prarameter.cpp

/*
   non-type parameter
   - �ڷ����� �ƴ� ���ø� �Ű�����
   - �ڷ����� �ƴ� ������� �־��ش�.
*/

#include<iostream>
#include<array>
using namespace std;



template <typename T, unsigned int SIZE>
class MyArray
{
public:
	MyArray() = default;
	~MyArray() = default;

private:
	T arr1[10];
	T arr2[SIZE]; // ���ø� ��üȭ ����(������ Ÿ��)�� SIZE�� ��ũ�� ��� ó�� �����ϸ鼭 �ۼ��̵�
};

#define SIZE 10

int main()
{
	MyArray<int, 10> arr1;
	MyArray<double, 10> arr2;



	return 0;
}