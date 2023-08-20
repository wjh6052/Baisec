// 04_relational_operator.cpp

#include<iostream>
#include<vector>   // ���� �迭
#include<algorithm> // ���� �˰����� ���ǵǾ� ����
using namespace std;

class Won
{
public:
    Won(int value = 0) : value(value) {}

    auto Getvalue()const { return value; }
    void SetValue(const int& value) { this->value = value; }

    bool operator == (const Won& rhs)const
    {
        // ���� ���� ���� ���־�� �Ѵ�.
        return value == rhs.value && value1 == rhs.value1;
    }

    bool operator != (const Won& rhs) const
    {
        //return value != rhs.value || value1 != rhs.value1;
        return !(*this == rhs); // ���� ������ == �����ڸ� ������ �����ϰ� ���� �� �ִ�.

    }
    friend ostream& operator << (ostream& out, const Won& won)
    {
        out << won.value;
        return out;
    }

    bool operator < (const Won& rhs) const
    {
        return value < rhs.value;
    }

private:
    int value;
    int value1;

};

bool test(const Won& lhs, const Won& rhs)
{
    return lhs.Getvalue() < rhs.Getvalue();
}

int main()
{
    Won w1(10), w2{ 20 };

    if (w1 == w2)
    {

    }

    vector<Won> wons(20, 0);

    int i = 0;
    for (auto& won : wons)
    {
        won.SetValue(i);
        i++;
    }
  
    for (auto& won : wons)
        cout << won << " ";
    cout << endl;

    random_shuffle(wons.begin(), wons.end());

    for (auto& won : wons)
        cout << won << " ";
    cout << endl;

    // ����, < �����ڰ� ���ǵǾ� �־����
    sort(wons.begin(), wons.end());

    for (auto& won : wons)
        cout << won << " ";
    cout << endl;

    // ����ڰ� ������ �Լ��� ����� ����
    sort(wons.begin(), wons.end(), test);

    for (auto& won : wons)
        cout << won << " ";
    cout << endl;

    // ���� : ���ٽ� ����
    // ���ٽ� ��� 
    sort(wons.begin(), wons.end(),
        [](const Won& lhs, const Won& rhs)
        {
            return lhs.Getvalue() < rhs.Getvalue();
        });

    for (const auto& won : wons)
        cout << won << " ";
    cout << endl;

    return 0;
}