/*
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Base
{
    Base *right; // 1. "right" pointer in the base class
public:
    Base()
    {
        right = 0;
    }
    void setNext(Base *n)
    {
        right = n;
    }
    void add(Base *n)
    {
        if (right)
            right->add(n);
        else
            right = n;
    }
    // 2. The "chain" method in the base class always delegates to the right obj
    virtual void handle(int i)
    {
        right->handle(i);
    }
};

class Handler1: public Base
{
public:
    void handle(int i)override
    {
        if (rand() % 3)
        {
            // 3. Don't handle requests 3 times out of 4
            cout << "H1 passed " << i << "  ";
            Base::handle(i); // 3. Delegate to the base class
        }
        else
            cout << "H1 handled " << i << "  ";
    }
};

class Handler2: public Base
{
public:
    void handle(int i)override
    {
        if (rand() % 3)
        {
            cout << "H2 passed " << i << "  ";
            Base::handle(i);
        }
        else
            cout << "H2 handled " << i << "  ";
    }
};

class Handler3: public Base
{
public:
    void handle(int i)override
    {
        if (rand() % 3)
        {
            cout << "H3 passed " << i << "  ";
            Base::handle(i);
        }
        else
            cout << "H3 handled " << i << "  ";
    }
};

int main()
{
    srand(time(0));
    Handler1 root;
    Handler2 two;
    Handler3 thr;
    root.add(&two);
    root.add(&thr);
    thr.setNext(&root);
    for (int i = 1; i < 10; i++)
    {
        root.handle(i);
        cout << '\n';
    }
}*/
