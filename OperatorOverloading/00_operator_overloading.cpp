// 00_operator_overloading.cpp

/*
   operator overloding
   - ������ �����ϴ� �⺻ �����ڸ� ����ڰ� ���� �����Ͽ� ����ϴ� ��
   - ���� ������ �Ұ����ϴ� Ÿ�԰��� ������ ó���� �� �ִ�.
   - (.), (.*), (::), (?:), (#), (##)�� ������ �����ڴ� �����ε��� �����ϴ�.
   => ���� ��ũ : https://docs.microsoft.com/ko-kr/cpp/cpp/operator-overloading?view=msvc-170

   �⺻ ���� ���

   ��ȯ�� operator������(�����ڰ� ���� �ǿ�����)
*/

class Number
{
public:
    Number(int num)
        : num(num)
    {

    }

    void SetNum(int num)
    {
        this->num = num;
    }

    int GetNum()
    {
        return num;
    }

private:
    int num;
};

int main()
{
    Number a(10), b(20);

    {
        int result = a.GetNum() + b.GetNum();
        a.SetNum(result);
    }

    // �����ε��� ����� ����
    //a = a + b;
    //a += b;

    return 0;
}