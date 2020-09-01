/*
#include <iostream>
using namespace std;

class Base
{
    void x()
    {
        cout << "x  ";
    }
    void c()
    {
        cout << "c  ";
    }
    void e()
    {
        cout << "e  ";
    }
    // 2. Steps requiring peculiar implementations are "placeholders" in base class
    virtual void ph1() = 0;
    virtual void ph2() = 0;
public:
    // 1. Standardize the skeleton of an algorithm in x base class "template method"
    void execute()
    {
        x();
        ph1();
        c();
        ph2();
        e();
    }
};

class One: public Base
{
    // 3. Derived classes implement placeholder methods
    void ph1()override
    {
        cout << "y  ";
    }
    void ph2()override
    {
        cout << "d  ";
    }
};

class Two: public Base
{
    void ph1()override
    {
        cout << "2  ";
    }
    void ph2()override
    {
        cout << "4  ";
    }
};

int main()
{
    Base *array[] = {new One(), new Two()};
    for (int i = 0; i < 2; i++)
    {
        array[i]->execute();
        cout << '\n';
    }
    for (int i = 0; i < 2; ++i)
    {
        delete array[i];
    }
}*/
