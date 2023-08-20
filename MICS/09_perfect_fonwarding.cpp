// 09_perfect_fonwarding.cpp

#include <iostream>
#include <vector>

class MyClass {};

void func(MyClass& c) { std::cout << "L-ref" << std::endl; }
void func(const MyClass& c) { std::cout << "const L-ref" << std::endl; }
void func(MyClass&& c) { std::cout << "R-ref" << std::endl; }

/*
	1. ���� Ȯ��

	�Ʒ��� ���� �ڵ带 �ۼ��Ѵٸ� t��� �Ű������� ������ ������ Ÿ���� &�� &&�� ���� T��� �ڷ������� �߷��ϰԵȴ�.
	-> T, T&, T&& ������ Ÿ���� ������ &�� ������ T�� �ν��ع���

	�׷��� ������ ���� Ÿ���� ���� �޴� T t�� ���� ī���ؿ��Եǰ�  L-value Ÿ���� �������� �� �ۿ� ����
	-> �� ������ �ذ��Ͽ� �Ϻ��ϰ� �����ϰ� ���� -> perfect forwarding
*/

//template <typename T>
//void func_wrapper(T t) {
//	func(t);
//}



/*
	2. T -> T&�� �ٲ۴ٸ�?

	l-value�� ���� �� �ֱ� ������ func_wrapper(MyClass()); ���� ������ �߻��Ѵ�
	�������� �ޱ����� cosnt T& t Ÿ������ �����ε� �Ͽ����� �ᱹ ���ڸ� �ޱ����ؼ���
	�̸��� �ִ� �Ű����� ������ �ޱ� ������ l-value�� �߷��ع����ٴ� ������ �߻��ϰ�
	�����ε��� ����� �Ѵٴ� ���ŷο��� �����.
*/
//template <typename T>
//void func_wrapper(T& t) {
//	func(t);
//}

//template <typename T>
//void func_wrapper(const T& t) {
//	func(t);
//}

/*
   3. T -> T&&�� �ٲ۴ٸ�?

   �Ϲ� �Լ������� ������ Ÿ�Կ� ���ؼ� &&�� �޴´ٴ� ���� r-value�� �޴� �ٴ� �ǹ̸� ��������
   ������ ���ø� Ÿ���� T&& ���·� �޴´ٴ� ���� l-value�� r-value�� ���� ���� �� �ִٴ� ���� �ǹ��Ѵ�.
   -> �̰��� universal reference��� �θ���.

   ������ �̸��� �ִ� �Ű������� �ޱ� ������ Ÿ�� ��ü�� l-value�� �ν��ϰԵȴ�.
   -> �̴� forward<T>()�� ����Ͽ� �ذᰡ��


   universal reference�� ���۷��� ��ħ ��Ģ�� ���� T�� Ÿ���� �߷��Ѵ�.
   -> &�� 1, &&�� 0���� �ΰ� OR������ �Ѵٰ� �����ϸ�ȴ�.

   typedef int& T1;
   T1& r1;	T1, &	->	int&, &	->	int&

   typedef int& T1;
   T1& r1;      T1&      -> int&, &      -> int&
   T1&& r2;   T1&&   -> int&, &&      -> int&&

   typedef int&& T2;
   T2& r3;   T2&      -> int&&, &      -> int&
   T2&& r4;  T2&&      -> int&&, &&   -> int&&
*/

template <typename T>
void func_wrapper(T&& t) {
	//func(t);

	func(std::forward<T>(t));
}

int main() {
	MyClass c;
	const MyClass cc;

	std::cout << "func" << std::endl;
	func(c);
	func(cc);
	func(MyClass());
	std::cout << std::endl;

	std::cout << "func_wrapper" << std::endl;
	func_wrapper(c);
	func_wrapper(cc);
	func_wrapper(MyClass());
	std::cout << std::endl;

}