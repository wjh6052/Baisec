// 10_derived_class_object_and_base_class.cpp

#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:
    Animal(string name) : name(name) {}

    //1.
    void Speak() const { cout << "??" << endl; }

    //2.
    //virtual void Speak() const { cout << "??" << endl; }

protected:
    string name;
};

class Cat : public Animal
{
public:
    Cat(string name) : Animal(name) {}
    void Speak() const { cout << "Meow" << endl; }
};

class Dog : public Animal
{
public:
    Dog(string name) : Animal(name) {}
    void Speak()const { cout << "Woof" << endl; }
};

int main()
{

    Cat cats[]{ Cat("cat1"),Cat("cat2"),Cat("cat3"),Cat("cat4"),Cat("cat5") };
    Dog dogs[]{ Dog("dog1"),Dog("dog2"),Dog("dog3"),Dog("dog4"),Dog("dog5") };


    // cat��, dogs�� Speack�� ������ ����ϰ� �ִ�.
    // ������ �ϴ°� �����ϴ�. -> ��ĳ�����ؼ� ��� �غ��� 
    for (const auto& cat : cats)
        cat.Speak();

    for (const auto& dog : dogs)
        dog.Speak();

    // Animal Ŭ������ ��ĳ����
    Animal* animals[]
    {
       &cats[0],
       &cats[1],
       &cats[2],
       &cats[3],
       &cats[4],
       &dogs[0],
       &dogs[1],
       &dogs[2],
       &dogs[3],
       &dogs[4],
    };

    for (const auto& animal : animals)
        animal->Speak();

    return 0;
}