// 04_weak_ptr.cpp


/*
   strong reference vs weak reference
    - strong reference : �޸� ������ ������ ��ġ�� ����, shared_ptr�� �����͸� ������ �� �����Ѵ�.
    - weak reference   : �޸� ������ ������ ���� �ʴ� ����, weak_ptr�� �����͸� ������ �� �����Ѵ�.

   weak_ptr
      - �ٸ� �� ����Ʈ �����Ϳ� �޸� �ܵ����� ������� ���ϴ� ����Ʈ ������
      - shared_ptr�� ��ȯ ������ ������ �ذ��ϱ����� ����Ѵ�.
*/

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Person
{
public:
    Person(const string& name) : name(name)
    {
        cout << name << " created" << endl;
    }
    ~Person()
    {
        cout << name << " destroyed" << endl;
    }

    const string& GetName() const { return name; }

    friend bool PartnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
    {
        if (!p1 == true || !p2 == true)
            return false;

        p1->partner = p2;
        p2->partner = p1;

        cout << p1->name << " is partnered with " << p2->name << endl;

        return true;

    }

private:
    std::string name;

    // �����Ҵ� �� ��ü�� ���θ� shared_ptr ���·� ����Ű�� ��ȯ ������ ������ �߻��� �� �ִ�
    //std::shared_ptr<Person> partner;

    // weak_ptr ���·� �����Ͽ� �����ذ� ����
    // -> ������ �ޱ�� ������ �޸������� ������ ���� �ʴ´�
    std::weak_ptr<Person> partner;
};

class Test : public Person
{
public:
    Test(const std::string& name)
        : Person(name)
    {}
};

