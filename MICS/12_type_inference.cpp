// 12_type_inference.cpp

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
   Type inference : �ڷ��� �߷�
   - auto and decltype
   // http://thbecker.net/articles/auto_and_decltype/section_01.html -> �ڼ��� ������ ���⿡
*/

void ex1()
{
    vector<int> vec;
    // �ʹ���
    for (std::vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter;

    //auto�� �߷��ؼ� ��� ����
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter;

    for (auto iter : vec)
        cout << iter;
}

void ex2()
{
    //Ÿ���� �ڵ����� �߷�����
    int x = int();
    auto auto_x = x;

    // 
    /*
       Ÿ���� �߷��� �� �ٸ��ִ� �ɼ��� ������
       -> Ű���尡 ���ŵ� ������ Ÿ�Ը� �޴´�.
    */
    const int& crx = x;
    auto auto_crx1 = crx;
    const auto& auto_crx2 = crx;
}


//templat type deduction(inference) -> auto�� ������ -> �ڷ����� ������
template<typename T>
void func_ex3(T arg) {}

void ex3()
{
    const int& crx = 123;
    func_ex3(crx);
}

void ex4()
{
    //const���� �ڷ����� auto&�� �����Ë���
    //const auto&�� ��
    const int c = 10;
    auto& rc = c;
}

void ex5()
{
    int i = 77;
    auto&& r1_1 = i; // int&& --> int&�� ����
    auto&& r1_2 = 77;// int&&
}

void ex6()
{
    int x = 77;
    const int* p1 = &x;
    auto p2 = p1; // const int*
}

struct S
{
    S() : x(77) {}
    int x;
};

void ex7()
{
    int x = 77;
    const int cx = 77;
    const int& crx = x;
    const S* p = new S();

    auto a = x;
    auto b = cx;
    auto c = crx;
    auto d = p;
    auto e = p->x;

    //decltype -> declaration type -> ó�� ����Ȱ� �ڷ����� �����´� 
    typedef decltype(x) x_type;
    typedef decltype(cx) cx_type;
    typedef decltype(crx) crx_type;
    typedef decltype(p->x) s_x_type;

    // () -> add reference to l-value
    typedef decltype((x)) x_with_parens_type;
    typedef decltype((cx)) cx_with_parens_type;
    typedef decltype((crx)) crx_with_parens_type;
    typedef decltype((p->x)) s_x_with_parens_type;

}

const S foo() { return S(); }
const int& foobar() { return 123; }

void ex8()
{
    auto a = foo();
    // decltype()�ȿ� �ִ� �͵��� ���� x, �ڷ����� �����ϴ� ��
    typedef decltype(foo()) foo_type;

    auto b = foobar();
    typedef decltype(foobar()) foobar_type;

    // �̷������ε� ��밡��
    decltype(foobar()) c = foobar();

    std::vector<int> vec{ 1,2,3 };

    auto iter = vec.begin();
    decltype(vec.begin()) iter2 = vec.begin();

    // [] ��ȯ���� &���¶� �ٸ�
    auto first_element = vec[0]; // int
    decltype(vec[1]) second_element = vec[1]; // int&

}

void ex9()
{
    int x = 0;
    int y = 0;
    const int cx = 66;
    const int cy = 77;
    double d1 = 3.14;
    double d2 = 1.57;

    typedef decltype(x* y) prod_xy_type;
    auto a = x * y;


    // int�� -> �ܵ����� �������� cosnt int�� ������ ��� ����� ���ο� ���� ���� ���̱� ������ ������ r-value��
    typedef decltype(cx* cy) prod_cxcy_type;  // return is(pure-r-value)
    auto b = cx * cy;

    // �ΰ��� ������� ���� �ڷ����̰� l-value���  & ���·� ����
    typedef decltype(false ? d1 : d2) cond_type; // result is lvalue
    auto c = false ? d1 : d2;

    // �ΰ��� ������� �ٸ� �ڷ����� ���� ū �ڷ������� ����ȯ �Ǿ� ���� -> &�� �����
    typedef decltype(true ? x : d2) cond_type_mixed; // promotion of x to double
    auto d = true ? x : d2;

}

//���� ���� ��� ���۷��� ���°� �����µ� 
//x�� y�� ���������� ���� �Ҹ���
template <typename T, typename S>
auto fpmin_wrong(T x, S y) -> decltype(x < y ? x : y)
{
    return x < y ? x : y;
}

//�̷������� ���۷����� ���� ������ �ؾ��� 
template <typename T, typename S>
auto fpmin(T x, S y) -> typename std::remove_reference<decltype(x < y ? x : y)>::type
{
   return x < y ? x : y;
}

void ex10()
{
    int i = 33;
    double d = 1.1;
    int& j = i;

    typedef decltype(fpmin_wrong(d, d)) fpmin_wrong_type1;
    typedef decltype(fpmin_wrong(i, d)) fpmin_wrong_type2;
    typedef decltype(fpmin_wrong(j, d)) fpmin_wrong_type3;

    typedef decltype(fpmin(d, d)) fpmin_wrong_type1;
    typedef decltype(fpmin(i, d)) fpmin_wrong_type2;
    typedef decltype(fpmin(j, d)) fpmin_wrong_type3;
}

void ex11()
{
    std::vector<int> vec; //empty
    typedef decltype(vec[0]) integer; // ���� ������ �ƴ϶� ���� �߷��ϴ°Ŷ� ������
}

template <typename T>
class SomeFunctor
{
public:
    typedef T result_type;

    SomeFunctor() {}
    result_type operator()() { return result_type(); }
};

void ex12()
{
    SomeFunctor<int> func;

    typedef decltype(func)::result_type integer;
}

void ex13()
{
    // ��ȯ�� ()���̿����� �ٸ� �� ���� 
    auto lambda = []() {return 77; };
    decltype(lambda) lambda2(lambda);   // int
    decltype((lambda)) lambda3(lambda); // int&

    cout << "Lambda functions" << endl;
    cout << &lambda << " " << &lambda2 << endl;
    cout << &lambda << " " << &lambda3 << endl;

}

void ex14()
{
    //generic lambda
    //���ٿ����� �Ű����� auto�� �� ���� 
    auto lambda = [](auto x, auto y)
    {
        return x + y;
    };

    cout << lambda(1.1, 2) << " " << lambda(3, 4) << " " << lambda(4.5, 2.2f) << endl;
}

int main()
{
    //ex13();
    ex14();
    return 0;
}