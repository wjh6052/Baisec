// 08_string.cpp

#include<iostream>
#include<string>

using namespace std;

int main()
{
	// �����ͷ� ���ڿ� ����� �ްԵǸ� ���ڿ� ����� ���� �ּҸ� �ޱ� ������
	// �����͸� ������ �� ���� ���·� �޾ƾ߸� �Ѵ�.
	const char* test = "Hello";

	// ���� �����͸� �����ϴ� �纻 �����͸� ����� ������ const�� �߰�����
	// �ʾƵ� ����
	char my_str[] = "Hello, C++";

	// string : ���ڿ��� �ٷ�� ���� ���ִ� ��ü
	string str = "Hello, C++!";


	// ���̹�ȯ
	str.size();
	str.length();

	// ����ó�� �ʱ�ȭ ����
	string a("Hello, ");
	string b("C++!");

	// + ���� ����
	string c = a + b;

	c += ", good!!";
	cout << c << endl;

	// �迭ó�� ��� ����
	c[0];



	return 0;
}