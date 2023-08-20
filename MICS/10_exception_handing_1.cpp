// 10_exception_handing_1.cpp

/*
   ����ó��
   try, catch, throw
*/
#include<iostream>
using namespace std;

int main()
{
	double x;
	cin >> x;

	// try : ���ܰ� �߻��� �� �ִ� ������ ǥ���Ѵ�
	try
	{
		// throw : ���ܸ� ������ try ������ �����
		// �Ʒ��� catch���� ���ܸ� �޾� ó�����ش�
		// ���� catch���� ���ܸ� ���� ���Ұ�� ������ �߻��Ѵ�
		if (x < 0.0) throw - 1.0;

		if (x >= 100) throw "100�̻��� ���� �Էµ�";

		cout << sqrt(x) << endl;
	}
	// catch : throw�� ���ܸ� �޾� ó���Ѵ�
	// throw�� Ÿ�԰� ��ġ�ؾ� chtch�� �� �ִ�
	catch (double x)
	{
		cerr << x << endl;
	}
	// catch�� ������ �ۼ��Ͽ� �پ��� Ÿ������ throw�ϰ� catch�� �� �ִ�
	// ��� �����͸� ���� ���·� �޴°�쿡�� const�� �� ������� �Ѵ�
	catch (const char* error_message)
	{
		cerr << error_message << endl;
		clog;
	}

	return 0;
}