int main()
{
    /*
        circular dependency issuses : ��ȯ ������ ����

        ���ΰ� ���θ� �����ϴ� ��Ȳ���� ī������ ���ο��� �����־�,
        ���� �������� ��ٸ��� �ֱ� ������ ī������ ���� �ʰ� ����ϰ� ����(�޸𸮰� ������ ���� �ʰ� �ӹ�)
    */

    // ��ȯ ���� ����
    {
        // �Ҵ� Luck ��ü�� ����Ʈ ������ luck�� ����, ���� ���� 0 -> 1
        auto lucy = std::make_shared<Person>("Lucy");

        // �Ҵ� Ricky ��ü�� ����Ʈ ������ ricky�� ����, ���� ���� 0 -> 1
        auto ricky = std::make_shared<Person>("Ricky");

        // ���� �޸� Luck���� Ricky�� shared_ptr ���·� ���� ����
        // ���� �޸� Ricky���� Luck�� shared_ptr ���·� ���� ����
        // -> ������ ���� ���� ī��Ʈ 1 -> 2 ����
        PartnerUp(lucy, ricky);
    }
    /* ����Ʈ ������ lucy, ricky �Ҹ� -> ������ ī��Ʈ ���� 2 -> 1

        ������ ���� �Ҵ�� ��ü Lucy, Ricky�� ��� ������ ���θ� shared_ptr ���·� ������ ����

        1. Lucy�� �Ҹ��ϱ� ���� Ricky�� ���� ����Ʈ �����Ͱ� �Ҹ��ؾ���.
        2. Ricky�� ���� ����Ʈ �����Ͱ� �Ҹ�Ǳ� ���ؼ��� Ricky�� �Ҹ��ؾ���.
        3. Ricky�� �Ҹ��ϱ� ���� Lucy�� ���� ����Ʈ �����Ͱ� �Ҹ��ؾ���.
        4. Lucy�� ���� ����Ʈ �����Ͱ� �Ҹ�Ǳ� ���ؼ��� Ricky�� �Ҹ��ؾ���.
        -> 1. ���� �ݺ�

        ���ΰ� �������� ������ �ִ��ؼ� ��ȯ ������ ������� �θ���.
        -> ���θ� ������ �� weak_ptr���·� �����Ͽ� ���� �ذ� ����
     */

     // weak_ptr ����
    {
        auto test = std::make_shared<Person>("Test");
        std::weak_ptr<Person> weak = test;

        cout << endl << "------------�׽�Ʈ��------------" << endl;

        // �Ѵ� ���� ǥ��
        //test.reset();
        //test = nullptr;

        // expired() : weak_ptr�� ������ �������� �Ҹ� ���� Ȯ��, �Ҹ�� ture ��ȯ
        if (weak.expired() != true)
            cout << "��ȿ��" << endl;
        else
            cout << "��ȿ���� ����" << endl;

        cout << "------------�׽�Ʈ��------------" << endl;


        // weak_ptr ���·δ� �ٷ� ������� ���ϰ� shared_ptr�� �ٲپ ����ؾ��Ѵ�.
        // -> �ֳ��ϸ� ��Ƽ ������ ȯ�濡�� weak_ptr�� ����ؾ� �� �� ���� shared_ptr�� ���� �����ɼ����ֱ� ������ 
        // weak_ptr�� ������ �����Ͱ� �Ҹ��ϴ°��� �������� ������� �ּ� 1�� ���� ���� Ƚ���� Ȯ���ϱ� �����̴�.

        //weak-> // error
        weak.lock()->GetName(); // ok //lock() : ���� ����(weak_ptr)�� ���� ����(shared_ptr) ���·� �ٲپ��ش�.
    }

    // �߰����� ����Ʈ ������ ���� + ������
    {
        auto test1 = std::make_shared<Person>("Test1");

        auto test2 = std::make_shared<Person>("Test2");

        //1. ����Ʈ ������ ���� ���� ����
        test1.swap(test2);

        //2. �ش� ����Ʈ �������� dull ������ ����, �ش� ����Ʈ �������� ������ �����ش�.
        //  -> �ش� �����͸� �����ϴ� ��� ����Ʈ �����Ϳ��� �������ִ°� x
        test1.reset();

        //3. ����Ʈ �������� ĳ���� 


        //3-1. dull �������� ĳ����.

        // ��ĳ������ �Ͻ��� ����ȯ ����
        Person* test3 = new Test("Test3");

        // �ٿ�ĳ������ �Ͻ��� ����ȯ x, ����� ����ȯ�� ���־�� �Ѵ�.
        //Test* test4 = test3; //error
        Test* test4 = static_cast<Test*>(test3); //static cast�� �����.


        //3-2 ����Ʈ �������� ĳ����

        // ����Ʈ �����͵� ��ĳ���� �Ͻ��� ����ȯ ����
        std::shared_ptr<Person> parent = std::make_shared<Test>("Test");

        // ����Ʈ �����͵� �ٿ�ĳ������ �Ͻ��� ����ȯ x, ����� ����ȯ�� ���־�� �Ѵ�.
        //std::shared_ptr<Test> child = parent; // error
        std::shared_ptr<Test> child = std::static_pointer_cast<Test>(parent); // ����Ʈ �����ͳ����� ����� ����ȯ�� static_pointer_cast�� ����Ѵ�.

        //4. ����Ʈ �������� dull ������ ��ȿ ���� Ȯ�ι�

        cout << endl << "------------�׽�Ʈ��------------" << endl;


        auto test5 = std::make_shared<Test>("Test5");
        auto test6 = test5;

        // �Ѵ� ���� ǥ��
        //test5.reset();
        //test5 = nullptr;

        cout << test5 << endl;
        cout << test5.get() << endl;

        if (test5 != nullptr)
            cout << "��ȿ��" << endl;
        else
            cout << "��ȿ���� ����" << endl;

        if (!test5 == false)
            cout << "��ȿ��" << endl;
        else
            cout << "��ȿ���� ����" << endl;

        cout << "------------�׽�Ʈ��------------" << endl;
    }

    return 0;
}

