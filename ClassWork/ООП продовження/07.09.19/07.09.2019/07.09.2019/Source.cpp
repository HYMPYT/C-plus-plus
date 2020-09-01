#include<iostream>
using namespace std;
class A
{
	int a;
public:
	A(int val)
	{
		a = val;
	}
	int getA()const
	{
		return a;
	}
	void setA(int val)
	{
		a = val;
	}
	virtual void doSomething()
	{
		cout << "Doing something in class A" << endl;
	}
	virtual ~A() = default;
};

class B
{
public:
	virtual void doSomethingElse()
	{
		cout << "Doing something else in class B" << endl;
	}
	virtual ~B() = default;
};

class C :public A, public B
{
public:
	C(int val) :A(val), B() {}
	void doSomething()override
	{
		cout << "Doing something in class C" << endl;
	}
	void doSomethingElse()override
	{
		cout << "Doing something else in class C" << endl;
	}
};
int main()
{
	A *pt = new C(123);
	pt->doSomething();
	B *ptr = new C(1234);
	ptr->doSomethingElse();
	delete pt;
	delete ptr;
	system("pause");
}